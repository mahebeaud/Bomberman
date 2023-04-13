/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Print help
*/

#include <fstream>
#include <iostream>

void print_doc(void) {
  std::ifstream myFd("README.md");
  std::string line;
  while (getline(myFd, line))
    std::cout << line << std::endl;
  myFd.close();
}
