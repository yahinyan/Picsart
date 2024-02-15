#include "matrix.h"

Matrix::Matrix(const int width, const int height)
    : m_width{width}, m_height{height}, m_matrix{new Pixel *[width]}
{
    for (int i = 0; i < m_width; ++i)
    {
        m_matrix[i] = new Pixel[m_height];
    }
}

Matrix::Matrix(const Matrix &other)
    : m_width{other.m_width}, m_height{other.m_height}, m_matrix{new Pixel *[other.m_width]}
{
    for (int i = 0; i < m_width; ++i)
    {
        m_matrix[i] = new Pixel[m_height];
        for (int j = 0; j < m_height; ++j)
        {
            m_matrix[i][j] = other.m_matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&other)
    : m_width{std::exchange(other.m_width, 0)}, m_height{std::exchange(other.m_height, 0)}, m_matrix{std::exchange(other.m_matrix, nullptr)}
{
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        for (int i = 0; i < m_width; ++i)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;

        m_width = other.m_width;
        m_height = other.m_height;
        for (int i = 0; i < m_width; ++i)
        {
            m_matrix[i] = new Pixel[m_height];
            for (int j = 0; j < m_height; ++j)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other)
{
    if (this != &other)
    {
        for (int i = 0; i < m_width; ++i)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
        m_width = std::exchange(other.m_width, 0);
        m_height = std::exchange(other.m_height, 0);
        m_matrix = std::exchange(other.m_matrix, nullptr);
    }
    return *this;
}

Matrix::~Matrix()
{
    for (int i = 0; i < m_width; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

void Matrix::print() const
{
    for (int i = 0; i < m_width; ++i)
    {
        for (int j = 0; j < m_height; ++j)
        {
            m_matrix[i][j].print();
        }
        std::cout << std::endl;
    }
}

void Matrix::newValue(int index_i, int index_j, int r, int g, int b)
{
    if (index_i < 0 || index_i >= m_width || index_j < 0 || index_j >= m_height) {
        throw std::out_of_range("Index out of range");
    }
    m_matrix[index_i][index_j].value(r, g, b);
}

Pixel& Matrix::getValue(int index_i, int index_j) {
    if(index_i < 0 || index_i >= m_width || index_j < 0 || index_j >= m_height) {
        throw std::out_of_range("Index out of range");
    }
    return m_matrix[index_i][index_j];
}

void Matrix::printValue(int index_i, int index_j) {
    if(index_i < 0 || index_i >= m_width || index_j < 0 || index_j >= m_height) {
        throw std::out_of_range("Index out of range");
    }
    m_matrix[index_i][index_j].print();
}