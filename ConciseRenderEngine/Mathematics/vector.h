#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "point.h"
#include "utils.h"
namespace scmales
{
    template <class T, int dim>
    class Vector
    {
    private:
        T *m_data;
        int m_dim;

    public:
        Vector()
        {
            m_dim = dim;
            m_data = new T[dim];
        }
        Vector(const scmales::Point<T, dim> &begin, const scmales::Point<T, dim> &end)
        {
            ASSERT(begin.dim() == end.dim(), "error: sub elements must be the same dim.");
            m_dim = begin.dim();
            m_data = new T[m_dim];

            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) = *(end.getData(i)) - *(begin.getData(i));
            }
        }
        Vector(std::initializer_list<T> list)
        {
            m_dim = list.size();
            m_data = new T[m_dim];
            int i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                *(m_data + i++) = *it;
            }
        }
        Vector(const Vector &vec) //复制构造函数
        {
            m_dim = vec.m_dim;
            m_data = new T[m_dim];
            int i = 0;
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) = *(vec.m_data + i);
            }
        }

        bool operator==(const Vector &vec)
        {
            return this->equal(vec);
        }
        bool operator!=(const Vector &vec)
        {
            return !this->equal(vec);
        }
        bool equal(const Vector &vec)
        {
            return Vector::equal(*this, vec);
        }
        static bool equal(const Vector &a, const Vector &b)
        {
            if (&a == &b)
                return true;
            if (a.m_dim != b.m_dim)
                return false;

            for (int i = 0; i < a.m_dim; i++)
            {
                if (*(a.m_data + i) != *(a.m_data + i))
                    return false;
            }
            return true;
        }
        Vector operator,(T val)
        {
            Vector temp = Vector(*this);
            *(temp.m_data + temp.m_dim++) = val;
            return temp;
        }
        Vector operator,(Vector vec)
        {
            Vector temp = Vector(*this);
            for (int i = 0; i < vec.m_dim; i++)
            {
                *(temp.m_data + temp.m_dim++) = *(vec.m_data + i);
            }
            return temp;
        }
        Vector operator+(const Vector &vec)
        {
            Vector temp = Vector(*this);
            return temp.add(vec);
        }
        Vector &add(const Vector &vec)
        {
            //必须同个维度
            ASSERT(vec.m_dim == m_dim, "error: add elements must be the same dim.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) += *(vec.m_data + i);
            }
            return *this;
        }
        Vector operator-(const Vector &vec)
        {
            Vector temp = Vector(*this);
            return temp.sub(vec);
        }
        Vector &sub(const Vector &vec)
        {
            ASSERT(vec.m_dim == m_dim, "error: sub elements must be the same dim.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) -= *(vec.m_data + i);
            }
            return *this;
        }
        Vector operator*(const T &val)
        {
            Vector temp = Vector(*this);
            return temp.mul(val);
        }
        Vector &mul(const T &val)
        {
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) *= val;
            }
            return *this;
        }
        Vector operator/(const T &val)
        {
            Vector temp = Vector(*this);
            return temp.div(val);
        }
        Vector &div(const T &val)
        {
            ASSERT(val != 0, "error: div element can't be zero.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) /= val;
            }
            return *this;
        }

        T dot(const Vector &vec1, const Vector &vec2)
        {
            ASSERT(vec1.m_dim == vec2.m_dim, "error: dot elements must be the same dim.");
            T sum = 0;
            for (int i = 0; i < vec1.m_dim; i++)
            {
                sum += *(vec1.m_data + i) * *(vec2.m_data);
            }
            return sum;
        }
        Vector cross(const Vector &vec1, const Vector &vec2)
        {
            ASSERT(vec1.m_dim == 3 && vec2.m_dim == 3, "error: cross elements must be 3-dim.");
            Vector<T, 3> tempVec;
            
            tempVec[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
            tempVec[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
            tempVec[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
                    
        }
        std::string toString()
        {
            std::string retStr;
            for (int i = 0; i < m_dim; i++)
            {
                std::stringstream out;
                std::string tempStr;
                out << *(m_data + i);
                out >> tempStr;
                retStr += tempStr;
            }
            return retStr;
        }
        virtual ~Vector()
        {
            std::cout << "delete Vector" << std::endl;
        };
    };
} // namespace scmales

#endif