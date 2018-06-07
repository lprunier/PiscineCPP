#include <iostream>
#include "Position.class.hpp"

Position::Position( void ) : x(0) , y(0) {
}

Position::Position( int x, int y ) : x(x) , y(y) {
}

Position::Position ( Position const &obj ) : x(obj.getX()), y(obj.getY()) {
}

Position & Position::operator=(const Position & rhs) {
  this->x = rhs.getX();
  this->y = rhs.getY();

  return *this;
}

Position & Position::operator%(int rhs) {
  this->x = this->x % rhs;
  this->y = this->y % rhs;

  return *this;
}

Position::~Position( void ) {
}

int Position::getX( void ) const {
  return this->x;
}

int Position::getY( void ) const {
  return this->y;
}

void  Position::setXup( void ) {
  this->x++;
}

void  Position::setXdown( void ) {
  this->x--;
}

void  Position::setYup( void ) {
  this->y++;
}

void  Position::setYdown( void ) {
  this->y--;
}

/**
* Returns true when postion are the same
*/
bool Position::cmp(const Position &p1, const Position &p2) {
  if (p1.getX() != p2.getX()) return false;
  if (p1.getY() != p2.getY()) return false;

  return true;
}

std::ostream	&operator<<(std::ostream &o, Position const & rhs) {
	o << rhs.getX() << " " << rhs.getY() << std::endl;

	return (o);
}
