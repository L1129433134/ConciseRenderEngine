#ifndef __VECTOR_4F_H__
#define __VECTOR_4F_H__
#include "vector.h"
namespace scmales{
class Vector4f:public Vector<float, 4>  //齐次坐标系中的点
{
private:
    /* data */
public:
    Vector4f():Vector(){};
    Vector4f(std::initializer_list<float> list):Vector(list){};
    Vector4f(const Vector4f &vec):Vector(vec){};

    ~Vector4f(){};
};
}//scmales
#endif