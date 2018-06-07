#include <iostream>
#include <cstdlib> // For rand
#include <chrono>
#include <ctime>

// Local includes
#include "Utils.class.hpp"
#include "../System.class.hpp"
#include "../GameEntities/Position.class.hpp"

/**
* This function generates a random Position object
*/
Position Utils::generateRandomPosition( void ) {
  return Position(
    // x
    Utils::generateRandomInt() % System::BOARD_MAX_POSTION,

    // y
    // 10 to pop at the top
    Utils::generateRandomInt() % 10
  );
}

/**
* This function generates a random int
*/
int Utils::generateRandomInt( void ) {
    int n = rand();
    int isNegative = n % 2;

    if (isNegative) return -n;

    return n;
}

/**
* This function generates a random int
*/
int Utils::generateRandomUnsignedInt( void ) {
    return rand();
}

 t_time_point Utils::getTimeNow() {
   return std::chrono::system_clock::now();
 }

 /**
 *  Appends all strings passed as argument
 *  to create one single string
 */
 std::string Utils::generateSingleStringFrommanyStrings(int n...) {
    va_list args;
    va_start(args, n);

    std::string ret;

    for (int i = 0; i < n; i++) {
      ret.append(std::string(va_arg(args, char *)));
      ret.append("\n");
    }

    va_end(args);

    return ret;
}
