#include "CMatrix2D.h"
#include <cstdlib>

CMatrix::CMatrix() : CMatrix(3,3){
}

CMatrix::CMatrix(int n) : CMatrix(n,n){
}

CMatrix::CMatrix(int n, int m) : rows(n), cols(m){
    matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j]=rand()%10;
        }
    }
}

CMatrix::CMatrix(CVector mat, int n){
    rows = 3;
    cols = n;
    matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(i == 0){
                matrix[i][j]=mat.Coordinates[0];
            }
        }
    }
}
CMatrix::~CMatrix() {

}
