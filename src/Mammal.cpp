#include "Mammal.hpp"

namespace ws {

    Mammal::Mammal() : Animal(), m_hasFur(true), m_isAggressive(false), m_dietType("Omnivore") {}

    Mammal::Mammal(const std::string& n, const std::string& g, int a, double w, const Date& d, 
                   bool fur, bool aggressive, const std::string& diet)
        : Animal(n, g, a, w, d), m_hasFur(fur), m_isAggressive(aggressive), m_dietType(diet) {}

    void Mammal::setHasFur(bool fur) { m_hasFur = fur; }
    void Mammal::setIsAggressive(bool aggressive) { m_isAggressive = aggressive; }
    void Mammal::setDietType(const std::string& diet) { 
        if(diet.empty()) throw std::invalid_argument("Diet cannot be empty");
        m_dietType = diet; 
    }

    void Mammal::serialize(std::ostream& os) const {
        Animal::serialize(os);
        os << " " << m_hasFur << " " << m_isAggressive << " " << m_dietType;
    }

    void Mammal::printDetails(std::ostream& os) const {
        Animal::printDetails(os);
        os << " | Fur: " << (m_hasFur ? "Yes" : "No")
           << " | Aggressive: " << (m_isAggressive ? "Yes" : "No")
           << " | Diet: " << m_dietType;
    }
}