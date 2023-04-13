/*
** EPITECH PROJECT, 2022
** indie
** File description:
** ia
*/

#include "Game.hpp"
#include "Player.hpp"

int Indie::Player::control_second_bot(
    std::vector<std::vector<Rectangle>> collisions) {
  Vector2 lastPos = {playerPos.x, playerPos.y};

  if (life <= 0)
    return (0);
  if (script_bot_2 == 0) {
    if (move == Indie::Player::TOP) {
      playerPos.y = playerPos.y - speed;
    } else if (move == Indie::Player::BOT) {
      playerPos.y = playerPos.y + speed;
    } else if (move == Indie::Player::RIGHT && bombPosed == 0) {
      playerPos.x = playerPos.x + speed;
    } else if (move == Indie::Player::LEFT) {
      playerPos.x = playerPos.x - speed;
    }
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP) {
        move = Indie::Player::BOT;
        if (myId == 4 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::BOT) {
        move = Indie::Player::LEFT;
      } else if (move == Indie::Player::LEFT) {
        move = Indie::Player::RIGHT;
      } else
        move = Indie::Player::TOP;
    }
    if (playerPos.x > 1430 && playerPos.x < 1440 && playerPos.y > 110 &&
        playerPos.y < 120)
      script_bot_2 = script_bot_2 + 1;
  } else if (script_bot_2 == 1) {
    if (move == Indie::Player::BOT && bombPosed == 0)
      move = Indie::Player::TOP;
    if (move == Indie::Player::TOP && bombPosed == 0) {
      playerPos.y = playerPos.y - speed;
    } else if (move == Indie::Player::BOT && playerPos.y < 170) {
      playerPos.y = playerPos.y + speed;
    } else if (move == Indie::Player::RIGHT) {
      playerPos.x = playerPos.x + speed;
    } else if (move == Indie::Player::LEFT) {
      playerPos.x = playerPos.x - speed;
    }
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::LEFT) {
        move = Indie::Player::RIGHT;
        if (myId == 4 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::TOP) {
        move = Indie::Player::LEFT;
      } else if (move == Indie::Player::RIGHT) {
        move = Indie::Player::BOT;
      } else
        move = Indie::Player::TOP;
    }
    if (playerPos.x < 475)
      script_bot_2 = script_bot_2 + 1;
  } else if (script_bot_2 == 2) {
    if (move == Indie::Player::TOP) {
      playerPos.y = playerPos.y - speed;
    } else if (move == Indie::Player::BOT) {
      playerPos.y = playerPos.y + speed;
    } else if (move == Indie::Player::RIGHT) {
      playerPos.x = playerPos.x + speed;
    } else if (move == Indie::Player::LEFT && bombPosed == 0) {
      playerPos.x = playerPos.x - speed;
    }
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::BOT) {
        move = Indie::Player::TOP;
        if (myId == 4 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::TOP) {
        move = Indie::Player::RIGHT;
      } else if (move == Indie::Player::RIGHT) {
        move = Indie::Player::LEFT;
      } else
        move = Indie::Player::BOT;
    }
  }
  if (playerPos.x != lastPos.x || playerPos.y != lastPos.y) {
    anim = anim + 1;
    if (anim > 5)
      anim = 0;
  }
  return (0);
}
