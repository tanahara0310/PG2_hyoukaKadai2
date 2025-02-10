#include "MyMath.h"
#include <assert.h>
#include <math.h>

//======================================
// その他数学計算用の関数
//======================================

// 内積
float Dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

// 外積
float Cross(Vector2 a, Vector2 b)
{
    return a.x * b.y - a.y * b.x;
}

//
float Length(Vector2 a)
{
    return sqrtf(powf(a.x, 2.0f) + powf(a.y, 2.0f));
}

unsigned int FadeColor(unsigned int color, float alpha)
{
    unsigned int rgbColor = color & 0xFFFFFF00;
    return rgbColor | static_cast<unsigned int>(alpha * 255);
}

// ２点間の距離
float Distance(Vector2 pos1, Vector2 pos2)
{
    return sqrtf(powf(pos1.x - pos2.x, 2.0f) + powf(pos1.y - pos2.y, 2.0f));
}

//======================================
// 行列用の関数
//======================================

#pragma region 行列関数

// 正射影行列
Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom)
{

    Matrix3x3 result;

    result.m[0][0] = 2.0f / (right - left);
    result.m[0][1] = 0.0f;
    result.m[0][2] = 0.0f;
    result.m[1][0] = 0.0f;
    result.m[1][1] = 2.0f / (top - bottom);
    result.m[1][2] = 0.0f;
    result.m[2][0] = (left + right) / (left - right);
    result.m[2][1] = (top + bottom) / (bottom - top);
    result.m[2][2] = 1.0f;

    return result;
}

// ビューポート行列
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height)
{

    Matrix3x3 result;

    result.m[0][0] = width / 2.0f;
    result.m[0][1] = 0.0f;
    result.m[0][2] = 0.0f;
    result.m[1][0] = 0.0f;
    result.m[1][1] = -(height / 2.0f);
    result.m[1][2] = 0.0f;
    result.m[2][0] = left + (width / 2.0f);
    result.m[2][1] = top + (height / 2.0f);
    result.m[2][2] = 1.0f;

    return result;
}

// アフィン変換
Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate)
{

    Matrix3x3 result;

    result.m[0][0] = scale.x * cosf(theta);
    result.m[0][1] = scale.x * sinf(theta);
    result.m[0][2] = 0.0f;
    result.m[1][0] = -scale.y * sinf(theta);
    result.m[1][1] = scale.y * cosf(theta);
    result.m[1][2] = 0.0f;
    result.m[2][0] = translate.x;
    result.m[2][1] = translate.y;
    result.m[2][2] = 1.0f;

    return result;
}

// 3×3行列同士の積
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2)
{
    Matrix3x3 result;

    // 行列の各要素を直接計算
    result.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0];
    result.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1];
    result.m[0][2] = matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2];

    result.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0];
    result.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1];
    result.m[1][2] = matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2];

    result.m[2][0] = matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0];
    result.m[2][1] = matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1];
    result.m[2][2] = matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2];

    return result;
}

// ２次元ベクトルを同次座標に変換
Vector2 Transform(Vector2 vector, Matrix3x3 matrix)
{
    Vector2 result;

    result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
    result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
    float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];

    assert(w != 0.0f);

    result.x /= w;
    result.y /= w;

    return result;
}

// 逆行列
Matrix3x3 InversMatrix(Matrix3x3 matrix)
{
    // 行列式の計算
    float determinant = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2]) + (matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0]) + (matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1]) - (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0])
        - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]) - (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);

    assert(determinant != 0.0f);

    // 逆行列の計算
    Matrix3x3 inverse;
    float invDet = 1.0f / determinant;

    inverse.m[0][0] = (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) * invDet;
    inverse.m[0][1] = -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]) * invDet;
    inverse.m[0][2] = (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) * invDet;

    inverse.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]) * invDet;
    inverse.m[1][1] = (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) * invDet;
    inverse.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]) * invDet;

    inverse.m[2][0] = (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) * invDet;
    inverse.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]) * invDet;
    inverse.m[2][2] = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) * invDet;

    return inverse;
}

#pragma endregion