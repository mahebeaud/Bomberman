/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** soun
*/

#include "MakeSound.hpp"

GameEngine::MakeSound::MakeSound(const char *path) noexcept {
  snd = LoadSound(path);
}

void GameEngine::MakeSound::play_sound(void) { PlaySound(snd); }

void GameEngine::MakeSound::setSound(float volume) {
  SetSoundVolume(snd, (volume / 10));
}

void GameEngine::MakeSound::unloadSound(void) { UnloadSound(snd); }
