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

  do {
    std::cout << "Game Library! Choose an option:" << std::endl;
    std::cout << "1. Read from file" << std::endl;
    std::cout << "2. Write to a file" << std::endl;
    std::cout << "3. Print game library" << std::endl;
    std::cout << "4. Add a game" << std::endl;

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
      std::cout << "Enter a file name: ";
      std::cin >> filename;
      l.read_from_file(filename);
      l.print();
      break;
    case 4: {
      Game g("", "", "", 0.0, 0);
      std::cout << "Enter game title: ";
      std::getline(std::cin, g.title);
      std::cout << "Enter game publisher: ";
      std::getline(std::cin, g.publisher);
      std::cout << "Enter game genre: ";
      std::getline(std::cin, g.genre);
      std::cout << "Enter game hours played: ";
      std::cin >> g.hours;
      std::cout << "Enter game year: ";
      std::cin >> g.year;
      std::cin.ignore();

      l.insert_sorted(g);
      std::cout << "The game was added" << std::endl;
      break;
    }
    default:
      std::cout << "Invalid choice" << std::endl;
    }
  }while(choice != 4);
  return 0;
}
