#include "Bird.hpp"
#include <stdexcept>

namespace ws {

    Bird::Bird() : Animal(), m_wingSpan(0.1), m_canFly(true), m_beakColor("Yellow") {}

    Bird::Bird(const std::string& n, const std::string& g, int a, double w, const Date& d, 
               double wings, bool fly, const std::string& beak)
        : Animal(n, g, a, w, d), m_wingSpan(wings), m_canFly(fly), m_beakColor(beak) {}

    void Bird::setWingSpan(double wings) {
        if (wings < 0) throw std::invalid_argument("Wingspan cannot be negative");
        m_wingSpan = wings;
    }
    void Bird::setCanFly(bool fly) { m_canFly = fly; }
    void Bird::setBeakColor(const std::string& beak) {
        if(beak.empty()) throw std::invalid_argument("Beak color cannot be empty");
        m_beakColor = beak;
    }

    void Bird::serialize(std::ostream& os) const {
        Animal::serialize(os);
        os << " " << m_wingSpan << " " << m_canFly << " " << m_beakColor;
    }

    void Bird::printDetails(std::ostream& os) const {
        Animal::printDetails(os);
        os << " | Wingspan: " << m_wingSpan << "m"
           << " | Flying: " << (m_canFly ? "Yes" : "No")
           << " | Beak: " << m_beakColor;
    }
}