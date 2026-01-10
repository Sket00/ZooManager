#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Animal.hpp"

/**
 * @file ZooManager.hpp
 * @brief Manages the collection of animals in the zoo.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class responsible for managing a list of animals.
     * Handles adding, removing, listing, and file persistence.
     */
    class ZooManager {
    private:
        std::vector<std::unique_ptr<Animal>> m_animals;

    public:
        /**
         * @brief Adds a new animal to the zoo.
         * Takes ownership of the pointer.
         */
        void addAnimal(std::unique_ptr<Animal> animal);

        /**
         * @brief Displays all animals to standard output.
         */
        void showAllAnimals() const;

        /**
         * @brief Removes an animal by its unique ID.
         * Releases the ID back to the pool.
         */
        void removeAnimalById(int id);

        /**
         * @brief Saves the current zoo state to a text file.
         */
        void saveToFile(const std::string& filename) const;

        /**
         * @brief Loads animals from a text file.
         * Clears current zoo state before loading.
         */
        void loadFromFile(const std::string& filename);

        /**
         * @brief Clears all animals from the zoo.
         */
        void clearZoo() { m_animals.clear(); }
        
        /**
         * @brief Finds an animal by ID and returns a raw pointer.
         * @return Pointer to the animal or nullptr if not found.
         */
        Animal* getAnimalById(int id);
    };

}