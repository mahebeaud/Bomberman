/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** bombs
*/

#include "Game.hpp"
#include "Player/Player.hpp"

void Indie::Game::create_bombs(Player *myPlayer) {
  allBombPlayer.push_back(myPlayer->myId);
  allBombCount.push_back(0);
  allBombRange.push_back(myPlayer->fire);
  allBombPos.push_back({myPlayer->playerPos.x + 6, myPlayer->playerPos.y + 5});
  allBombTime.push_back(GetTime());
  allBombPause.push_back(0);
}

void Indie::Game::draw_bombs(std::vector<Texture2D> allGameTexture) {
  for (int i = 0; i < allBombPos.size(); i = i + 1)
    DrawTexture(allGameTexture.at(Indie::Game::BOMB), allBombPos.at(i).x,
                allBombPos.at(i).y, WHITE);
}

void Indie::Game::manage_bombs(std::vector<Texture2D> allGameTexture,
                               Player *myPlayer) {
  draw_bombs(allGameTexture);
  for (int i = 0; i < allBombPos.size(); i = i + 1) {
    if (GetTime() - allBombTime.at(i) >= 3 + allBombPause.at(i)) {
      check_collisions(allBombPos.at(i), myPlayer, i);
      allBombCount.at(i) = allBombCount.at(i) + 1;
      if (allBombPlayer.at(i) == myPlayer->myId && allBombCount.at(i) > 5) {
        if (myPlayer->myId == 3)
          myPlayer->script_bot_1++;
        myPlayer->bombPosed = myPlayer->bombPosed - 1;
        allSounds.at(Indie::Game::BOMB_SND)->play_sound();
        allBombPlayer.erase(allBombPlayer.begin() + i);
        allBombPos.erase(allBombPos.begin() + i);
        allBombTime.erase(allBombTime.begin() + i);
        allBombRange.erase(allBombRange.begin() + i);
        allBombPause.erase(allBombPause.begin() + i);
        allBombCount.erase(allBombCount.begin() + i);
        if (myPlayer->myId == 4) {
          if (myPlayer->move == Indie::Player::BOT)
            myPlayer->move = Indie::Player::TOP;
          else if (myPlayer->move == Indie::Player::RIGHT)
            myPlayer->move = Indie::Player::LEFT;
          else if (myPlayer->move == Indie::Player::TOP)
            myPlayer->move = Indie::Player::BOT;
        }
      }
    }
  }
}
