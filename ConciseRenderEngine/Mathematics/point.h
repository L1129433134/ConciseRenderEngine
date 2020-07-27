#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "utils.h"
// #include "vector.h"
namespace scmales
{
    template <class T, int dim>
    class Point
    {
    private:
        T *m_data;
        int m_dim;

    public:
        Point()
        {
            m_dim = dim;
            m_data = new T[m_dim];
        }
        Point(std::initializer_list<T> list)
        {
            m_dim = dim;
            m_data = new T[m_dim];
            int i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                *(m_data + i++) = *it;
            }
        }
        Point(const Point &point) //复制构造函数
        {
            m_dim = point.m_dim;
            m_data = new T[m_dim];
            int i = 0;
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) = *(point.m_data + i);
            }
        }
        // int dim()
        // {
        //     return m_dim;
        // }
        T getData(int i)
        {
            ASSERT(i < m_dim, "error: out of boundary");

            return *(m_data + i);
        }
        bool operator==(const Point &point)
        {
            return this->equal(point);
        }
        bool operator!=(const Point &point)
        {
            return !this->equal(point);
        }
        bool equal(const Point &point)
        {
            return Point::equal(*this, point);
        }
        static bool equal(const Point &a, const Point &b)
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
        Point operator,(T val)
        {
            Point temp = Point(*this);
            *(temp.m_data + temp.m_dim++) = val;
            return temp;
        }
        Point operator,(Point point)
        {
            Point temp = Point(*this);
            for (int i = 0; i < point.m_dim; i++)
            {
                *(temp.m_data + temp.m_dim++) = *(point.m_data + i);
            }
            return temp;
        }
        Point operator+(const Point &point)
        {
            Point temp = Point(*this);
            return temp.add(point);
        }
        Point &add(const Point &point)
        {
            //必须同个维度
            ASSERT(point.m_dim == m_dim, "error: add elements must be the same dim.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) += *(point.m_data + i);
            }
            return *this;
        }

        // scmales::Vector operator-(const Point &point)
        // {
        //     ASSERT(point.m_dim == m_dim, "error: sub elements must be the same dim.");
        //     Vector temp(point, *this);

        //     return temp;
        // }

        Point operator-(const Point &point)
        {
            Point temp = Point(*this);
            return temp.sub(point);
        }
        Point &sub(const Point &point)
        {
            ASSERT(point.m_dim == m_dim, "error: sub elements must be the same dim.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) -= *(point.m_data + i);
            }
            return *this;
        }
        Point operator*(const T &val)
        {
            Point temp = Point(*this);
            return temp.mul(val);
        }
        Point &mul(const T &val)
        {
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) *= val;
            }
            return *this;
        }
        Point operator/(const T &val)
        {
            Point temp = Point(*this);
            return temp.div(val);
        }
        Point &div(const T &val)
        {
            ASSERT(val != 0, "error: div element can't be zero.");
            for (int i = 0; i < m_dim; i++)
            {
                *(m_data + i) /= val;
            }
            return *this;
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

        ~Point()
        {
            std::cout << "delete Point" << this << std::endl;
        };
    };
} // namespace scmales

#endif