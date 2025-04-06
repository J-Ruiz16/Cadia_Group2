/**
 * @file main.cpp
 * @author Jocelyn Ruiz
 * @date 2025-04-03
 * @brief User interaction and driver
 *
 * program includes a driver for options for the Game library and interaction 
 *with user to choice options for reading, writing, finding, printing, deleting
 */
#include "game.h"
#include "library.h"
#include <iostream>

int main(){
  Library l;

  int choice;
  std::string filename;
  std::cout << "Game Library! Choose an option:" << std::endl;

  do {
    std::cout << "1. Read from file" << std::endl;
    std::cout << "2. Write to a file" << std::endl;
    std::cout << "3. Print game library" << std::endl;
    std::cout << "4. Add a game" << std::endl;
    std::cout << "5. Find by genre" << std::endl;
    std::cout << "6. Find by title keyword" << std:: endl;
    std::cout << "7. Delete a game" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cout << "Please enter choice: ";
    std::cin >> choice;
    std::cin.ignore();
    switch(choice) {
    case 1:
      std::cout << "Enter a file name for reading: ";
      std::cin >> filename;
      l.read_from_file(filename);
      std::cout << "File was read successfully" << std::endl;
      break;
    case 2:
      std::cout << "Enter a file name for writing: ";
      std::cin >> filename;
      l.write_to_file(filename);
      std::cout << "File was written successfully" << std::endl;
      break;
    case 3:
      l.print();
      break;
    case 4: {
      Game g("", "", "", 0.0, 0.0, 0);
      std::cout << "Enter game title: ";
      std::getline(std::cin, g.title);
      std::cout << "Enter game publisher: ";
      std::getline(std::cin, g.publisher);
      std::cout << "Enter game genre: ";
      std::getline(std::cin, g.genre);
      std::cout << "Enter game hours played: ";
      std::cin >> g.hours;
      std::cout << "Enter game price: ";
      std::cin >> g.price;
      std::cout << "Enter game year: ";
      std::cin >> g.year;
      std::cin.ignore();

      l.insert_sorted(g);
      std::cout << "The game was added" << std::endl;
      break;
    }
    case 5: {
      std::string genre;
      std::cout << "Enter genre: ";
      std::getline(std::cin, genre);
      l.find_genre(genre);
      break;
    }
    case 6: {
      std::string keyword;
      std::cout << "Enter part of the title to search for: ";
      std::getline(std::cin, keyword);
      l.find_game(keyword);
      break;
    }
    case 7: {
      std::string title;
      int year;
      std::cout << "Enter title to delete: ";
      std::getline(std::cin, title);
      std::cout << "Enter year: ";
      std::cin >> year;
      std::cin.ignore();
      l.delete_game(title, year);
      break;
    }
    case 0: {
      std::cout << "Thank you for using our library!" << std::endl;
      break;
    }
    default:
      std::cout << "Invalid choice" << std::endl;
      std::cout << " " << std::endl;
    }
  }while(choice != 0);
  return 0;
}
