#include "Bullet.h"

// コンストラクタ
Bullet::Bullet()
{
    Init();
}

void Bullet::Init()
{

    pos = { 0.0f, 0.0f };
    velocity = { 5.0f, 5.0f };
    radius = 10.0f;

    

    isShot = false;
}

void Bullet::Update()
{

    // 弾が打たれている場合
    if (isShot) {
        pos.y -= velocity.y;

        if (pos.y <= 0.0f + radius) {
            isShot = false;
        }
    }
}

void Bullet::Draw()
{

    if (isShot) {
        Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y),
            static_cast<int>(radius), static_cast<int>(radius),
            0.0f, RED, kFillModeSolid);
    }
}

void Bullet::SetPos(Vector2 setPos)
{
    this->pos = setPos;
}

void Bullet::SetIsShot(bool setIsShot)
{
    this->isShot = setIsShot;
}
