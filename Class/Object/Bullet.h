#pragma once
#include "Common/MyMath.h"
#include "Object.h"

class Bullet : public Object {
public:
    Bullet();

    void Init() override;
    void Update() override;
    void Draw() override;

    void SetPos(Vector2 setPos);

    bool GetIsShot() { return isShot; }
    void SetIsShot(bool setIsShot);

private:
    bool isShot;
};
