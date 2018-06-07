#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Local includes
#include "../AEntity.class.hpp"
#include "../Shoot/Shoot.class.hpp"
#include "../Shootzone.class.hpp"

/**
* This classe describe a Player in the Engine
*/
class Player : public AEntity {

private:

public:
  Player( void );
  Player ( Player const &obj );
  Player & operator=(const Player & rhs);
  ~Player( void );

  static const std::string DISPLAY;

  /**
  * This function shoots at a position from
  * the AEntity position
  */
  void shoot(void) const;
  void shoot(int x, int y) const;
  void shoot(const Position & p) const;

  void update( void );
};

#endif
