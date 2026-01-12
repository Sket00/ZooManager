#include <iostream>
#include <limits>
#include <memory>
#include "ZooManager.hpp"
#include "DataIO.hpp"



void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "\n--- ZOO MANAGER SYSTEM ---\n";
    std::cout << "1. Add New Animal\n";
    std::cout << "2. List All Animals\n";
    std::cout << "3. Remove Animal by ID\n";
    std::cout << "4. Edit Animal Attributes\n";
    std::cout << "5. Save & Exit\n";
    std::cout << "Choice: ";
}

int main() {
    try {
        ws::ZooManager zoo;
        zoo.loadFromFile("zoo_db.txt");

        bool running = true;
        while (running) {
            displayMenu();
            int choice;
            if (!(std::cin >> choice)) {
                clearInput();
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
                case 1: {
                    auto newAnimal = ws::DataIO::createAnimalSelection();
                    if (newAnimal) {
                        zoo.addAnimal(std::move(newAnimal));
                    }
                    break;
                }
                case 2:
                    zoo.showAllAnimals();
                    break;
                case 3: {
                    int id;
                    std::cout << "ID to remove: ";
                    std::cin >> id;
                    zoo.removeAnimalById(id);
                    std::cout << "Removed: Animal with ID: " << id << "\n";
                    break;
                }
                case 4: {
                    int id;
                    std::cout << "ID to edit: ";
                    std::cin >> id;
                    ws::Animal* animal = zoo.getAnimalById(id);
                    if (animal) {
                        ws::DataIO::editAnimal(animal);
                        std::cout << "Update complete.\n";
                    } else {
                        std::cout << "Animal not found.\n";
                    }
                    break;
                }
                case 5:
                    zoo.saveToFile("zoo_db.txt");
                    std::cout << "Data saved to file zoo_db.txt\n";
                    running = false;
                    break;
                default:
                    std::cout << "Invalid option.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Critical Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}