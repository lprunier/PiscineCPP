#include <iostream>

// Local includes
#include "Enemy.class.hpp"
#include "../Position.class.hpp"
#include "../../System.class.hpp"
#include "../../Utils/Utils.class.hpp"
#include "../../Engine/Engine.class.hpp"

const std::string Enemy::DISPLAY[Enemy::NUMBER_OF_DIFFERENT_STATIC_OBJECT] = {
  Utils::generateSingleStringFrommanyStrings(5,
    "    _....._        ",
    " .'        `'-../  ",
    "( Z E P P L I N -><",
    " '._     _,.-'''\\ ",
    "    `````          "),

  Utils::generateSingleStringFrommanyStrings(5,
    "       _.-;;-._ ",
    "'-..-'|   ||   |",
    "'-..-'|_.-;;-._|",
    "'-..-'|   ||   |",
    "'-..-'|_.-''-._|"),
};

const std::string Enemy::getRandomDisplay( void ) {
  return Enemy::DISPLAY[Utils::generateRandomUnsignedInt() % Enemy::NUMBER_OF_DIFFERENT_STATIC_OBJECT];
}

/**
* Default constructor of the Enemy object
* When an Enemy object is instaciated by default
* set its position to a random one
*/
Enemy::Enemy( void ) {
  // Set random position
  this->position = Utils::generateRandomPosition();

  this->shootzone = Shootzone(Enemy::getRandomDisplay());
}

Enemy::Enemy( const Position & p )  {
  this->position = p;

  this->shootzone = Shootzone(Enemy::getRandomDisplay());
}

Enemy::Enemy( int x, int y )  {
  this->position = Position(x, y);

  this->shootzone = Shootzone(Enemy::getRandomDisplay());
}

Enemy::~Enemy( void ) {
}

Enemy & Enemy::operator=(const Enemy & rhs) {
  this->position = rhs.getPosition();

  this->shootzone = getShootzone();

  return *this;
}


/**
* This function shoots at a position from
* the AEntity position
*/
void Enemy::shoot(int x, int y) const {
  Engine::getInstance().newShoot(
    // Tells that it is a shoot from the player
      Shoot::ENEMY_SHOOT,

      // The position of the player is the initial position of the bullet
      this->position,

      // The position of the target
      Position(x, y));
}

void Enemy::shoot(const Position & p) const {
  Engine::getInstance().newShoot(
    // Tells that it is a shoot from the player
      Shoot::ENEMY_SHOOT,

      // The position of the player is the initial position of the bullet
      this->position,

      // The position of the target
      p);
}

void Enemy::update( void ) {
  this->position.setYup();
  this->position.setYup();
}
