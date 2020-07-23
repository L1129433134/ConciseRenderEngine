#include "point.h"
#include <iostream>
#include <initializer_list>
int main()
{
    std::initializer_list<int> arr = {1, 2, 3};
    scmales::Point<int, 3> p1(arr);
    scmales::Point<int, 3> p2(arr);
    std::cout << scmales::Point<int, 3>::equal(p1, p2) << std::endl;
    if(p1 == p2)
        std::cout << "Yes" << std::endl;
    else
        std::cout<< "None" << std::endl;
    
    return 0;
}