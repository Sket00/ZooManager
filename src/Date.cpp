#include "Date.hpp"
#include <sstream>
#include <iomanip>
#include <vector>

namespace ws {

    Date::Date() : m_day(1), m_month(1), m_year(2000) {}

    Date::Date(int d, int m, int y) {
        validate(d, m, y);
        m_day = d;
        m_month = m;
        m_year = y;
    }

    Date::Date(const std::string& dateStr) {
        std::istringstream ss(dateStr);
        char sep1, sep2;
        int d, m, y;

        if (!(ss >> d >> sep1 >> m >> sep2 >> y)) {
            throw std::invalid_argument("Invalid date format (parse error): " + dateStr);
        }

        if (!ss.eof()) {
             throw std::invalid_argument("Invalid date format (trailing characters): " + dateStr);
        }

        if (sep1 != sep2) {
            throw std::invalid_argument("Invalid date format (mixed separators): " + dateStr);
        }

        std::string allowedSeps = ".-/";
        if (allowedSeps.find(sep1) == std::string::npos) {
             throw std::invalid_argument("Invalid date format (invalid separator): " + dateStr);
        }

        validate(d, m, y);
        
        m_day = d;
        m_month = m;
        m_year = y;
    }

    void Date::validate(int d, int m, int y) {
        if (y < 1900 || y > 2100) {
            throw std::out_of_range("Year out of allowed range (1900-2100)");
        }
        if (m < 1 || m > 12) {
            throw std::out_of_range("Month must be between 1-12");
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(y)) {
            daysInMonth[2] = 29;
        }

        if (d < 1 || d > daysInMonth[m]) {
            throw std::out_of_range("Invalid day for the given month");
        }
    }

    std::string Date::toString() const {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << m_day << "."
            << std::setw(2) << std::setfill('0') << m_month << "."
            << m_year;
        return oss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.toString();
        return os;
    }

    bool Date::operator==(const Date& other) const {
        return m_day == other.m_day && m_month == other.m_month && m_year == other.m_year;
    }

}