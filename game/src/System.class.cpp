#include <iostream>
#include "System.class.hpp"
#include "Engine/Engine.class.hpp"
#include "GameEntities/Player/Player.class.hpp"
#include "GameEntities/Position.class.hpp"
#include "GameEntities/Enemy/Enemy.class.hpp"

WINDOW *System::WIN = NULL;
int System::WIDTH = 0;
int System::HEIGHT = 0;

System::System( void ) {
}

System::~System( void ) {
  // Rend la main aux termcaps du terminal
  endwin();
}

int System::boot() {
  cbreak();

  noecho();

  nodelay(stdscr, TRUE);

  // utlisation du keyboard possible
  keypad(System::WIN, TRUE);

  // curseur efface
  curs_set(0);

  wborder(System::WIN, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

  wrefresh(System::WIN);

  Engine::getInstance().start();

  Engine::destroyInstance();

  return 1;
}
