#pragma once

#include "Mammal.hpp"
#include <iostream>
#include <memory>

/**
 * @file Lion.hpp
 * @brief Specific class for Lions.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a Lion, specialized from Mammal.
     * Includes attributes like mane length and roar volume.
     */
    class Lion : public Mammal {
    private:
        double m_maneLength;
        int m_prideSize;
        int m_roarVolumeDecibels;

    public:
        /**
         * @brief Default constructor.
         */
        Lion();

        /**
         * @brief Parameterized constructor for a Lion.
         */
        Lion(const std::string& n, const std::string& g, int a, double w, const Date& d, 
             double mane, int pride, int volume);

        // Getters
        double getManeLength() const { return m_maneLength; }
        int getPrideSize() const { return m_prideSize; }
        int getRoarVolume() const { return m_roarVolumeDecibels; }

        /**
         * @brief Sets the mane length.
         * @throws std::invalid_argument if length is negative.
         */
        void setManeLength(double len);

        /**
         * @brief Sets the pride size.
         * @throws std::invalid_argument if size is negative.
         */
        void setPrideSize(int size);

        /**
         * @brief Sets the roar volume in decibels.
         * @throws std::invalid_argument if volume is negative.
         */
        void setRoarVolume(int vol);

        /**
         * @brief Serializes lion specific data.
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints full details including specific lion traits.
         */
        void printDetails(std::ostream& os) const override;

        /**
         * @brief Static factory method to create a Lion from an input stream.
         * @return Pointer to new Lion object or nullptr if parsing fails.
         */
        static std::unique_ptr<Lion> fromFileStream(std::istream& is);
    };

}