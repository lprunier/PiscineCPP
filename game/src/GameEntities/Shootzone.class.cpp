#include <iostream>
#include "Shootzone.class.hpp"

Shootzone::Shootzone( void ) : width(0) , height(0) {
}

Shootzone::Shootzone( int width, int height ) : width(width) , height(height), howIlook(" ints ") {
}

Shootzone::Shootzone( std::string const str ) {
  int len = strlen(str.c_str());

  this->height = 0;
  this->width = 0;

  for(int i = 0; i < len; i++) {
    if (str[i] == '\n')
      this->height++;

    if (this->height == 0)
      this->width++;
  }

  this->howIlook = str;
}

Shootzone::Shootzone ( Shootzone const &obj ) : width(obj.getwidth()), height(obj.getheight()), howIlook(obj.gethowIlook()) {
}

Shootzone & Shootzone::operator=(const Shootzone & rhs) {
  this->width = rhs.getwidth();
  this->height = rhs.getheight();
  this->howIlook = rhs.gethowIlook();

  return *this;
}

Shootzone::~Shootzone( void ) {
}

int Shootzone::getwidth( void ) const {
  return this->width;
}

int Shootzone::getheight( void ) const {
  return this->height;
}

const std::string & Shootzone::gethowIlook( void ) const {
  return this->howIlook;
}

std::ostream	&operator<<(std::ostream &o, Shootzone const &rhs) {
	o << rhs.getwidth() << " " << rhs.getheight() << " " << rhs.gethowIlook() << std::endl;

	return (o);
}
