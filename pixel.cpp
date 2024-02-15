#include "pixel.h"

bool Pixel::check(int r, int g, int b) {
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return false;
    }
    return true;
}
// Pixel::Pixel() 
//     : m_r{}
//     , m_g{}
//     , m_b{}
// {}

Pixel::Pixel(const int r, const int g, const int b) {
    if(!(check(r, g, b))) {
       throw std::out_of_range("The range must be between 0 and 255");
    }
    m_r = r;
    m_g = g;
    m_b = b;
}

Pixel::Pixel(const Pixel &other) 
    : m_r{other.m_r}
    , m_g{other.m_g}
    , m_b{other.m_b} 
{}

Pixel::Pixel(Pixel &&other) 
    : m_r{std::exchange(other.m_r, 0)}
    , m_g{std::exchange(other.m_g, 0)}
    , m_b{std::exchange(other.m_b, 0)}
{}

Pixel& Pixel::operator=(const Pixel &other) {
    if(this != &other) {
        m_r = other.m_r;
        m_g = other.m_g;
        m_b = other.m_b;
    }
    return *this;
}

Pixel& Pixel::operator=(Pixel &&other) {
    if(this != &other) {
        m_r = std::move(other.m_r);
        m_g = std::move(other.m_g);
        m_b = std::move(other.m_b);
    }
    return *this;
}

Pixel::~Pixel() 
{}

void Pixel::print() const{ 
    std::cout << '('<< m_r << ", " << m_g << ", " << m_b << ")   " ;
}

void Pixel::value(int r, int g, int b) {
    m_r = r;
    m_g = g;
    m_b = b;
}

