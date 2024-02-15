#include <iostream>

void randomOnes(int** matrix, int width) {
    std::srand(std::time(0));

    for(int i = 0; i < width * 3; ++i) {
        int rand_row = std::rand() % width ;
        int rand_col = std::rand() % width ;

        matrix[rand_row][rand_col] = 1;
    }
}

void reverse(int* matrix, int width) {
    for(int i = 0; i <= width/2 ; i++) {
        std::swap(matrix[i], matrix[width - 1 - i]); 
    }
}

void invert(int* matrix, int width) {
    for(int i = 0; i < width; ++i) {
        if(matrix[i] == 1) { 
            matrix[i] = 0;
        } else {
            matrix[i] = 1;
        }
    }
}

int main()
{
    int width = 5;
    int height = 5;
    int** matrix = new int*[width];
    for(int i = 0; i < width; ++i) {
        matrix[i] = new int[height];
    }

    // to random initialaze matrix
    randomOnes(matrix, width);

    // print your matrix
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            std::cout << matrix[i][j] << ' ' ;
        }
        std::cout << std::endl;
    }

    std::cout << "~~~~" << std::endl;
    
    // reverse your matrix lines
    for(int i = 0; i < width; ++i) {
        reverse(matrix[i], width);
    }

    // print your reversed matrix 
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            std::cout << matrix[i][j] << ' ' ;
        }
        std::cout << std::endl;
    }

    std::cout << "~~~~" << std::endl;
    
    // invert your matrix lines
    for(int i = 0; i < width; ++i) {
        invert(matrix[i], width);
    }

    // print your matrix
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            std::cout << matrix[i][j] << ' ' ;
        }
        std::cout << std::endl;
    }

    // delete 
    for(int i = 0; i < width; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}