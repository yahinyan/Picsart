#ifndef MATRIX_H
#define MATRIX_H
#include "pixel.h"
#include <iostream>

class Matrix {
public:
    Matrix(const int width = 0, const int height = 0);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other);
    ~Matrix();

    void print() const;
    void newValue(int index_i, int index_j, int r, int g, int b);
    Pixel& getValue(int index_i, int index_j);
    void printValue(int index_i, int index_j);
private:
    int m_width;
    int m_height;
    Pixel** m_matrix;
};

#endif // MATRIX_H