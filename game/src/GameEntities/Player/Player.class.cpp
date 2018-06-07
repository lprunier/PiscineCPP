#include <iostream>

// Local includes
#include "Player.class.hpp"
#include "../Position.class.hpp"
#include "../../Engine/Engine.class.hpp"
#include "../../Utils/Utils.class.hpp"

const std::string Player::DISPLAY = Utils::generateSingleStringFrommanyStrings(3,
    "  /|\\ ",
    " / | \\",
    "/ ||| \\");


Player::Player( void ) {
    this->shootzone = Player::DISPLAY;
}

Player::~Player( void ) {
}

/**
* This function shoots at a position from
* the AEntity position
*/
void Player::shoot(int x, int y) const {
  Engine::getInstance().newShoot(
    // Tells that it is a shoot from the player
      Shoot::PLAYER_SHOOT,

      // The position of the player is the initial position of the bullet
      this->position,

      // The position of the target
      Position(x, y));
}

void Player::shoot( void ) const {
  Engine::getInstance().newShoot(
    // Tells that it is a shoot from the player
      Shoot::PLAYER_SHOOT,

      // The position of the player is the initial position of the bullet
      this->position,

      // The position of the target
      Position());
}

void Player::shoot(const Position & p) const {
  // Compute the new from position
  // Height : Position of the player in Y + 1
  // Width : Position of the player in X + (WIDTH / 2)
  // When the height is not d
  Position from = Position(p.getX() + this->getShootzone().getwidth() / 2, p.getY() - 1);;

  Position to = Position(from.getX(), 0);

  Engine::getInstance().newShoot(
    // Tells that it is a shoot from the player
      Shoot::PLAYER_SHOOT,

      // The position of the player is the initial position of the bullet
      from,

      // The position of the target
      p);
}

void Player::update( void ) {
}
