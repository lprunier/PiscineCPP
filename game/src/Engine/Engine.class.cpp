#include <iostream>
#include <ctime>
#include <unistd.h>


#include "Engine.class.hpp"
#include "../System.class.hpp"
#include "../GameEntities/Player/Player.class.hpp"
#include "../GameEntities/Position.class.hpp"
#include "../GameEntities/Shoot/Shoot.class.hpp"
#include "../GameEntities/Shootzone.class.hpp"
#include "../Utils/Utils.class.hpp"
#include "../GameEntities/AEntity.class.hpp"
#include "../GameEntities/StaticObject/StaticObject.class.hpp"

Engine* Engine::instance = NULL;

const std::string Engine::GAME_OVER_DISPLAY = Utils::generateSingleStringFrommanyStrings(6,
  " ________                        ________                               ",
  "/  _____/_____    _____   ____   \\_____  \\___  __ ___________         ",
  "/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\",
  "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/",
  "\\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|        ",
  "       \\/     \\/      \\/     \\/          \\/          \\/           ");

Engine::Engine( void ) :  startTime(Utils::getTimeNow()),

                          score(0),

                          gameOn(false),

                          lives(Engine::MAXIMUM_LIVES),

                          enemiesList(NULL),

                          enemiesListLength(0),

                          shootList(NULL) {
}

Engine::~Engine( void ) {
  // Delete allocated enemies
  if (this->enemiesList)
    delete [] enemiesList;

  // Delete allocated enemies
  if (this->shootList)
    delete shootList;
}

// @TODO creer une method dans player qui bouge la position due lentity
int Engine::treateInput(int input) {
  // recuperera les inputs
  Position  pos = this->player.getPosition();

  /**
  *  When it starts with \033, needs to get the second ch after
  * ex :
  * \033 XXX <input>
  */
  if (input == '\033') {
    getch();
    input = getch();
  }

  switch (input) {
      case System::SYSTEM_KEY_UP:
        pos.setYdown();
        break;
      case System::SYSTEM_KEY_DOWN:
        pos.setYup();
        break;
      case System::SYSTEM_KEY_LEFT:
        pos.setXdown();
        pos.setXdown();
        break;
      case System::SYSTEM_KEY_RIGHT:
        pos.setXup();
        pos.setXup();
        break;
      case System::SYSTEM_KEY_BACKSPACE:
        if (this->shootList == NULL)
          this->player.shoot();
        break;

      // QUIT THE GAME
      case System::SYSTEM_KEY_CTRL_D:
        this->gameOn = false;
        break;
  }

  // Block le perso si il est trop proche des bords
  while (pos.getX() < 0)
    pos.setXup();
  while (pos.getX() + this->player.getShootzone().getwidth() >= System::WIDTH)
    pos.setXdown();

  if (pos.getY() < 0)
    pos.setYup();
  if (pos.getY() + this->player.getShootzone().getheight() > System::HEIGHT)
    pos.setYdown();

  this->player.move(pos);

  return 0;
}

/**
*  Cette function re render all the display
*/
void Engine::refresh( void ) {
    // Clear all the window
    wclear(System::WIN);

    Position pos = this->player.getPosition();

    // reafficher le player
    this->player.display();

    if (this->shootList) {
      this->shootList->display();
    }

    for (int i = 0; i < System::NB_ENEMIES; i++)
      this->enemiesList[i].display();

    // Affichage du score
    wmove(System::WIN, 0, 1);
    whline(System::WIN, ACS_HLINE, 16);
    wmove(System::WIN, 1, 1);
    whline(System::WIN, ' ', 16);
    wmove(System::WIN, 2, 1);
    whline(System::WIN, ACS_HLINE, 16);

    wmove(System::WIN, 0, 0);
    whline(System::WIN, ACS_ULCORNER, 1);
    wmove(System::WIN, 1, 0);
    whline(System::WIN, ACS_VLINE, 1);
    wmove(System::WIN, 2, 0);
    whline(System::WIN, ACS_LLCORNER, 1);

    wmove(System::WIN, 0, 17);
    whline(System::WIN, ACS_URCORNER, 1);
    wmove(System::WIN, 1, 17);
    whline(System::WIN, ACS_VLINE, 1);
    wmove(System::WIN, 2, 17);
    whline(System::WIN, ACS_LRCORNER, 1);

    // Deplace le cursor a la nouvelle position
    wmove(System::WIN, 1, 3);
    std::string towrite = "Score : " + std::to_string(this->score);
    waddstr(System::WIN, towrite.c_str());

    wrefresh(System::WIN);
}

void  Engine::updateEnemies( int *timetomove ) {
  Position  pos;

  // deplacer les enemis de 1 vers le bas
  if (Engine::getTickCount() != *timetomove) {
    for (int i = 0; i < System::NB_ENEMIES; i++) {
      this->enemiesList[i].update();

      pos = this->enemiesList[i].getPosition();

      if (pos.getX() < -20)
        this->enemiesList[i].move(rand() % System::BOARD_MAX_POSTION, rand() % 10 - 15);
      if (pos.getY() > System::H_MAX)
        this->enemiesList[i].move(rand() % System::BOARD_MAX_POSTION, rand() % 10 - 15);
    }

    (*timetomove)++;
  }
}

int Engine::endGame( void ) {
  wclear(System::WIN);

  mvwprintw(System::WIN, 0, 0, Engine::GAME_OVER_DISPLAY.c_str());

  wrefresh(System::WIN);

  sleep(2);

  return 1;
}


int Engine::start() {
  // getTickCount() returns the current number of milliseconds that have elapsed since the system was started
  int next_game_tick = Engine::getTickCount();

  int input;

  int timetomove = 0;

  int sleep_time = 0;

  this->gameOn = true;

  this->player.move(System::WIDTH / 2, System::HEIGHT / 2);

  Position pos = this->player.getPosition();

  wmove(System::WIN, pos.getY(), pos.getX());

  this->player.display();

  this->enemiesList = new Enemy[System::NB_ENEMIES];
  this->enemiesListLength = System::NB_ENEMIES;

  this->enemiesList->display();

  wrefresh(System::WIN);

  //////////////////////////////////////////////////
  //                  GAME LOOP
  //////////////////////////////////////////////////
  while (this->gameOn == true) {
    input = getch();

    // Treat the input of the user
    if (input > 0) {
      this->treateInput(input);
    }


    // Check collapse with other enemies
    for (int i = 0; i < this->enemiesListLength; i++) {

      if (AEntity::collapse(this->player, enemiesList[i])) {
        return Engine::endGame();
      }
    }

    // Update l'engine

    updateEnemies(&timetomove);

    if (this->shootList) {
      this->shootList->update();
    }

    // Re render la fenetre
    this->refresh();

    next_game_tick += Engine::SKIP_TICKS;

    sleep_time = next_game_tick - Engine::getTickCount();

    if ( sleep_time >= 0 ) {
     usleep( sleep_time );
    }
  }

  return 1;

}

const t_time_point & Engine::getTime( void ) const {
  return this->startTime;
}

const Player & Engine::getPlayer( void ) const {
  return this->player;
}

void Engine::destroyShoot( void ) {
  delete this->shootList;

  this->shootList = NULL;
}

void Engine::upScore( void ) {
  this->score++;
}

// getTickCount() returns the current number of milliseconds
// that have elapsed since the engine was starte
int Engine::getTickCount( void ) const {
  return std::chrono::duration_cast<std::chrono::seconds>(Utils::getTimeNow() - this->startTime).count();
}

Engine & Engine::getInstance( void ) {
  if (!instance)   // Only allow one instance of class to be generated.
   instance = new Engine();


   return *instance;
}

void Engine::destroyInstance( void ) {
  if (!instance) return;

  delete instance;
}


Enemy * Engine::getEnemyList( void ) const {
  return this->enemiesList;
}

int Engine::getEnemyListLength( void ) const {
  return this->enemiesListLength;
}

/**
* Appends a shoot to the shootList
*/
void Engine::newShoot( int type , Position from, Position to) {
  if (this->shootList) delete this->shootList;

  this->shootList = new Shoot( type, from, to );
}

/**
* @static
* This function returns true if the postion is out of the game engine
*/
bool Engine::isPositionOutOfRange(const Position & pos) {
  if (pos.getX() < 0
      || pos.getX() >= System::WIDTH
      || pos.getY() < 0
      || pos.getY() >= System::HEIGHT) {
    return true;
  }

  return false;
}

std::ostream	&operator<<(std::ostream &o, Engine const &rhs) {
	o << std::chrono::system_clock::to_time_t(rhs.getTime()) << std::endl;

	return (o);
}
