/*
** EPITECH PROJECT, 2022
** Indie studio
** File description:
** Main
*/

#include "../include/Macro.hpp"
#include <iostream>
#include <string.h>

void print_doc(void);
int start_indie(void);

int main(int ac, char **av) {
  int rt;

  if (ac == 2 && strcmp(av[1], "-doc") == 0) {
    print_doc();
    return (EXIT_OK);
  } else if (ac > 1) {
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t./bomberman -doc\tPrint the documentation." << std::endl;
    std::cout << "\t./bomberman\t\tPlay the game." << std::endl;
    return (EXIT_ERROR);
  } else {
    rt = start_indie();
  }
  return (rt);
}
