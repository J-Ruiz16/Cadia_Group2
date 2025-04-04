/**
 * @file library.h
 * @author Jocelyn Ruiz
 * @date 2025-04-03
 * @brief class definition of Library
 *
 * This program reads, writes, deletes, prints, finds games
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "game.h"
#include <list>
#include <fstream>


/**
 * Includes methods to read from a file, write to a file, print content\
s of file, find specfic genre or game, delete games
 *
 * @class Library{ library.h "Game_library/library.h"
 * @brief class that uses methods to read, write, print , find, delete \
games
 *
 */
class Library{
 private:
  std::list<Game> games;
  
 public:
  
  /**
 * Adds a game to the library sorting by title
 *
 * @param const Gamee& game
 * @return void return nothing
 *
 */
  void insert_sorted(const Game& game);
/**
 * Reads the game data from the string file input
 *
 * @param const std::string& filename a file input from user
 * @return void return nothing
 *
 */
  void read_from_file(const std::string& filename);

/**
 * takes a string file name as parameter and writes to the file
 *
 * @param const std::string& file name file input from user
 * @return void return nothing
 *
 */
  void write_to_file(const std::string& filename);

/**
 * Prints contents of file in sorted order
 *
 * @return void returns nothing
 *
 */
  void print();
};

#endif //LIBRARY_H
