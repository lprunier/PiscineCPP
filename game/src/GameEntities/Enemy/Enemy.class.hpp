#ifndef ENEMY_H
#define ENEMY_H

#include <string>

// Local includes
#include "../AEntity.class.hpp"
#include "../Shootzone.class.hpp"

class Enemy : public AEntity {

private:

public:
  Enemy( void );
  Enemy( Enemy const &obj );
  Enemy( const Position & p );
  Enemy( int x, int y );
  Enemy & operator=(const Enemy & rhs);
  ~Enemy( void );

  static const int NUMBER_OF_DIFFERENT_STATIC_OBJECT = 3;
  static const std::string DISPLAY[Enemy::NUMBER_OF_DIFFERENT_STATIC_OBJECT];
  // static const int TIME;

  /**
  * This function returns a random string from the Enemy::DISPLAY pool
  */
  static const std::string getRandomDisplay( void );

  /**
  * This function shoots at a position from
  * the AEntity position
  */
  void shoot(int x, int y) const;

  void shoot(const Position & p) const;

  void update( void );


};

#endif
