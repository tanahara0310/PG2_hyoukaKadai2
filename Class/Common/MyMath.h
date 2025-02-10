#pragma once

struct Vector2 {

    float x;
    float y;

    Vector2 operator+(const Vector2& other) { return { x + other.x, y + other.y }; }
    Vector2 operator-(const Vector2& other) { return { x - other.x, y - other.y }; }
    Vector2 operator*(const Vector2& other) { return { x * other.x, y * other.y }; }
    Vector2 operator/(const Vector2& other) { return { x / other.x, y / other.y }; }
    Vector2 operator=(const Vector2& other) { return { x = other.x, y = other.y }; }
    Vector2 operator+=(const Vector2& other) { return { x += other.x, y += other.y }; }
    Vector2 operator-=(const Vector2& other) { return { x -= other.x, y -= other.y }; }
    Vector2 operator*=(const Vector2& other) { return { x *= other.x, y *= other.y }; }
    Vector2 operator/=(const Vector2& other) { return { x /= other.x, y /= other.y }; }
};

struct Matrix2x2 {
    float m[2][2];
};

struct Matrix3x3 {
    float m[3][3];
};

//======================================
// その他数学計算用の関数
//======================================

// 内積
float Dot(Vector2 a, Vector2 b);

// 外積
float Cross(Vector2 a, Vector2 b);

// 長さ
float Length(Vector2 a);

// 透明度の変化
unsigned int FadeColor(unsigned int color, float alpha);

//当たり判定用
float Distance(Vector2 pos1, Vector2 pos2);

//=====================================
// 行列用関数
//=====================================

// 正射影行列
Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

// ビューポート行列
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);

// アフィン変換
Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate);

// 3x3同士の積
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

// 3x3の逆行列
Matrix3x3 InversMatrix(Matrix3x3 matrix);

// 座標変換
Vector2 Transform(Vector2 vector, Matrix3x3 matrix);