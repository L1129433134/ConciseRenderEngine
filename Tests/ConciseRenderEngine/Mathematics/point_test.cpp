#include "point.h"
#include <iostream>
#include <initializer_list>
int main()
{
    std::initializer_list<int> arr = {1, 2, 3};
    std::initializer_list<int> arr1 = {1, 2, 3, 4};

    ///////点测试
    scmales::Point<int, 3> p1(arr);
    scmales::Point<int, 3> p2(arr);
    scmales::Point<int, 4> p3(arr1);

    std::cout << scmales::Point<int, 3>::equal(p1, p2) << std::endl; //点相等
    // std::cout << typeid(p1).name() << std::endl;
    // std::cout << typeid(p2).name() << std::endl;
    if (p1 == p2) //点相等
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    auto a = p1.mul(10); //点相乘
    std::cout << p1.toString() << std::endl;

    auto b = (p1, 2); //点和值组成新点//()会生成两个临时变量，所以还会调用析构函数
    std::cout << b.toString() << std::endl;

    auto c = (p1, p2); //点和点组成新点
    std::cout << c.toString() << std::endl;

    auto d = p1 + p2; //点加点
    std::cout << d.toString() << std::endl;
    return 0;
}