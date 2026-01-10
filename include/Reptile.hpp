#pragma once

#include "Animal.hpp"

/**
 * @file Reptile.hpp
 * @brief Base class for reptiles.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a reptile with attributes like scale texture and heat requirements.
     */
    class Reptile : public Animal {
    private:
        bool m_isVenomous;
        std::string m_scaleTexture;
        bool m_requiresHeatLamp;

    public:
        /**
         * @brief Default constructor.
         */
        Reptile();

        /**
         * @brief Parameterized constructor initializing all reptile attributes.
         */
        Reptile(const std::string& n, const std::string& g, int a, double w, const Date& d, 
                bool venom, const std::string& texture, bool heat);

        // Getters
        bool getIsVenomous() const { return m_isVenomous; }
        std::string getScaleTexture() const { return m_scaleTexture; }
        bool getRequiresHeatLamp() const { return m_requiresHeatLamp; }

        /**
         * @brief Sets whether the reptile is venomous.
         */
        void setIsVenomous(bool v);

        /**
         * @brief Sets the scale texture description.
         * @throws std::invalid_argument if texture string is empty.
         */
        void setScaleTexture(const std::string& texture);

        /**
         * @brief Sets whether a heat lamp is required.
         */
        void setRequiresHeatLamp(bool h);

        /**
         * @brief Serializes reptile data.
         */
        void serialize(std::ostream& os) const override;

        /**
         * @brief Prints detailed reptile information.
         */
        void printDetails(std::ostream& os) const override;
    };

}