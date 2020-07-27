#include "point.h"
#include "vector.h"
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

    ////向量测试
    scmales::Vector<int, 3> p4(arr); //(1, 2, 3)
    scmales::Vector<int, 3> p5(arr); //(1, 2, 3)
    scmales::Vector<int, 4> p6(arr1); //(1, 2, 3, 4)
    std::cout << scmales::Vector<int, 3>::equal(p4, p5) << std::endl; //点相等
    if (p4 == p5)                                                     //点相等
        std::cout << "Yes, vector equal." << std::endl;
    else
        std::cout << "No, vector not equal." << std::endl;
    auto e = scmales::Vector<int, 3>::dot(p4, p5); //点乘
    std::cout<< e << std::endl;

    auto f = scmales::Vector<int, 3>::cross(p4, p5); //叉乘
    std::cout<< f.toString() << std::endl;
    return 0;
}