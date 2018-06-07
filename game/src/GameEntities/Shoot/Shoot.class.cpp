#include <iostream>
#include "Shoot.class.hpp"
#include "../Position.class.hpp"
#include "../../Engine/Engine.class.hpp"
#include "../../Utils/Utils.class.hpp"

const std::string Shoot::DISPLAY = Utils::generateSingleStringFrommanyStrings(1, "*");

Shoot::Shoot( void ) {
}

/**
* @params {
*   id: int // Used to identify from who is the shoot
*   initialPosition: {Position} // The initial postion
*   targetPosition: {Position} // The target postion
* }
*/
Shoot::Shoot( int id, Position initialPosition, Position targetPosition ) : id(id), initialPosition(initialPosition), targetPosition(targetPosition), currentPosition(initialPosition) {
      this->shootzone = Shoot::DISPLAY;
}

Shoot::~Shoot( void ) {
}

void Shoot::move( void ) {
}

void Shoot::move(const Position & p) {
 this->currentPosition = p;
}

void Shoot::move(int x, int y) {
  this->currentPosition = Position ( x, y );
}

void Shoot::update( void ) {
  // The bullet goes in top incremented in one case
  this->currentPosition.setYdown();

  // If the shoot is outside the screen, destroy it
  if (Engine::isPositionOutOfRange(this->currentPosition)) {
    Engine::getInstance().destroyShoot();

    return;
  }

  AEntity *enemiesList = Engine::getInstance().getEnemyList();

  // Check if it collapses an entity
  for (int i = 0; i < Engine::getInstance().getEnemyListLength(); i++) {

    if (AEntity::collapse(*this, enemiesList[i])) {
      enemiesList[i].move(rand() % System::BOARD_MAX_POSTION, rand() % 10 - 15);

      // Delete the bullet
      Engine::getInstance().destroyShoot();

      // Up the score
      Engine::getInstance().upScore();

      return;
    }
  }
}

const Position & Shoot::getPosition( void ) const {
  return this->currentPosition;
}
