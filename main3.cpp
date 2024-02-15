#include <iostream>

void sinkIsland(int i, int j, int** matrix, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col ) {
        return;
    }
    if(matrix[i][j] == 0) {
        return;
    }
    matrix[i][j] = 0;
    sinkIsland(i + 1, j, matrix, row, col);
    sinkIsland(i , j - 1, matrix, row, col);
    sinkIsland(i - 1, j, matrix, row, col);
    sinkIsland(i, j + 1, matrix, row, col);
}

int count_of_islands(int** matrix, int row, int col) {
    int count = 0;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(matrix[i][j] == 1) {
                ++count;
                sinkIsland(i, j, matrix, row, col);
            }
        }
    }
    return count;
}


int main() {
    int row = 0;
    int col = 0;
    std::cout << "Input row & col for your matrix: ";
    std::cin >> row >> col;

    int** matrix = new int*[row];
    for(int i = 0; i < row; ++i) {
        matrix[i] = new int[col];
    }    

    std::cout << "~~~ Input your matrix elements ~~~" << std::endl;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Count: " << count_of_islands(matrix, row, col);

    for(int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}