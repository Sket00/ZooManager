#pragma once

#include "Animal.hpp"

/**
 * @file Bird.hpp
 * @brief Base class for birds.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a bird with specific attributes like wingspan and beak color.
     */
    class Bird : public Animal {
    private:
        double m_wingSpan;
        bool m_canFly;
        std::string m_beakColor;

    public:
        /**
         * @brief Default constructor.
         */
        Bird();

        /**
         * @brief Parameterized constructor initializing all bird attributes.
         */
        Bird(const std::string& n, const std::string& g, int a, double w, const Date& d, 
             double wings, bool fly, const std::string& beak);

        // Getters
        double getWingSpan() const { return m_wingSpan; }
        bool getCanFly() const { return m_canFly; }
        std::string getBeakColor() const { return m_beakColor; }

        /**
         * @brief Sets the wingspan in meters.
         * @throws std::invalid_argument if wingspan is negative.
         */
        void setWingSpan(double wings);

        /**
         * @brief Sets the ability to fly.
         */
        void setCanFly(bool fly);

        /**
         * @brief Sets the beak color.
         * @throws std::invalid_argument if beak color string is empty.
         */
        void setBeakColor(const std::string& beak);

        /**
         * @brief Serializes bird data.
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints detailed bird information.
         */
        void printDetails(std::ostream& os) const override;
    };

}