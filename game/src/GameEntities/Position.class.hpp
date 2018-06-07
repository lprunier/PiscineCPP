#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {

private:
    int x;
    int y;

public:
  Position( void );
  Position( Position const &obj );
  Position( int x, int y );
  ~Position( void );

  Position & operator=(const Position & rhs);
  Position & operator%(int rhs);

  int   getX( void ) const;
  int   getY( void ) const;
  void  setXup( void );
  void  setXdown( void );
  void  setYup( void );
  void  setYdown( void );

  // This function compares two Position
  static bool cmp(const Position &, const Position &);
};

std::ostream	&operator<<(std::ostream &o, Position const & rhs);

#endif
