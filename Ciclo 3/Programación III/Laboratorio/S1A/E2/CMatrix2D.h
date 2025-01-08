#ifndef CMATRIX2D_H
#define CMATRIX2D_H
#include "CVector.h"
#include <iostream>
class CMatrix {
public:
    CMatrix();
    CMatrix(int n);
    CMatrix(int n, int m);
    void print(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; i < cols; ++i) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    CMatrix(CVector matrix, int n);
    ~CMatrix();

private:
    int rows;
    int cols;
    int** matrix;
};




#endif // !CMATRIX2D_H
