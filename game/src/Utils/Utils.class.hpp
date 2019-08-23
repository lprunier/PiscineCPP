#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <chrono>

// Local includes
#include "../GameEntities/Position.class.hpp"

/**
*         THIS IS A TATIC CLASS USED ONLY TO STORE SOME UTILS FUNCTIONS
*/

typedef std::chrono::time_point<std::chrono::system_clock> t_time_point;

class Utils {

private:

public:
  Utils( void );
  Utils ( Utils const &obj );
  Utils & operator=(const Utils & rhs);
  ~Utils( void );

  static Position generateRandomPosition( void );
  static int generateRandomInt( void );
  static int generateRandomUnsignedInt( void );
  static t_time_point getTimeNow( void );
  static std::string generateSingleStringFrommanyStrings(int n...);
};

#endif
