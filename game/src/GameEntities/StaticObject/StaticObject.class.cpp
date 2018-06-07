#include <iostream>
#include "StaticObject.class.hpp"
#include "../../Utils/Utils.class.hpp"
#include "../Position.class.hpp"


const std::string StaticObject::DISPLAY[StaticObject::NUMBER_OF_DIFFERENT_STATIC_OBJECT] = {
  Utils::generateSingleStringFrommanyStrings(5,
    "    (_)     ",
    "  <--|-->   ",
    " _   |   _  ",
    "`\\__/ \\__/`",
    "  `-. .-'   "),

  Utils::generateSingleStringFrommanyStrings(6,
    "     __     ",
    "   _|==|_   ",
    "    ('')___/" ,
    ">--(`^^')   ",
    "  (`^'^'`)  ",
    "  `======'  "),
};

const std::string StaticObject::getRandomDisplay( void ) {
  return StaticObject::DISPLAY[Utils::generateRandomUnsignedInt() % StaticObject::NUMBER_OF_DIFFERENT_STATIC_OBJECT];
}

/**
* Default constructor of the StaticObject object
* When an StaticObject object is instaciated by default
* set its position to a random one
*/
StaticObject::StaticObject( void )  {
  // Set random position
  this->position = Utils::generateRandomPosition();

  this->shootzone = StaticObject::getRandomDisplay();
}

StaticObject::StaticObject( const StaticObject & obj ) {
  this->position = obj.getPosition();
  this->shootzone = obj.getShootzone();
}

StaticObject::~StaticObject( void ) {
}

void StaticObject::update( void ) {
}

std::ostream	&operator<<(std::ostream &o, StaticObject const rhs) {
	o << rhs.getShootzone() << std::endl;

	return (o);
}
