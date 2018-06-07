#ifndef SHOOTZONE_H
#define SHOOTZONE_H

#include <iostream>
#include <string>

class Shootzone {

private:
    int width;
    int height;
    std::string howIlook;

public:
  Shootzone( void );
  Shootzone ( Shootzone const &obj );
  Shootzone ( int width, int height );
  Shootzone ( std::string const str );
  Shootzone & operator=(const Shootzone & rhs);
  ~Shootzone( void );

  int getwidth( void ) const;
  int getheight( void ) const;
  const std::string & gethowIlook( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Shootzone const &rhs);

#endif
