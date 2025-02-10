#pragma once
#include "Common/MyMath.h"
#include "Object.h"

//const int kMaxEnemy = 2;

class Enemy : public Object {
public:

    Enemy();
    ~Enemy();

    void Init() override;
    void Update() override;
    void Draw() override;

    void SetPos(Vector2 setPos);

private:

    int respawnTime = 0;
};
