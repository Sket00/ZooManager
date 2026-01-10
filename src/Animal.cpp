#include "Animal.hpp"
#include <stdexcept>
#include <limits>

namespace ws {

    unsigned int Animal::m_nextId = 0;
    std::set<unsigned int> Animal::m_freeIds;

    Animal::Animal() 
        : m_name("Unknown"), m_gender("Unknown"), m_age(0), m_weight(MIN_WEIGHT), m_arrivalDate() {
        if (!m_freeIds.empty()) {
            m_id = *m_freeIds.begin();
            m_freeIds.erase(m_freeIds.begin());
        } else {
            m_id = m_nextId++;
        }
    }

    Animal::Animal(const std::string& n, const std::string& g, int a, double w, const Date& arrival)
        : m_name(n), m_gender(g), m_arrivalDate(arrival) {
        if (!m_freeIds.empty()) {
            m_id = *m_freeIds.begin();
            m_freeIds.erase(m_freeIds.begin());
        } else {
            m_id = m_nextId++;
        }
        setAge(a);
        setWeight(w);
    }

    void Animal::setName(const std::string& n) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        m_name = n;
    }

    void Animal::setGender(const std::string& g) {
        if (g != "M" && g != "F") throw std::invalid_argument("Gender must be M or F");
        m_gender = g;
    }

    void Animal::setAge(int a) {
        if (a < 0) throw std::invalid_argument("Age cannot be negative");
        m_age = a;
    }

    void Animal::setWeight(double w) {
        if (w <= MIN_WEIGHT) throw std::invalid_argument("Weight must be greater than " + std::to_string(MIN_WEIGHT));
        m_weight = w;
    }

    void Animal::setArrivalDate(const Date& d) {
        m_arrivalDate = d;
    }

    void Animal::releaseId(unsigned int idToRelease) {
        if (idToRelease < m_nextId) {
            m_freeIds.insert(idToRelease);
        }
    }

    void Animal::resetIdCounter() {
        m_nextId = 0;
        m_freeIds.clear();
    }

    void Animal::forceId(unsigned int newId) {
        m_id = newId;
        updateNextId(newId);
        m_freeIds.erase(newId);
    }

    void Animal::updateNextId(unsigned int idFromFile) {
        if (idFromFile >= m_nextId) {
            m_nextId = idFromFile + 1;
        }
    }

    void Animal::rebuildFreeIds(const std::vector<unsigned int>& existingIds) {
        m_freeIds.clear();
        std::set<unsigned int> taken(existingIds.begin(), existingIds.end());
        for (unsigned int i = 0; i < m_nextId; ++i) {
            if (taken.find(i) == taken.end()) {
                m_freeIds.insert(i);
            }
        }
    }

    void Animal::serialize(std::ostream& os) const {
        os << m_id << " " << m_name << " " << m_gender << " " << m_age << " " << m_weight << " " << m_arrivalDate.toString();
    }

    void Animal::printDetails(std::ostream& os) const {
        os << "[ID:" << m_id << "] " << m_name 
           << " | " << m_gender 
           << " | " << m_age << "yo"
           << " | " << m_weight << "kg"
           << " | Arrived: " << m_arrivalDate;
    }

    std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        animal.printDetails(os);
        return os;
    }
}