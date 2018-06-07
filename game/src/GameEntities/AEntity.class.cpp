#include <iostream>
#include "AEntity.class.hpp"
#include "Position.class.hpp"
#include "Shootzone.class.hpp"
#include "../System.class.hpp"

AEntity::AEntity(void) {
}

AEntity::~AEntity(void) {
}

/**
* This function updates the AEntity position to a new location
* zith int as parameters
*/
void AEntity::move(int x, int y) {
  this->position = Position( x, y );
}

void AEntity::move(const Position & p) {
  this->position = Position( p );
}

void AEntity::setShootzone(int width, int height) {
  this->shootzone = Shootzone(width, height);
}

void AEntity::setShootzone(std::string const str) {
  this->shootzone = Shootzone(str);
}

void AEntity::setShootzone(const Shootzone & p) {
  this->shootzone = Shootzone( p );
}

/**
* ============= MANDATORY FUNCTION ===============
* This function handles the print of every AEntity
*/
void  AEntity::display() {
  std::string dis = this->shootzone.gethowIlook();

  Position pos = this->getPosition();

  std::string str;
  int instr = 0;
  int j;

  // Loop over the string str
  for (int i = 0; i < this->shootzone.getheight(); i++) {
    j = 0;

    while (dis[instr] != '\0' && dis[instr] != '\n') {
      str[j] = dis[instr];
      j++;
      instr++;
    }

    instr++;

    mvwprintw(System::WIN, pos.getY() + i, pos.getX(), str.c_str());
  }
}

/**
*     - Loop over e1 shoot zone
*         - For each character of e1's shootzone :
*             - If the position of the character (Position + index) matches a character of the e2's Shootzone
*                 - If one of them is a blank character : OK
*                 - Else the both are printable and there is collapse : RETURN FALSE
*             - Else : OK
*/
bool AEntity::collapse( const AEntity & e1, const AEntity & e2 ) {
  // Get positions
  const Position e1_pos = e1.getPosition();
  const Position e2_pos = e2.getPosition();


  // Get shootzone
  const Shootzone e1_shootzone = e1.getShootzone();
  const Shootzone e2_shootzone = e2.getShootzone();


  // Get shootzone
  const std::string e1_str = e1_shootzone.gethowIlook();
  const std::string e2_str = e2_shootzone.gethowIlook();

  // Initialize the line index of the e1_shootzone lines of height
  int line1 = 0;
  int x1 = 0;

  // For each character of e1's shootzone :
  for(std::string::size_type i = 0; i < e1_shootzone.gethowIlook().length(); ++i) {
    // Zhen the character is \n, skipe line and incremente the line index
    if (e1_str[i] == '\n') {
      line1++;
      x1 = 0;
      continue;
    }

    // When e1_str[i] is a blank character, skip
    if (isblank(e1_str[i])) {
      x1++;
      continue;
    }

    // Determine the position of the character in the space of e1 current character
    Position e1_p(e1_pos.getX() + x1, e1_pos.getY() + line1);

    // Initialize the line index of the e2_shootzone lines of height
    int line2 = 0;
    int x2 = 0;

    // For each character of e1's shootzone :
    for(std::string::size_type j = 0; j < e2_shootzone.gethowIlook().length(); ++j) {
      // Zhen the character is \n, skipe line and incremente the line index
      if (e2_str[j] == '\n') {
        line2++;
        x2 = 0;

        continue;
      }

      // When e1_str[i] is a blank character, skip
      if (isblank(e2_str[j])) {
        x2++;
        continue;
      }

      // Determine the position of the character in the space of e1 current character
      Position e2_p(e2_pos.getX() + x2, e2_pos.getY() + line2);

      // Compare the Position objects
      if (Position::cmp( e1_p, e2_p )) {
        return true;
      }

      x2++;
    }

    x1++;
  }

  return false;
}

const Position & AEntity::getPosition( void ) const {
  return this->position;
}

const Shootzone & AEntity::getShootzone( void ) const {
  return this->shootzone;
}
