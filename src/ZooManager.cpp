#include "ZooManager.hpp"
#include "Lion.hpp"
#include "Eagle.hpp"
#include "Snake.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace ws {

    void ZooManager::addAnimal(std::unique_ptr<Animal> animal) {
        if (animal) {
            std::cout << "Success! Added " << animal->getName() << " to the Zoo.\n";
            m_animals.push_back(std::move(animal));
        }
    }

    void ZooManager::showAllAnimals() const {
        if (m_animals.empty()) {
            std::cout << "The Zoo is empty.\n";
            return;
        }

        std::cout << "=== ZOO ANIMAL LIST ===\n";
        for (const auto& animal : m_animals) {
            std::cout << *animal << "\n";
            std::cout << "---------------------------------------------------\n";
        }
        std::cout << "Total Animals: " << m_animals.size() << "\n";
    }

    void ZooManager::removeAnimalById(int id) {
        auto it = std::find_if(m_animals.begin(), m_animals.end(), 
            [id](const std::unique_ptr<Animal>& a) { return a->getId() == static_cast<unsigned int>(id); });

        if (it != m_animals.end()) {
            std::cout << "Removed: " << (*it)->getName() << " (ID: " << id << ")\n";
            Animal::releaseId(id);
            m_animals.erase(it);
        } else {
            std::cerr << "Animal with ID " << id << " not found!\n";
        }
    }

    Animal* ZooManager::getAnimalById(int id) {
        auto it = std::find_if(m_animals.begin(), m_animals.end(), 
            [id](const std::unique_ptr<Animal>& a) { return a->getId() == static_cast<unsigned int>(id); });
        
        if (it != m_animals.end()) {
            return it->get();
        }
        return nullptr;
    }

    void ZooManager::saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Cannot open file for writing!\n";
            return;
        }

        for (const auto& animal : m_animals) {
            animal->serialize(file);
            file << "\n";
        }
        std::cout << "Data saved to file " << filename << "\n";
    }

    void ZooManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File " << filename << " missing. Starting fresh.\n";
        return;
    }

    clearZoo();
    std::string type;
    
    while (file >> type) {
        std::unique_ptr<Animal> loadedAnimal = nullptr;
        
        if (type == "Lion") {
            loadedAnimal = Lion::fromFileStream(file);
        } else if (type == "Eagle") {
            loadedAnimal = Eagle::fromFileStream(file);
        } else if (type == "Snake") {
            loadedAnimal = Snake::fromFileStream(file);
        }

        if (loadedAnimal) {
            addAnimal(std::move(loadedAnimal));
        }
    }

    std::vector<unsigned int> loadedIds;
    for (const auto& animal : m_animals) {
        loadedIds.push_back(animal->getId());
    }
    Animal::rebuildFreeIds(loadedIds);
    std::cout << "Loaded " << m_animals.size() << " animals from file.\n";
    }
}