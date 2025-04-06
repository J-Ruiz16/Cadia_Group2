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
   float hours,price;
   int year;
   //Reads data from the file
   while(std::getline(file, title)){//keeps reading if there is a title
     std::getline(file, publisher);
     std::getline(file, genre);
     file >> hours >> price >> year;
     file.ignore();
     //insert the read data in the library in sorted order
     insert_sorted(Game(title, publisher, genre, hours, price, year));
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
     file << it -> hours << " " << it -> price << " " << it -> year << "\n";
   }
 
   std::cout << "The games were written" << std::endl;
 }
 
 void Library::print(){
   if (games.empty()) {
     std::cout << "No games exist" << std::endl;
     return;
   }
   std::cout << std::left << std::setw(25) << "Title" 
                          << std::setw(20) << "Publisher" 
                          << std::setw(15) << "Genre" 
                          << std::setw(13) << "Hours Played" 
                          << std::setw(10) << "Price" 
                          << std::setw(6) << "Year" << std::endl;
   std::cout << "------------------------------------------------------------------------" << std::endl;
   //iterates through the list to print the data in an ordered manner
   std::list<Game>::iterator it;
   for(it = games.begin(); it != games.end(); it++){
     std::cout << std::left << std::setw(25) << it -> title 
                            << std::setw(20) << it -> publisher 
                            << std::setw(15) << it -> genre 
                            << std::setw(15) << std::fixed << std::setprecision(1) << it -> hours
                            << std::setw(10) << std::fixed << std::setprecision(2) << it -> price 
                            << std::setw(6) << it -> year << std::endl;
   } //Went through and made changes to accomadate price and made it more readable
 }

 void Library::find_genre(std::string& genre) {
  bool found = false;
  std::list<Game>::iterator it;
  //Uses found bool to find the genre of the games it scrolls through
  for( it = games.begin(); it != games.end(); it++) {
    if (it->genre == genre) {
      found = true;
      std::cout << it->title << " by " << it->publisher << " (" << it->year << ")" << std::endl;
    }
  }
  if (!found) std::cout << "No games found in genre: " << genre << std::endl;
}

void Library::find_game(std::string& title_part) {
  bool found = false;
  std::list<Game>::iterator it;
  //Same logic as above but uses any word in the title, hence why we need npos
  for( it = games.begin(); it != games.end(); it++) {
    if (it->title.find(title_part) != std::string::npos) {
      found = true;
      std::cout << it->title << " - " << it->genre << " (" << it->year << ")" << std::endl;
    }
  }
  if (!found) std::cout << "No games found matching title: " << title_part << std::endl;
}


void Library::delete_game(std::string& title, int year) {
  std::list<Game>::iterator it;
  //Same thing as previous too but deletes the game from the txt file instead
  for( it = games.begin(); it != games.end(); it++) {
    if (it->title == title and it->year == year) {
      games.erase(it);
      std::cout << "The game was deleted." << std::endl;
      return;
    }
  }
  std::cout << "The game was not found. Please try again." << std::endl;
}

