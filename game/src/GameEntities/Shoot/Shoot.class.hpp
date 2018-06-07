#ifndef SHOOT_H
#define SHOOT_H

#include <string>

// Local includes
#include "../AEntity.class.hpp"
#include "../Shootzone.class.hpp"

/**
* This object identifys a shoot instance
*/
class Shoot : public AEntity {

private:
  /**
  * This is the structur that is used to
  * know the position of the Shoot in the space
  */

  // Used to identify from zho is the shoot
  int id;

  Position initialPosition;
  Position targetPosition;
  Position currentPosition;

public:
  Shoot( void );
  Shoot ( Shoot const &obj );
  Shoot( int id, Position initialPosition, Position targetPosition );
  ~Shoot( void );
  Shoot & operator=(const Shoot & rhs);

  /**
  * These constants are used to identify from who is the shoot
  */
  static const int ENEMY_SHOOT = 1;
  static const int PLAYER_SHOOT = 2;

  static const std::string DISPLAY;

  // This function moves the Shoot to the position
  void move( void );
  void move(int x, int y);
  void move(const Position &);

  void update( void );

  const Position & getPosition( void ) const;

  void tracerSegment(int x1, int y1, int x2, int y2);
};

#endif
