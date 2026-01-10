#pragma once

#include "Reptile.hpp"
#include <iostream>

/**
 * @file Snake.hpp
 * @brief Specific class for Snakes.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a Snake, specialized from Reptile.
     * Includes attributes like length and constrictor status.
     */
    class Snake : public Reptile {
    private:
        double m_lengthMeters;
        bool m_isConstrictor;
        int m_sheddingFrequencyDays;

    public:
        /**
         * @brief Default constructor.
         */
        Snake();

        /**
         * @brief Parameterized constructor for a Snake.
         */
        Snake(const std::string& n, const std::string& g, int a, double w, const Date& d, 
              double length, bool constrictor, int shedding);

        // Getters
        double getLength() const { return m_lengthMeters; }
        bool getIsConstrictor() const { return m_isConstrictor; }
        int getSheddingFrequency() const { return m_sheddingFrequencyDays; }

        /**
         * @brief Sets the snake's length in meters.
         * @throws std::invalid_argument if length is negative.
         */
        void setLength(double len);

        /**
         * @brief Sets whether the snake is a constrictor.
         */
        void setIsConstrictor(bool c);

        /**
         * @brief Sets the shedding frequency in days.
         * @throws std::invalid_argument if frequency is negative.
         */
        void setSheddingFrequency(int days);

        /**
         * @brief Serializes snake specific data.
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints full details including specific snake traits.
         */
        void printDetails(std::ostream& os) const override;

        /**
         * @brief Static factory method to create a Snake from an input stream.
         * @return Pointer to new Snake object or nullptr if parsing fails.
         */
        static Snake* fromFileStream(std::istream& is);
    };

}