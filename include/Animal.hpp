#pragma once

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include "Date.hpp"

/**
 * @file Animal.hpp
 * @brief Base class for all animals in the zoo system.
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Abstract base class representing a generic animal.
     * Manages unique IDs and basic attributes like name, age, and weight.
     */
    class Animal {
        friend class ZooManager;
        
    private:
        static unsigned int m_nextId;
        static std::set<unsigned int> m_freeIds;
        
        unsigned int m_id;
        std::string m_name;
        std::string m_gender;
        int m_age;
        double m_weight;
        Date m_arrivalDate;

    protected:
        /// Minimum allowed weight
        static constexpr int MIN_WEIGHT = 0;
        
        /**
         * @brief Releases an ID back to the pool for reuse.
         * @param idToRelease ID to be released
         */
        static void releaseId(unsigned int idToRelease);
        
        /**
         * @brief Resets the ID counter to initial state.
         */
        static void resetIdCounter();
        
        /**
         * @brief Rebuilds the free IDs pool from existing IDs.
         * @param existingIds Vector of currently used IDs
         */
        static void rebuildFreeIds(const std::vector<unsigned int>& existingIds);
        
        /**
         * @brief Forces a specific ID for this object (used when loading from file).
         * @param newId ID to assign
         */
        void forceId(unsigned int newId);
        
        /**
         * @brief Updates the next ID counter based on loaded ID.
         * @param idFromFile ID loaded from file
         */
        static void updateNextId(unsigned int idFromFile);
        
    public:
        /**
         * @brief Default constructor. Assigns a unique ID automatically.
         */
        Animal();

        /**
         * @brief Parameterized constructor.
         * @throws std::invalid_argument if validation fails in setters.
         */
        Animal(const std::string& n, const std::string& g, int a, double w, const Date& arrival);

        virtual ~Animal() = default;

        // Getters
        unsigned int getId() const { return m_id; }
        std::string getName() const { return m_name; }
        std::string getGender() const { return m_gender; }
        int getAge() const { return m_age; }
        double getWeight() const { return m_weight; }
        Date getArrivalDate() const { return m_arrivalDate; }

        /**
         * @brief Sets the animal's name.
         * @throws std::invalid_argument if name is empty.
         */
        void setName(const std::string& n);

        /**
         * @brief Sets the gender (M/F).
         * @throws std::invalid_argument if gender is not 'M' or 'F'.
         */
        void setGender(const std::string& g);

        /**
         * @brief Sets the age.
         * @throws std::invalid_argument if age is negative.
         */
        void setAge(int a);

        /**
         * @brief Sets the weight.
         * @throws std::invalid_argument if weight is invalid.
         */
        void setWeight(double w);

        /**
         * @brief Sets the arrival date.
         */
        void setArrivalDate(const Date& d);

        /**
         * @brief Serializes animal data to a stream.
         */
        virtual void serialize(std::ostream& os) const;

        /**
         * @brief Prints formatted details to a stream.
         */
        virtual void printDetails(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
    };

}