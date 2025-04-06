/**
 * @file game.h
 * @author Jocelyn Ruiz
 * @date 2025-04-03
 * @brief game struct definiiton
 *
 * holds information about game like title,publisher, genre, hors playe\
d, and year
 *uses constructor to initialize the above.
 */

#ifndef GAME_H
#define GAME_H

#include <string>

struct Game{
  std::string title;
  std::string publisher;
  std::string genre;
  float hours;
  float price; //added this since it was forgotten 
  int year;
  //constructor for initialization
  Game(std::string t, std::string p, std::string g, float h, float pr, int y){
    title = t;
    publisher = p;
    genre = g;
    hours = h;
    price = pr;
    year = y;
  }
};

#endif //GAME_H
