#include "Reptile.hpp"
#include <stdexcept>

namespace ws {

    Reptile::Reptile() : Animal(), m_isVenomous(false), m_scaleTexture("Smooth"), m_requiresHeatLamp(true) {}

    Reptile::Reptile(const std::string& n, const std::string& g, int a, double w, const Date& d, 
                     bool venom, const std::string& texture, bool heat)
        : Animal(n, g, a, w, d), m_isVenomous(venom), m_scaleTexture(texture), m_requiresHeatLamp(heat) {}

    void Reptile::setIsVenomous(bool v) { m_isVenomous = v; }
    void Reptile::setScaleTexture(const std::string& texture) {
        if(texture.empty()) throw std::invalid_argument("Texture cannot be empty");
        m_scaleTexture = texture;
    }
    void Reptile::setRequiresHeatLamp(bool h) { m_requiresHeatLamp = h; }

    void Reptile::serialize(std::ostream& os) const {
        Animal::serialize(os);
        os << " " << m_isVenomous << " " << m_scaleTexture << " " << m_requiresHeatLamp;
    }

    void Reptile::printDetails(std::ostream& os) const {
        Animal::printDetails(os);
        os << " | Venomous: " << (m_isVenomous ? "Yes" : "No")
           << " | Scales: " << m_scaleTexture
           << " | Heat Lamp: " << (m_requiresHeatLamp ? "Required" : "Not Required");
    }
}