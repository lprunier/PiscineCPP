#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <ncurses.h>

class System {

private:

public:
  System( void );
  System ( System const &obj );
  System & operator=(const System & rhs);
  ~System( void );

  static const int SYSTEM_KEY_UP = 65;
  static const int SYSTEM_KEY_DOWN = 66;
  static const int SYSTEM_KEY_LEFT = 68;
  static const int SYSTEM_KEY_RIGHT = 67;
  static const int SYSTEM_KEY_BACKSPACE = 32;
  static const int SYSTEM_KEY_CTRL_D = 4;

  static int WIDTH;
  static int HEIGHT;
  // This value is used to determine the max size of the board
  static const int BOARD_MAX_POSTION = 500;
  static const int NB_ENEMIES = 50;
  static const int H_MAX = 83;
  static const int NB_SHOOTS_ALLOWED = 300;

  static WINDOW * WIN;

  int boot( void );
};

#endif
