#include "CVector.h"
#include <iostream>
int main () {
    int n = 5;
    CVector vec1;
    CVector vec(n);
    print(std::cout, vec1);
    print(std::cout, vec);
    return 0;
}
