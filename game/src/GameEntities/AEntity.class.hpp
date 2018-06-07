#ifndef AENTITY_H
#define AENTITY_H

#include <string>

// Local includes
#include "Position.class.hpp"
#include "Shootzone.class.hpp"
#include "../System.class.hpp"


/**
* This class represents every identifiable entity of ht e game, like the Player, enemies, object, etc
*/
class AEntity {

private:
  AEntity ( const AEntity & obj );

protected:
  /**
  * This is the structur that is used to
  * know the position of the AEntity in the space
  */
  Position position;

  Shootzone shootzone;

public:
  AEntity( void );
  virtual ~AEntity( void );

  // This function moves the AEntity to the posiiton
  void move(int x, int y);
  void move(const Position &);
  void setShootzone(int width, int height);
  void setShootzone(std::string const str);
  void setShootzone(const Shootzone &);

  void display( void );

  // This method is mandatory for every AEntitys
  // It needs
  virtual void update( void ) = 0;

  virtual const Position & getPosition( void ) const;
  const Shootzone & getShootzone( void ) const;


  static bool collapse( const AEntity & s1, const AEntity & s2 );
};

#endif
