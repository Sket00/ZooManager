#include "Snake.hpp"
#include <stdexcept>

namespace ws {

    Snake::Snake() : Reptile(), m_lengthMeters(0), m_isConstrictor(false), m_sheddingFrequencyDays(0) {}

    Snake::Snake(const std::string& n, const std::string& g, int a, double w, const Date& d, 
                 bool venom, const std::string& texture, bool heat, double length, bool constrictor, int shedding)
        : Reptile(n, g, a, w, d, venom, texture, heat), 
          m_lengthMeters(length), m_isConstrictor(constrictor), m_sheddingFrequencyDays(shedding) {}

    void Snake::setLength(double len) {
        if(len <= 0) throw std::invalid_argument("Length cannot be negative");
        m_lengthMeters = len;
    }
    void Snake::setIsConstrictor(bool c) { m_isConstrictor = c; }
    void Snake::setSheddingFrequency(int days) {
        if(days <= 0) throw std::invalid_argument("Shedding frequency cannot be negative");
        m_sheddingFrequencyDays = days;
    }

    void Snake::serialize(std::ostream& os) const {
        os << "Snake "; 
        Reptile::serialize(os);
        os << " " << m_lengthMeters << " " << m_isConstrictor << " " << m_sheddingFrequencyDays;
    }

    void Snake::printDetails(std::ostream& os) const {
        Reptile::printDetails(os);
        os << " | Length: " << m_lengthMeters << "m"
           << " | Constrictor: " << (m_isConstrictor ? "Yes" : "No")
           << " | Shedding: every " << m_sheddingFrequencyDays << " days";
    }

    std::unique_ptr<Snake> Snake::fromFileStream(std::istream& is) {
        unsigned int id;
        std::string n, g, dateStr, texture;
        int a, shedding;
        double w, length;
        bool venom, heat, constrictor;
        
        if (is >> id >> n >> g >> a >> w >> dateStr >> venom >> texture >> heat >> length >> constrictor >> shedding) {
            auto snake = std::make_unique<Snake>(n, g, a, w, Date(dateStr), venom, texture, heat, length, constrictor, shedding);
            snake->forceId(id);
            return snake;
        }
        return nullptr;
    }
}