/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** pause
*/

#include "Game.hpp"
#include <fstream>

void Indie::Game::check_pause(void) {
  if (96 == GetKeyPressed()) {
    tmpTime = GetTime();
    gameStatus = Indie::Game::PAUSE;
    ShowCursor();
    pauseTime = 120 - (GetTime() - startTime) + lostTime;
  }
}

void Indie::Game::check_play(void) {
  if (96 == GetKeyPressed()) {
    for (int i = 0; i < allBombPause.size(); i = i + 1) {
      allBombPause.at(i) = allBombPause.at(i) + (GetTime() - tmpTime);
    }
    for (int i = 0; i < allBonus.size(); i = i + 1) {
      allBonus.at(i)[4] = allBonus.at(i)[4] + (GetTime() - tmpTime);
    }
    lostTime = lostTime + (GetTime() - tmpTime);
    gameStatus = Indie::Game::GAME;
    HideCursor();
  }
}

void Indie::Game::resume_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {730, 460, 200, 50})) {
    DrawText("RESUME", 730, 460, 50, VIOLET);
    if (IsMouseButtonPressed(0)) {
      for (int i = 0; i < allBombPause.size(); i = i + 1) {
        allBombPause.at(i) = allBombPause.at(i) + (GetTime() - tmpTime);
      }
      for (int i = 0; i < allBonus.size(); i = i + 1) {
        allBonus.at(i)[4] = allBonus.at(i)[4] + (GetTime() - tmpTime);
      }
      lostTime = lostTime + (GetTime() - tmpTime);
      gameStatus = Indie::Game::GAME;
      HideCursor();
    }
  } else
    DrawText("RESUME", 730, 460, 50, WHITE);
}

void Indie::Game::settings_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {980, 460, 270, 50})) {
    DrawText("SETTINGS", 980, 460, 50, VIOLET);
    if (IsMouseButtonPressed(0))
      gameStatus = Indie::Game::SETTING;
  } else
    DrawText("SETTINGS", 980, 460, 50, WHITE);
}

void Indie::Game::save_all(void) {
  std::fstream myFd;

  myFd.open("saves/save_game.txt", std::ios_base::out);

  myFd << "windowS" << std::endl;
  myFd << windowS << std::endl << std::endl << std::endl;
  myFd << "myVolume" << std::endl;
  myFd << myVolume << std::endl << std::endl << std::endl;
  myFd << "gameStatus" << std::endl;
  myFd << gameStatus << std::endl << std::endl << std::endl;
  myFd << "startTime" << std::endl;
  myFd << startTime << std::endl << std::endl << std::endl;
  myFd << "tmpTime" << std::endl;
  myFd << tmpTime << std::endl << std::endl << std::endl;
  myFd << "lostTime" << std::endl;
  myFd << lostTime << std::endl << std::endl << std::endl;
  myFd << "pauseTime" << std::endl;
  myFd << pauseTime << std::endl << std::endl << std::endl;
  myFd << "firstName" << std::endl;
  myFd << firstName << std::endl << std::endl << std::endl;
  myFd << "secondName" << std::endl;
  myFd << secondName << std::endl << std::endl << std::endl;
  myFd << "myMap" << std::endl;
  for (int i = 0; i < myMap.size(); i = i + 1)
    myFd << myMap.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "myPath" << std::endl;
  myFd << myPath << std::endl << std::endl << std::endl;
  myFd << "allGamePath" << std::endl;
  for (int i = 0; i < allGamePath.size(); i = i + 1)
    myFd << allGamePath.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "collisions" << std::endl;
  for (int i = 0; i < collisions.size(); i = i + 1) {
    for (int ii = 0; ii < collisions.at(i).size(); ii = ii + 1) {
      myFd << collisions.at(i).at(ii).x << std::endl;
      myFd << collisions.at(i).at(ii).y << std::endl;
      myFd << collisions.at(i).at(ii).width << std::endl;
      myFd << collisions.at(i).at(ii).height << std::endl;
    }
  }
  myFd << std::endl << std::endl;
  myFd << "allBombPlayer" << std::endl;
  for (int i = 0; i < allBombPlayer.size(); i = i + 1)
    myFd << allBombPlayer.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "allBombPos" << std::endl;
  for (int i = 0; i < allBombPos.size(); i = i + 1)
    myFd << allBombPos.at(i).x << std::endl
         << allBombPos.at(i).y << std::endl
         << std::endl;
  myFd << std::endl;
  myFd << "allBombTime" << std::endl;
  for (int i = 0; i < allBombTime.size(); i = i + 1)
    myFd << allBombTime.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "allBombRange" << std::endl;
  for (int i = 0; i < allBombRange.size(); i = i + 1)
    myFd << allBombRange.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "allBombPause" << std::endl;
  for (int i = 0; i < allBombPause.size(); i = i + 1)
    myFd << allBombPause.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "allBombCount" << std::endl;
  for (int i = 0; i < allBombCount.size(); i = i + 1)
    myFd << allBombCount.at(i) << std::endl;
  myFd << std::endl << std::endl;
  myFd << "allBonus" << std::endl;
  for (int i = 0; i < allBonus.size(); i = i + 1) {
    myFd << allBonus.at(i)[0] << std::endl;
    myFd << allBonus.at(i)[1] << std::endl;
    myFd << allBonus.at(i)[2] << std::endl;
    myFd << allBonus.at(i)[3] << std::endl;
    myFd << allBonus.at(i)[4] << std::endl;
  }
  myFd << std::endl << std::endl;
  myFd.close();

  for (int i = 0; i < 4; i = i + 1) {
    myFd.open("saves/save_player_" + std::to_string(i + 1) + ".txt",
              std::ios_base::out);
    myFd << "myId" << std::endl;
    myFd << allPlayers.at(i)->myId << std::endl << std::endl << std::endl;
    myFd << "myName" << std::endl;
    myFd << allPlayers.at(i)->myName << std::endl << std::endl << std::endl;
    myFd << "playerPos" << std::endl;
    myFd << allPlayers.at(i)->playerPos.x << std::endl
         << allPlayers.at(i)->playerPos.y << std::endl;
    myFd << allPlayers.at(i)->playerPos.width << std::endl
         << allPlayers.at(i)->playerPos.height;
    myFd << std::endl << std::endl << std::endl;
    myFd << "anim" << std::endl;
    myFd << allPlayers.at(i)->anim << std::endl << std::endl << std::endl;
    myFd << "move" << std::endl;
    myFd << allPlayers.at(i)->move << std::endl << std::endl << std::endl;
    myFd << "life" << std::endl;
    myFd << allPlayers.at(i)->life << std::endl << std::endl << std::endl;
    myFd << "speed" << std::endl;
    myFd << allPlayers.at(i)->speed << std::endl << std::endl << std::endl;
    myFd << "bombStock" << std::endl;
    myFd << allPlayers.at(i)->bombStock << std::endl << std::endl << std::endl;
    myFd << "bombPosed" << std::endl;
    myFd << allPlayers.at(i)->bombPosed << std::endl << std::endl << std::endl;
    myFd << "fire" << std::endl;
    myFd << allPlayers.at(i)->fire << std::endl << std::endl << std::endl;
    myFd << "script_bot_1" << std::endl;
    myFd << allPlayers.at(i)->script_bot_1 << std::endl
         << std::endl
         << std::endl;
    myFd << "script_bot_2" << std::endl;
    myFd << allPlayers.at(i)->script_bot_2 << std::endl
         << std::endl
         << std::endl;
    myFd.close();
  }
}

void Indie::Game::save_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {770, 560, 150, 50})) {
    DrawText("SAVE", 770, 560, 50, VIOLET);
    if (IsMouseButtonPressed(0))
      save_all();
  } else
    DrawText("SAVE", 770, 560, 50, WHITE);
}

void Indie::Game::load_saves(void) {
  std::string line;

  for (int i = 0; i < 4; i = i + 1) {
    std::ifstream myFd("saves/save_player_" + std::to_string(i + 1) + ".txt");
    while (line != "myId")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->myId = std::stoi(line);
    while (line != "myName")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->myName = line;
    while (line != "playerPos")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->playerPos.x = std::stoi(line);
    getline(myFd, line);
    allPlayers.at(i)->playerPos.y = std::stoi(line);
    getline(myFd, line);
    allPlayers.at(i)->playerPos.width = std::stoi(line);
    getline(myFd, line);
    allPlayers.at(i)->playerPos.height = std::stoi(line);
    while (line != "anim")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->anim = std::stoi(line);
    while (line != "move")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->move = std::stoi(line);
    while (line != "life")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->life = std::stoi(line);
    while (line != "speed")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->speed = std::stoi(line);
    while (line != "bombStock")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->bombStock = std::stoi(line);
    while (line != "bombPosed")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->bombPosed = std::stoi(line);
    while (line != "fire")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->fire = std::stoi(line);
    while (line != "script_bot_1")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->script_bot_1 = std::stoi(line);
    while (line != "script_bot_2")
      getline(myFd, line);
    getline(myFd, line);
    allPlayers.at(i)->script_bot_2 = std::stoi(line);
    myFd.close();
  }
  std::ifstream myFd("saves/save_game.txt");
  while (line != "windowS")
    getline(myFd, line);
  getline(myFd, line);
  windowS = std::stoi(line);
  while (line != "myVolume")
    getline(myFd, line);
  getline(myFd, line);
  myVolume = std::stoi(line);
  while (line != "gameStatus")
    getline(myFd, line);
  getline(myFd, line);
  gameStatus = std::stoi(line);
  while (line != "startTime")
    getline(myFd, line);
  getline(myFd, line);
  startTime = std::stoi(line);
  while (line != "tmpTime")
    getline(myFd, line);
  getline(myFd, line);
  tmpTime = std::stoi(line);
  while (line != "lostTime")
    getline(myFd, line);
  getline(myFd, line);
  lostTime = std::stoi(line);
  while (line != "pauseTime")
    getline(myFd, line);
  getline(myFd, line);
  pauseTime = std::stoi(line);
  while (line != "firstName")
    getline(myFd, line);
  getline(myFd, line);
  firstName = line;
  while (line != "secondName")
    getline(myFd, line);
  getline(myFd, line);
  secondName = line;
  while (line != "myMap")
    getline(myFd, line);
  for (int i = 0; i < myMap.size(); i = i + 1) {
    getline(myFd, line);
    myMap.at(i) = line;
  }
  while (line != "myPath")
    getline(myFd, line);
  getline(myFd, line);
  myPath = line;
  while (line != "allGamePath")
    getline(myFd, line);
  for (int i = 0; i < allGamePath.size(); i = i + 1) {
    getline(myFd, line);
    allGamePath.at(i) = line;
  }
  while (line != "collisions")
    getline(myFd, line);
  for (int i = 0; i < collisions.size(); i = i + 1) {
    for (int ii = 0; ii < collisions.at(i).size(); ii = ii + 1) {
      getline(myFd, line);
      float a = std::stoi(line);
      collisions.at(i).at(ii).x = a;
      getline(myFd, line);
      float b = std::stoi(line);
      collisions.at(i).at(ii).y = b;
      getline(myFd, line);
      float c = std::stoi(line);
      collisions.at(i).at(ii).width = c;
      getline(myFd, line);
      float d = std::stoi(line);
      collisions.at(i).at(ii).height = d;
    }
  }
  while (line != "allBombPlayer")
    getline(myFd, line);
  allBombPlayer.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0)
      allBombPlayer.push_back(std::stoi(line));
  }
  while (line != "allBombPos")
    getline(myFd, line);
  allBombPos.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0) {
      float tmpX = std::stoi(line);
      getline(myFd, line);
      float tmpY = std::stoi(line);
      allBombPos.push_back({tmpX, tmpY});
    }
  }
  while (line != "allBombTime")
    getline(myFd, line);
  allBombTime.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0)
      allBombTime.push_back(std::stoi(line));
  }
  while (line != "allBombRange")
    getline(myFd, line);
  allBombRange.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0)
      allBombRange.push_back(std::stoi(line));
  }
  while (line != "allBombPause")
    getline(myFd, line);
  allBombPause.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0)
      allBombPause.push_back(std::stoi(line));
  }
  while (line != "allBombCount")
    getline(myFd, line);
  allBombCount.clear();
  while (line.length() != 0) {
    getline(myFd, line);
    if (line.length() != 0)
      allBombCount.push_back(std::stoi(line));
  }
  while (line != "allBonus")
    getline(myFd, line);
  allBonus.clear();
  while (line.length() != 0) {
    std::array<int, 5> currentBonus;
    getline(myFd, line);
    if (line.length() != 0) {
      currentBonus[0] = std::stoi(line);
      getline(myFd, line);
      currentBonus[1] = std::stoi(line);
      getline(myFd, line);
      currentBonus[2] = std::stoi(line);
      getline(myFd, line);
      currentBonus[3] = std::stoi(line);
      getline(myFd, line);
      currentBonus[4] = std::stoi(line);
      allBonus.push_back(currentBonus);
    }
  }
  myFd.close();
}

void Indie::Game::load_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {1040, 560, 150, 50})) {
    DrawText("LOAD", 1040, 560, 50, VIOLET);
    if (IsMouseButtonPressed(0))
      load_saves();
  } else
    DrawText("LOAD", 1040, 560, 50, WHITE);
}

void Indie::Game::menu_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {770, 660, 150, 50})) {
    DrawText("MENU", 770, 660, 50, VIOLET);
    if (IsMouseButtonPressed(0)) {
      gameStatus = Indie::Game::MENU;
      EndDrawing();
      BeginDrawing();
      ClearBackground(BLACK);
      DrawText("Back to menu...", 575, 480, 100, WHITE);
      EndDrawing();
    }
  } else
    DrawText("MENU", 770, 660, 50, WHITE);
}

void Indie::Game::quit_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {1040, 660, 150, 50})) {
    DrawText("QUIT", 1040, 660, 50, VIOLET);
    if (IsMouseButtonPressed(0))
      gameStatus = Indie::Game::EXIT;
  } else
    DrawText("QUIT", 1040, 660, 50, WHITE);
}

void Indie::Game::fix_sound(void) {
  DrawText("SOUND", 875, 325, 60, WHITE);
  std::string tmps = std::to_string(((int)myVolume) * 10);
  tmps = tmps + "%";
  DrawText(tmps.c_str(), 925, 430, 60, WHITE);
  DrawRectangle(700, 440, 40, 40, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {700, 440, 40, 40})) {
    DrawText("-", 706, 430, 70, WHITE);
    if (IsMouseButtonPressed(0) && myVolume >= 1) {
      myVolume = myVolume - 1;
      for (int i = 0; i < allSounds.size(); i = i + 1)
        allSounds.at(i)->setSound(myVolume);
    }
  } else {
    DrawText("-", 706, 430, 70, BLACK);
  }
  DrawRectangle(1220, 440, 40, 40, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1220, 440, 40, 40})) {
    DrawText("+", 1223, 429, 70, WHITE);
    if (IsMouseButtonPressed(0) && myVolume <= 9) {
      myVolume = myVolume + 1;
      for (int i = 0; i < allSounds.size(); i = i + 1)
        allSounds.at(i)->setSound(myVolume);
    }
  } else {
    DrawText("+", 1223, 429, 70, BLACK);
  }
}

void Indie::Game::fix_window(void) {
  DrawText("WINDOW", 860, 565, 60, WHITE);
  if (windowS == Indie::Game::FENETRE)
    DrawText("FENETRE", 835, 670, 60, WHITE);
  else
    DrawText("FULL SCREEN", 770, 670, 60, WHITE);
  DrawRectangle(700, 680, 40, 40, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {700, 680, 40, 40})) {
    DrawText("<", 706, 669, 70, WHITE);
    if (IsMouseButtonPressed(0)) {
      if (windowS == Indie::Game::FENETRE)
        windowS = Indie::Game::FULL_SCREEN;
      else
        windowS = Indie::Game::FENETRE;
      ToggleFullscreen();
    }
  } else
    DrawText("<", 706, 669, 70, BLACK);
  DrawRectangle(1220, 680, 40, 40, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1220, 680, 40, 40})) {
    DrawText(">", 1226, 669, 70, WHITE);
    if (IsMouseButtonPressed(0)) {
      if (windowS == Indie::Game::FENETRE)
        windowS = Indie::Game::FULL_SCREEN;
      else
        windowS = Indie::Game::FENETRE;
      ToggleFullscreen();
    }
  } else
    DrawText(">", 1226, 669, 70, BLACK);
}

void Indie::Game::fix_pause(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {680, 325, 110, 50})) {
    DrawText("<---", 680, 325, 60, VIOLET);
    if (IsMouseButtonPressed(0))
      gameStatus = Indie::Game::PAUSE;
  } else
    DrawText("<---", 680, 325, 60, WHITE);
  fix_sound();
  fix_window();
}

void Indie::Game::time_pause(void) {
  std::string gruid;
  DrawRectangle(10, 450, 360, 100, BLACK);
  if (pauseTime <= 0)
    DrawText("DEATH TIME", 40, 480, 45, RED);
  else if (pauseTime == 120) {
    DrawText("02:00", 120, 470, 60, WHITE);
  } else if (pauseTime < 120 && pauseTime >= 60) {
    gruid = "01:";
    if (pauseTime < 70)
      gruid = gruid + "0";
    gruid = gruid + std::to_string(pauseTime - 60);
    DrawText(gruid.c_str(), 120, 470, 60, WHITE);
  } else {
    gruid = "00:";
    if (pauseTime < 10)
      gruid = gruid + "0";
    gruid = gruid + std::to_string(pauseTime);
    DrawText(gruid.c_str(), 120, 470, 60, WHITE);
  }
}

void Indie::Game::manage_pause(void) {
  DrawRectangle(660, 305, 640, 480, BLACK);
  if (gameStatus == Indie::Game::PAUSE)
    DrawText("PAUSE", 865, 340, 70, WHITE);
  time_pause();
  if (gameStatus == Indie::Game::PAUSE) {
    settings_pause();
    resume_pause();
    save_pause();
    load_pause();
    quit_pause();
    menu_pause();
  } else {
    fix_pause();
  }
}
