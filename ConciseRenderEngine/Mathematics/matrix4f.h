#ifndef __MATRIX_4F_H__
#define __MATRIX_4F_H__
#include "matrix.h"
#include "vector4f.h"

namespace scmales
{
    class Matrix4f : public Matrix<float, 4, 4> //专用于齐次坐标系下的变换矩阵
    {
    private:
        /* data */
    public:
        Matrix4f() : Matrix(){};
        Matrix4f(std::initializer_list<float> list) : Matrix(list){};
        Matrix4f(const Matrix4f &mat) : Matrix(mat){};
        ~Matrix4f(){};
        Matrix4f dot(const Matrix4f &mat)
        {
            return Matrix4f::dot(*this, mat);
        }
        static Matrix4f dot(const Matrix4f &mat1, const Matrix4f &mat2)
        {
            ASSERT(mat1.m_cols == mat2.m_rows, "error: size of two matrixes are not satisfied!");
            Matrix4f mat;
            for (int i = 0; i < mat.m_rows; i++)
            {
                for (int j = 0; j < mat.m_cols; j++)
                {
                    float sum = 0;

                    for (int k = 0; k < mat1.m_cols; k++)
                    {
                        float a = *(mat1.m_data + i * mat1.m_cols + k);
                        float b = *(mat2.m_data + k * mat2.m_cols + j);
                        sum += a * b;
                    }
                    *(mat.m_data + i * mat.m_cols + j) = sum; //i行j列的数
                }
            }
            return mat;
        }
        Vector4f dot(const Vector4f &vec)
        {
            return Matrix4f::dot(*this, vec);
        }
        static Vector4f dot(const Matrix4f &mat, const Vector4f &vec)
        {
            Vector4f retVec;
            for (int i = 0; i < 4; i++)
            {
                float sum = 0;
                for (int k = 0; k < 4; k++)
                {
                    sum += *(mat.m_data + i * mat.m_cols + k) * vec.getData(k);
                }
                retVec.setData(i, sum);
            }
            return retVec;
        }
    };

} // namespace scmales
#endif