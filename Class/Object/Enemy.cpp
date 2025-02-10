#include "Enemy.h"

Enemy::Enemy()
{
    Init();
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
    pos = { 640.0f, 300.0f };
    velocity = { 5.0f, 0.0f };
    radius = 20.0f;
    isAlive = true;
    respawnTime = 0;
}

void Enemy::Update()
{
    if (isAlive) {
        pos.x += velocity.x;

        if (pos.x >= 1280.0f - radius || pos.x <= 0.0f + radius) {
            velocity.x *= -1.0f;
        }
    }

    respawnTime++;

    if (respawnTime >= 60) {
        isAlive = true;
        respawnTime = 0;
    }
}

void Enemy::Draw()
{
    if (isAlive) {
        Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y),
            static_cast<int>(radius), static_cast<int>(radius),
            0.0f, RED, kFillModeSolid);
    }
}

void Enemy::SetPos(Vector2 setPos)
{
    this->pos = setPos;
}