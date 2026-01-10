#pragma once

#include "Bird.hpp"
#include <iostream>

/**
 * @file Eagle.hpp
 * @brief Specific class for Eagles.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing an Eagle, specialized from Bird.
     * Includes attributes like vision range and diving speed.
     */
    class Eagle : public Bird {
    private:
        double m_visionRangeMeters;
        double m_divingSpeedKmh;
        bool m_isTrained;

    public:
        /**
         * @brief Default constructor.
         */
        Eagle();

        /**
         * @brief Parameterized constructor for an Eagle.
         */
        Eagle(const std::string& n, const std::string& g, int a, double w, const Date& d, 
              double vision, double speed, bool trained);

        // Getters
        double getVisionRange() const { return m_visionRangeMeters; }
        double getDivingSpeed() const { return m_divingSpeedKmh; }
        bool getIsTrained() const { return m_isTrained; }

        /**
         * @brief Sets the vision range in meters.
         * @throws std::invalid_argument if range is negative.
         */
        void setVisionRange(double range);

        /**
         * @brief Sets the diving speed in km/h.
         * @throws std::invalid_argument if speed is negative.
         */
        void setDivingSpeed(double speed);

        /**
         * @brief Sets whether the eagle is trained.
         */
        void setIsTrained(bool trained);

        /**
         * @brief Serializes eagle specific data.
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints full details including specific eagle traits.
         */
        void printDetails(std::ostream& os) const override;

        /**
         * @brief Static factory method to create an Eagle from an input stream.
         * @return Pointer to new Eagle object or nullptr if parsing fails.
         */
        static Eagle* fromFileStream(std::istream& is);
    };

}