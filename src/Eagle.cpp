#include "Eagle.hpp"
#include <stdexcept>

namespace ws {

    Eagle::Eagle() : Bird(), m_visionRangeMeters(0), m_divingSpeedKmh(0), m_isTrained(false) {}

    Eagle::Eagle(const std::string& n, const std::string& g, int a, double w, const Date& d, 
                 double vision, double speed, bool trained)
        : Bird(n, g, a, w, d, 2.3, true, "Yellow"), 
          m_visionRangeMeters(vision), m_divingSpeedKmh(speed), m_isTrained(trained) {}

    void Eagle::setVisionRange(double range) {
        if(range < 0) throw std::invalid_argument("Vision range cannot be negative");
        m_visionRangeMeters = range;
    }
    void Eagle::setDivingSpeed(double speed) {
        if(speed < 0) throw std::invalid_argument("Speed cannot be negative");
        m_divingSpeedKmh = speed;
    }
    void Eagle::setIsTrained(bool trained) { m_isTrained = trained; }

    void Eagle::serialize(std::ostream& os) const {
        os << "Eagle "; 
        Bird::serialize(os);
        os << " " << m_visionRangeMeters << " " << m_divingSpeedKmh << " " << m_isTrained;
    }

    void Eagle::printDetails(std::ostream& os) const {
        Bird::printDetails(os);
        os << " | Vision: " << m_visionRangeMeters << "m"
           << " | Dive Speed: " << m_divingSpeedKmh << "km/h"
           << " | Trained: " << (m_isTrained ? "Yes" : "No");
    }

    std::unique_ptr<Eagle> Eagle::fromFileStream(std::istream& is) {
        unsigned int id;
        std::string n, g, dateStr, beak;
        int a;
        double w, wings, vision, speed;
        bool fly, trained;
        
        if (is >> id >> n >> g >> a >> w >> dateStr >> wings >> fly >> beak >> vision >> speed >> trained) {
            auto eagle = std::make_unique<Eagle>(n, g, a, w, Date(dateStr), vision, speed, trained);
            eagle->forceId(id);
            return eagle;
        }
        return nullptr;
    }
}