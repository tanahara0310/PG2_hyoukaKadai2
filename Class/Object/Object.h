#pragma once
#include "Common/MyMath.h"
#include <Novice.h>

class Object {

public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual Vector2 GetPos() { return pos; }

    virtual float GetRadius() { return radius; }
   virtual bool GetIsAlive() { return isAlive; }

   void SetIsAlive(int set) {
       isAlive = set;
   }

protected:
    Vector2 pos;
    Vector2 screenPos;

    Vector2 startPos;
    Vector2 endPos;

    Vector2 direction;

    Matrix3x3 worldMatrix;

    Vector2 velocity;

    Vector2 acceleration;

    Vector2 leftTop;
    Vector2 rightTop;
    Vector2 leftBottom;
    Vector2 rightBottom;

    Vector2 localLeftTop;
    Vector2 localRightTop;
    Vector2 localLeftBottom;
    Vector2 localRightBottom;

    Vector2 screenLeftTop;
    Vector2 screenRightTop;
    Vector2 screenLeftBottom;
    Vector2 screenRightBottom;

    Vector2 scale;

    Vector2 size;

    float radius;

    float angle;
    float alpha;
    // 質量
    float mass;
    // 摩擦係数
    float friction;
    // 反発係数
    float restitution;

    bool isAlive;
    bool isActive;

    int tmpTexture = Novice::LoadTexture("white1x1.png");
};
