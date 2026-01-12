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
         * @brief Safely reads input from stdin with validation and error handling.
         * @tparam T Type of value to read
         * @param prompt Message displayed to user
         * @return Validated input value
         * 
         * Repeatedly prompts until valid input is received.
         * Clears input buffer on failure.
         */
        template <typename T>
        static T safeInput(const std::string& prompt);

        // --- Data Input Methods ---
        
        /// @name Animal Creation Helpers
        /// Collect data for specific animal types during creation
        /// @{
        static void inputAnimalData(Animal* animal);
        static void inputMammalData(Mammal* mammal);
        static void inputBirdData(Bird* bird);
        static void inputReptileData(Reptile* reptile);
        static void inputLionData(Lion* lion);
        static void inputEagleData(Eagle* eagle);
        static void inputSnakeData(Snake* snake);
        /// @}

        // --- Edit Menu Methods ---
        
        /// @name Interactive Edit Menus
        /// Display menus and handle editing for specific animal types
        /// @{
        static void editAnimalMenu(Animal* animal);
        static void editMammalMenu(Mammal* mammal);
        static void editBirdMenu(Bird* bird);
        static void editReptileMenu(Reptile* reptile);
        static void editLionMenu(Lion* lion);
        static void editEagleMenu(Eagle* eagle);
        static void editSnakeMenu(Snake* snake);
        /// @}
    };

}