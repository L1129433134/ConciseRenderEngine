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
            ASSERT(cols > 0 && rows > 0, "error: initialize failed, empty matrix is not necessary");
            m_rows = rows;
            m_cols = cols;
            m_data = new T[m_rows * m_cols];
        };
        Matrix(std::initializer_list<T> list)
        {
            ASSERT(cols > 0 && rows > 0, "error: initialize failed, empty matrix is not necessary");
            ASSERT(list.size() == rows * cols, "error: initialize failed, sizes of list are not satisfied.");
            m_rows = rows;
            m_cols = cols;
            m_data = new T[m_rows * m_cols];

            int i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                *(m_data + i++) = *it;
            }
        }
        Matrix(const Matrix &mat)
        {
            m_rows = mat.m_rows;
            m_cols = mat.m_cols;
            m_data = new T[m_rows * m_cols];
            int m_count = m_cols * m_rows;
            for (int i = 0; i < m_count; i++)
            {
                *(m_data + i) = *(mat.m_data + i);
            }
        }
        virtual ~Matrix(){};

        std::string toString()
        {
            std::cout << m_rows << std::endl;
            std::cout << m_cols << std::endl;
            std::string retStr;
            for (int i = 0; i < m_rows; i++)
            {
                for (int j = 0; j < m_cols; j++)
                {
                    std::stringstream out;
                    std::string tempStr;
                    out << *(m_data + i * m_rows + j);
                    out >> tempStr;
                    retStr += tempStr;
                    if(j != m_cols-1)
                        retStr += " ";
                    if (j == m_cols - 1 && i != m_rows-1)
                        retStr += "\n";
                            
                }
            }
            return retStr;
        }
    };

} // namespace scmales
#endif