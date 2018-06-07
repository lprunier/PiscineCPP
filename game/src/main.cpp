#include <iostream>
#include "System.class.hpp"
#include "Utils/Utils.class.hpp"
#include "GameEntities/Enemy/Enemy.class.hpp"

int main() {
  // Initialization of rand
  srand(time(NULL));

  // Initialisation ncurses et recup de la taille de l'ecran
  initscr();

  getmaxyx(stdscr, System::HEIGHT, System::WIDTH);

  // Initialise window reference
  System::WIN = newwin(System::HEIGHT, System::WIDTH, 0, 0);

  // Boot the game
  return System().boot();
}
