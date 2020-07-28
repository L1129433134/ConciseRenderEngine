#include <iostream>
#include <string>
#include <initializer_list>
#include "matrix.h"

int main()
{
    std::initializer_list<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    scmales::Matrix<int, 3, 3> p(arr);

    std::cout << p.toString() << std::endl;
    return 0;
}