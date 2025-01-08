// Created by stiff on 07/01/2025

#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
class CVector {
public:
	CVector();
	CVector(int& n);
	~CVector();

friend std::ostream& print(std::ostream& os, const CVector& vec){
	std::cout << vec.dim;
	for (int i = 0; i < vec.dim; ++i) {
	os << vec.Coordinates[i] << " ";
	}
	return os;
}
private:
	int dim=0;
	double* Coordinates;
};

#endif // !CVECTOR_H



// TODO: Terminar la implementación del constructor para un vector
// con números aleatorios.
