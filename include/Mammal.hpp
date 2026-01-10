#pragma once

#include "Animal.hpp"

/**
 * @file Mammal.hpp
 * @brief Derived class representing mammals.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a mammal with specific attributes like fur and diet.
     */
    class Mammal : public Animal {
    private:
        bool m_hasFur;
        bool m_isAggressive;
        std::string m_dietType;

    public:
        /**
         * @brief Default constructor.
         */
        Mammal();

        /**
         * @brief Parameterized constructor initializing all mammal attributes.
         */
        Mammal(const std::string& n, const std::string& g, int a, double w, const Date& d, 
               bool fur, bool aggressive, const std::string& diet);

        // Getters
        bool getHasFur() const { return m_hasFur; }
        bool getIsAggressive() const { return m_isAggressive; }
        std::string getDietType() const { return m_dietType; }

        // Setters
        void setHasFur(bool fur);
        void setIsAggressive(bool aggressive);

        /**
         * @brief Sets the diet type.
         * @throws std::invalid_argument if diet string is empty.
         */
        void setDietType(const std::string& diet);

        /**
         * @brief Serializes mammal data (including base Animal data).
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints detailed mammal information.
         */
        void printDetails(std::ostream& os) const override;
    };

}