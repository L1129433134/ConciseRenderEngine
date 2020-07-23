#ifndef __POINT_H__
#define __POINT_H__
#include <initializer_list>
namespace scmales
{

    template <class T, int dim>
    class Point
    {
    private:
        T *m_data;
        int m_dim;

    public:
        Point(){m_data = new T[dim]};
        Point(std::initializer_list<T> list)
        {
            m_dim = dim;
            m_date = new T[dim];
            int i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                *(m_data + i++) = *it;
            }
        }
        Point(const Point &point) //复制构造函数
        {
            m_dim = dim;
            m_date = new T[dim];
            int i = 0;
            for (int i = 0; i < m_count; i++)
            {
                *(m_data + i) = *(point.m_data + i);
            }
        }
        ~Point(){};
    };
} // namespace scmales
#endif