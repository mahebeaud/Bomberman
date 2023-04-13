/*
** EPITECH PROJECT, 2022
** inie
** File description:
** bonus
*/

#include "Game.hpp"

void Indie::Game::create_bonus(Vector2 bombPos) {
  int rd = GetRandomValue(0, 7);
  if (rd <= 4)
    allBonus.push_back({(int)bombPos.x, (int)bombPos.y, (int)GetTime(), rd, 0});
}

void Indie::Game::check_bonus_disapear(int i) {
  if (GetTime() - allBonus.at(i)[2] >= 7 + allBonus.at(i)[4])
    allBonus.erase(allBonus.begin() + i);
}

void Indie::Game::draw_bonus(std::vector<Texture2D> allGameTexture, int i) {
  if (allBonus.at(i)[3] == 0)
    DrawTexture(allGameTexture.at(Indie::Game::FIRE), allBonus.at(i)[0],
                allBonus.at(i)[1], WHITE);
  else if (allBonus.at(i)[3] == 1)
    DrawTexture(allGameTexture.at(Indie::Game::NEWBOMB), allBonus.at(i)[0],
                allBonus.at(i)[1], WHITE);
  else if (allBonus.at(i)[3] == 2)
    DrawTexture(allGameTexture.at(Indie::Game::SPEED), allBonus.at(i)[0],
                allBonus.at(i)[1], WHITE);
  else if (allBonus.at(i)[3] == 3)
    DrawTexture(allGameTexture.at(Indie::Game::HEALTH), allBonus.at(i)[0],
                allBonus.at(i)[1], WHITE);
  else if (allBonus.at(i)[3] == 4)
    DrawTexture(allGameTexture.at(Indie::Game::DEATH), allBonus.at(i)[0],
                allBonus.at(i)[1], WHITE);
}

void Indie::Game::manage_bonus(std::vector<Texture2D> allGameTexture,
                               Player *myPlayer) {
  int dl;

  for (int i = 0; i < allBonus.size(); i = i + 1) {
    dl = 0;
    draw_bonus(allGameTexture, i);
    if (CheckCollisionRecs(myPlayer->playerPos,
                           {(float)allBonus.at(i)[0], (float)allBonus.at(i)[1],
                            (float)40, (float)40})) {
      allSounds.at(Indie::Game::BONUS_SND)->play_sound();
      if (allBonus.at(i)[3] == 0)
        myPlayer->fire = myPlayer->fire + 1;
      else if (allBonus.at(i)[3] == 1)
        myPlayer->bombStock = myPlayer->bombStock + 1;
      else if (allBonus.at(i)[3] == 2)
        myPlayer->speed = myPlayer->speed + 0.3;
      else if (allBonus.at(i)[3] == 3)
        myPlayer->life = myPlayer->life + 1;
      else if (allBonus.at(i)[3] == 4)
        myPlayer->speed = myPlayer->speed - 0.3;
      allBonus.erase(allBonus.begin() + i);
      dl = 1;
    }
    if (dl == 0)
      check_bonus_disapear(i);
  }
}
