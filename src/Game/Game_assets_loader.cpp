/*
** EPITECH PROJECT, 2022
** indie
** File description:
** game
*/

#include "Game.hpp"
#include <filesystem>
#include <fstream>

void Indie::Game::load_all_assets(int firstSkinIndex, int secondSkinIndex) {
  std::string tmp = myPath;
  tmp = tmp + "map.txt";
  std::ifstream fd(tmp);
  std::string line;
  while (getline(fd, line)) {
    myMap.push_back(line);
  }

  tmp = myPath + "left_corner.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "up_wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "right_corner.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "brake_wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "down_wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "left_wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "right_wall.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "ground.png";
  allGamePath.push_back(tmp);
  tmp = myPath + "background_map.png";
  allGamePath.push_back(tmp);
  allGamePath.push_back("utils/assets/pg.png");
  allGamePath.push_back("utils/assets/bomb.png");
  allGamePath.push_back("utils/assets/fire_bonus.png");
  allGamePath.push_back("utils/assets/bomb_bonus.png");
  allGamePath.push_back("utils/assets/speed_bonus.png");
  allGamePath.push_back("utils/assets/death_bonus.png");
  allGamePath.push_back("utils/assets/health_bonus.png");
  allGamePath.push_back("utils/assets/tombstone.png");
  // creep assets
  allGamePath.push_back("utils/Creep/Red_Creep_Back_0.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Back_1.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Back_2.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Back_3.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Back_4.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Back_5.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_0.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_1.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_2.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_3.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_4.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Front_5.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_0.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_1.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_2.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_3.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_4.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Right_5.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_0.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_1.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_2.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_3.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_4.png");
  allGamePath.push_back("utils/Creep/Red_Creep_Left_5.png");
  // bomber 1
  tmp = "utils/Bomberman/";
  if (firstSkinIndex == Indie::RED_COLOR)
    tmp = tmp + "Red/Bman_";
  else if (firstSkinIndex == Indie::YELLOW_COLOR)
    tmp = tmp + "Yellow/Bman_";
  else if (firstSkinIndex == Indie::BLUE_COLOR)
    tmp = tmp + "Blue/Bman_";
  else if (firstSkinIndex == Indie::WHITE_COLOR)
    tmp = tmp + "White/Bman_";
  allGamePath.push_back(tmp + "Back_0.png");
  allGamePath.push_back(tmp + "Back_1.png");
  allGamePath.push_back(tmp + "Back_2.png");
  allGamePath.push_back(tmp + "Back_3.png");
  allGamePath.push_back(tmp + "Back_4.png");
  allGamePath.push_back(tmp + "Back_5.png");
  allGamePath.push_back(tmp + "Front_0.png");
  allGamePath.push_back(tmp + "Front_1.png");
  allGamePath.push_back(tmp + "Front_2.png");
  allGamePath.push_back(tmp + "Front_3.png");
  allGamePath.push_back(tmp + "Front_4.png");
  allGamePath.push_back(tmp + "Front_5.png");
  allGamePath.push_back(tmp + "Right_0.png");
  allGamePath.push_back(tmp + "Right_1.png");
  allGamePath.push_back(tmp + "Right_2.png");
  allGamePath.push_back(tmp + "Right_3.png");
  allGamePath.push_back(tmp + "Right_4.png");
  allGamePath.push_back(tmp + "Right_5.png");
  allGamePath.push_back(tmp + "Left_0.png");
  allGamePath.push_back(tmp + "Left_1.png");
  allGamePath.push_back(tmp + "Left_2.png");
  allGamePath.push_back(tmp + "Left_3.png");
  allGamePath.push_back(tmp + "Left_4.png");
  allGamePath.push_back(tmp + "Left_5.png");
  // bomber 2
  tmp = "utils/Bomberman/";
  if (secondSkinIndex == Indie::RED_COLOR)
    tmp = tmp + "Red/Bman_";
  else if (secondSkinIndex == Indie::YELLOW_COLOR)
    tmp = tmp + "Yellow/Bman_";
  else if (secondSkinIndex == Indie::BLUE_COLOR)
    tmp = tmp + "Blue/Bman_";
  else if (secondSkinIndex == Indie::WHITE_COLOR)
    tmp = tmp + "White/Bman_";
  allGamePath.push_back(tmp + "Back_0.png");
  allGamePath.push_back(tmp + "Back_1.png");
  allGamePath.push_back(tmp + "Back_2.png");
  allGamePath.push_back(tmp + "Back_3.png");
  allGamePath.push_back(tmp + "Back_4.png");
  allGamePath.push_back(tmp + "Back_5.png");
  allGamePath.push_back(tmp + "Front_0.png");
  allGamePath.push_back(tmp + "Front_1.png");
  allGamePath.push_back(tmp + "Front_2.png");
  allGamePath.push_back(tmp + "Front_3.png");
  allGamePath.push_back(tmp + "Front_4.png");
  allGamePath.push_back(tmp + "Front_5.png");
  allGamePath.push_back(tmp + "Right_0.png");
  allGamePath.push_back(tmp + "Right_1.png");
  allGamePath.push_back(tmp + "Right_2.png");
  allGamePath.push_back(tmp + "Right_3.png");
  allGamePath.push_back(tmp + "Right_4.png");
  allGamePath.push_back(tmp + "Right_5.png");
  allGamePath.push_back(tmp + "Left_0.png");
  allGamePath.push_back(tmp + "Left_1.png");
  allGamePath.push_back(tmp + "Left_2.png");
  allGamePath.push_back(tmp + "Left_3.png");
  allGamePath.push_back(tmp + "Left_4.png");
  allGamePath.push_back(tmp + "Left_5.png");
}
