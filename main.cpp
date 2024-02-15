#include "pixel.h"
#include "matrix.h"

int main() {
    Pixel object;
    object.print();
    Pixel image{3, 99, 44};
    image.print();
    std::cout << std::endl;
    Matrix ob(3, 3);
    ob.print();
    std::cout << std::endl;
    ob.newValue(0, 0, 255, 255, 255);
    ob.print();
    std::cout << std::endl;
    ob.printValue(0, 0);
    Pixel image1{99, 255, 555};
}