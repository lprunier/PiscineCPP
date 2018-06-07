#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <string>

// Local includes
#include "../AEntity.class.hpp"

class StaticObject : public AEntity {

private:

public:
  StaticObject( void );
  StaticObject( StaticObject const &obj );
  StaticObject( const Position & p );
  StaticObject & operator=(const StaticObject & rhs);
  ~StaticObject( void );

  static const int NUMBER_OF_DIFFERENT_STATIC_OBJECT = 2;
  static const std::string DISPLAY[NUMBER_OF_DIFFERENT_STATIC_OBJECT];

  /**
  * This function returns a random string from the StaticObject::DISPLAY pool
  */
  static const std::string getRandomDisplay( void );

  void update( void );
};

std::ostream &operator<<(std::ostream &o, StaticObject const rhs);

#endif
