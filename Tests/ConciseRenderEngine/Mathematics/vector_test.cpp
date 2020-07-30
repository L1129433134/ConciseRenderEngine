#include "vector4f.h"
#include <iostream>
#include <initializer_list>
int main()
{
    std::initializer_list<int> arr = {1, 2, 3};
    std::initializer_list<int> arr1 = {1, 2, 3, 4};

    ////向量测试
    scmales::Vector<int, 3> p4(arr); //(1, 2, 3)
    scmales::Vector<int, 3> p5(arr); //(1, 2, 3)
    scmales::Vector<int, 4> p6(arr1); //(1, 2, 3, 4)
    std::cout << scmales::Vector<int, 3>::equal(p4, p5) << std::endl; //点相等
    if (p4 == p5)                                                     //点相等
        std::cout << "Yes, vectors are equal." << std::endl;
    else
        std::cout << "No, vectors are not equal." << std::endl;
    auto e = scmales::Vector<int, 3>::dot(p4, p5); //点乘
    std::cout<< e << std::endl;

    auto f = scmales::Vector<int, 3>::cross(p4, p5); //叉乘
    std::cout<< f.toString() << std::endl;
    return 0;
}