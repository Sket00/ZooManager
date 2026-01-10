#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

/**
 * @file Date.hpp
 * @brief Helper class for date handling (DD-MM-YYYY format)
 * @author Wojciech Skawiński
 */

namespace ws {

    /**
     * @brief Class representing a date with validation.
     */
    class Date {
    private:
        int m_day;
        int m_month;
        int m_year;

        /**
         * @brief Checks if a year is a leap year.
         */
        constexpr bool isLeapYear(int y) const {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        }

        /**
         * @brief Validates date correctness.
         * @throws std::out_of_range if date is invalid.
         */
        void validate(int d, int m, int y);

    public:
        /**
         * @brief Default constructor (sets a default date).
         */
        Date();

        /**
         * @brief Parameterized constructor (integers).
         */
        Date(int d, int m, int y);

        /**
         * @brief Constructor parsing a string.
         * Supports formats: 13.12.2025, 13-12-2025, 13/12/2025
         * @throws std::invalid_argument if format is incorrect.
         */
        explicit Date(const std::string& dateStr);

        // Getters
        int getDay() const { return m_day; }
        int getMonth() const { return m_month; }
        int getYear() const { return m_year; }

        /**
         * @brief Returns date as a string in DD.MM.YYYY format.
         */
        std::string toString() const;

        /**
         * @brief Output stream operator overload.
         */
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
        
        /**
         * @brief Equality operator.
         */
        bool operator==(const Date& other) const;
    };

} 