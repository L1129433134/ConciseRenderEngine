#include <iostream>
#include <string>
#include <initializer_list>
#include "matrix4f.h"
#include "vector4f.h"
int main()
{
    std::initializer_list<float> arr = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
    std::initializer_list<float> arr1 = {1, 2, 3, 4};

    scmales::Matrix4f p1(arr);
    scmales::Matrix4f p2(arr);
    std::cout << p1.toString() << std::endl;
    std::cout << p2.toString() << std::endl;

    auto a = scmales::Matrix4f::dot(p1, p2);
    std::cout << a.toString() << std::endl;

    scmales::Vector4f vec(arr1);
    auto b = scmales::Matrix4f::dot(p1, vec);
    std::cout << b.toString() << std::endl;

    return 0;
}