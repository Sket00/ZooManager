#include "Lion.hpp"
#include <stdexcept>

namespace ws {

    Lion::Lion() : Mammal(), m_maneLength(0), m_prideSize(0), m_roarVolumeDecibels(0) {}

    Lion::Lion(const std::string& n, const std::string& g, int a, double w, const Date& d, 
              bool fur, bool aggressive,const std::string& diet, double mane, int pride, int volume)
        : Mammal(n, g, a, w, d, fur, aggressive, diet), 
          m_maneLength(mane), m_prideSize(pride), m_roarVolumeDecibels(volume) {}

    void Lion::setManeLength(double len) {
        if(len < 0) throw std::invalid_argument("Mane length cannot be negative");
        m_maneLength = len;
    }

    void Lion::setPrideSize(int size) {
        if(size < 0) throw std::invalid_argument("Pride size cannot be negative");
        m_prideSize = size;
    }

    void Lion::setRoarVolume(int vol) {
        if(vol < 0) throw std::invalid_argument("Volume cannot be negative");
        m_roarVolumeDecibels = vol;
    }

    void Lion::serialize(std::ostream& os) const {
        os << "Lion "; 
        Mammal::serialize(os);
        os << " " << m_maneLength << " " << m_prideSize << " " << m_roarVolumeDecibels;
    }

    void Lion::printDetails(std::ostream& os) const {
        Mammal::printDetails(os);
        os << " | Mane: " << m_maneLength << "cm"
           << " | Pride Size: " << m_prideSize
           << " | Roar: " << m_roarVolumeDecibels << "dB";
    }

    std::unique_ptr<Lion> Lion::fromFileStream(std::istream& is) {
        unsigned int id;
        std::string n, g, dateStr, diet;
        int a, pride, volume;
        double w, mane;
        bool fur, aggressive; 
        
        if (is >> id >> n >> g >> a >> w >> dateStr >> fur >> aggressive >> diet >> mane >> pride >> volume) {
            auto lion = std::make_unique<Lion>(n, g, a, w, Date(dateStr), fur, aggressive, diet, mane, pride, volume);
            lion->forceId(id); 
            return lion;
        }
        return nullptr;
    }
}