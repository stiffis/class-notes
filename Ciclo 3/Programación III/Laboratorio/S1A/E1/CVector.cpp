#include "CVector.h"
#include <iostream>
CVector::CVector():dim(3){
    Coordinates = new double[dim]{0,0,0};
}
CVector::CVector(int& n) {
    dim = n;
    Coordinates = new double[dim];
    for (int i = 0; i < dim; ++i) {
        Coordinates[i]=0.0;
    }
}

CVector::~CVector() {
    std::cout << "Deleting Vector" << std::endl;
    delete[] Coordinates;
}

