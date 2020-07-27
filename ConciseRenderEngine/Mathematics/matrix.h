#ifndef __MATRIX_H__
#define __MATRIX_H__
#include "utils.h"
#include <initializer_list>
#include <string>
#include <sstream>
#include <iostream>

namespace scmales
{
    template <typename T, int rows, int cols>
    class Matrix
    {
    private:
        /* 行主序存储 */
        int m_rows;
        int m_cols;
        int *m_data;

    public:
        Matrix()
        {
            m_rows = rows;
            m_cols = cols;
            m_data = new T[m_rows * m_cols];
        };
        Matrix(std::initializer_list<T> list)
        {
            ASSERT(list.size() == m_rows*m_cols, "error: initialize failed, sizes of list are not satisfied.");
            int i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                *(m_data + i++) = *it;
            }
        }
        ~Matrix();
    };

} // namespace scmales
#endif