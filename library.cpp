/**
 * @file library.cpp
 * @author Jocelyn Ruiz
 * @date 2025-04-03
 * @brief Implementation of the class Library
 *
 * This program reads, writes, deletes, prints, find games
 */

#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void Library::insert_sorted(const Game& game){
  //the following iterates through the list
  std::list<Game>::iterator it;
  for(it = games.begin(); it != games.end(); it++){
    if (game.title < it -> title){//sorts by title
      games.insert(it, game);
      return;
    }
  }
  games.push_back(game);//inserts at the end of the list
}
void Library::read_from_file(const std::string& filename){
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error cannot open the file for reading: " << filename << std::endl;
    return;
  }

  std::string title, publisher, genre;
  float hours;
  int year;
  //Reads data from the file
  while(std::getline(file, title)){//keeps reading if there is a title
    std::getline(file, publisher);
    std::getline(file, genre);
    file >> hours >> year;
    file.ignore();
    //insert the read data in the library in sorted order
    insert_sorted(Game(title, publisher, genre, hours, year));
  }
  std::cout << "The games were read" << std::endl;
}

void Library::write_to_file(const std::string& filename){
  std::ofstream file(filename);
  if(!file) {
    std::cerr << "Error opening the file for writing: " << filename << std::endl;
    return;
  }
  //iterates through the list of games in library and writes data to the file
  std::list<Game>::iterator it;
  for( it = games.begin(); it != games.end(); it++) {
    file << it -> title << "\n";
    file << it -> publisher << "\n";
    file << it -> genre << "\n";
    file << it -> hours << " " << it -> year << "\n";
  }

  std::cout << "The games were written" << std::endl;
}

void Library::print(){
  if (games.empty()) {
    std::cout << "No games exist" << std::endl;
    return;
  }

  std::cout << std::left << std::setw(25) << "Title" << std::setw(20)
            << "Publisher" << std::setw(15) << "Genre" << std::setw(10)
            << "Hours Played" << std::endl;
  std::cout << "------------------------------------------------------------------------" << std::endl;
  //iterates through the list to print the data in an ordered manner
  std::list<Game>::iterator it;
  for(it = games.begin(); it != games.end(); it++){
    std::cout << std::left << std::setw(25) << it -> title << std::setw(20)
              << it -> publisher << std:: setw(15) << it -> genre
              << std::setw(10) << it -> hours << std::setw(6) << it -> year << std::endl;
  }
}
