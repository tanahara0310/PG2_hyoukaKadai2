#pragma once
#include "Common/InputManager.h"
#include "Common/MyMath.h"
#include "Object.h"

class Bullet;

// 弾発射インターバル
const int kShotCoolTimeInterval = 10;

// 弾の最大数
const int kMaxBullet = 10;

class Player : public Object {
public:
    Player();
    ~Player();

    void Init() override;
    void Update() override;
    void Draw() override;

    void SetPos(Vector2 setPos);

    Bullet* GetBullet(int i) { return bullet[i]; }

    InputManager* input = InputManager::GetInstance();

private:
    Bullet* bullet[kMaxBullet];

    int shotCoolTime = 0;
};
