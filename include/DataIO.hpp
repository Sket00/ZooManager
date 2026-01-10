#pragma once

#include "Animal.hpp"
#include "Lion.hpp"
#include "Eagle.hpp"
#include "Snake.hpp"
#include <memory>
#include <iostream>
#include <limits>
#include <string>

/**
 * @file DataIO.hpp
 * @brief Handles user input and output operations for animal data.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Static helper class for console I/O and menu interactions.
     */
    class DataIO {
    public:
        /**
         * @brief interactive menu to create a specific type of animal.
         * @return std::unique_ptr to the created animal (or nullptr on failure).
         */
        static std::unique_ptr<Animal> createAnimalSelection();

        /**
         * @brief Starts the edit menu for a specific animal.
         * Detects the animal type and shows relevant options.
         */
        static void editAnimal(Animal* animal);

    private:
        /**
         * @brief Helper template to safely get input from std::cin.
         * Clears buffer on failure.
         */
        template <typename T>
        static T safeInput(const std::string& prompt);

        // Input helpers
        static void inputAnimalData(Animal* animal);
        static void inputMammalData(Mammal* mammal);
        static void inputBirdData(Bird* bird);
        static void inputReptileData(Reptile* reptile);
        
        static void inputLionData(Lion* lion);
        static void inputEagleData(Eagle* eagle);
        static void inputSnakeData(Snake* snake);

        // Edit menu helpers
        static void editAnimalMenu(Animal* animal);
        static void editMammalMenu(Mammal* mammal);
        static void editBirdMenu(Bird* bird);
        static void editReptileMenu(Reptile* reptile);
        
        static void editLionMenu(Lion* lion);
        static void editEagleMenu(Eagle* eagle);
        static void editSnakeMenu(Snake* snake);
    };

}