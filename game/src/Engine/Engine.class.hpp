#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <chrono>
#include <ctime>

// Local includes
#include "Engine.class.hpp"
#include "../System.class.hpp"
#include "../GameEntities/AEntity.class.hpp"
#include "../GameEntities/Shoot/Shoot.class.hpp"
#include "../GameEntities/Player/Player.class.hpp"
#include "../GameEntities/Enemy/Enemy.class.hpp"

typedef std::chrono::time_point<std::chrono::system_clock> t_time_point;

class Engine {

private:
  Engine ( Engine const &obj );
  Engine & operator=(const Engine & rhs);

  static const int FRAMES_PER_SECOND = 25;
  static const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;
  static const int MAXIMUM_LIVES = 8;

  // Time when the engine started to run
  t_time_point startTime;

  // Score
  int score;

  bool gameOn;

  // Number of lives
  int lives;


  // Here are stored all Enemies object of the Engine
  Enemy *enemiesList;
  int enemiesListLength;

  // Here are stored all shoots in the engine
  Shoot *shootList;

  Player player;

public:
  Engine( void );
  ~Engine( void );

  static Engine * instance;

  // The string displayed when game over
  static const std::string GAME_OVER_DISPLAY;

  // getTickCount() returns the current number of milliseconds
  // that have elapsed since the system was starte
  int getTickCount( void ) const;

  static void destroyInstance( void );
  void newShoot( int type , Position from, Position to );

  int start( void );

  const t_time_point & getTime( void ) const;
  const Player & getPlayer( void ) const;
  Enemy * getEnemyList( void ) const;
  void destroyShoot( void );
  void upScore( void );
  int getEnemyListLength( void ) const;
  static Engine & getInstance( void );

  int treateInput(int input);
  void refresh( void );
  void updateEnemies( int *timetomove );
  static bool isPositionOutOfRange(const Position &);
  static int endGame( void );

};

#endif
