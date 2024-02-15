#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <stdexcept>

class Pixel {
public:
    //Pixel();
    Pixel(const int r = 0, const int g = 0, const int b = 0);
    Pixel(const Pixel& other);
    Pixel(Pixel&& other);
    Pixel& operator=(const Pixel& other);
    Pixel& operator=(Pixel&& other);
    ~Pixel();

    void print() const;
    void value(int r = 0, int g = 0, int b = 0);

private:
    bool check(int r, int g, int b);
    int m_r;
    int m_g;
    int m_b;
};
#endif // PIXEL_H