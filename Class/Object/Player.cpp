#include "Player.h"
#include "Bullet.h"
#include <Novice.h>

void Player::Init()
{
    pos = { 640.0f, 500.0f };
    velocity = { 5.0f, 5.0f };
    radius = 20.0f;
    isAlive = true;

    shotCoolTime = 0;

    for (int i = 0; i < kMaxBullet; ++i) {
        bullet[i] = new Bullet();
    }
}

Player::Player()
{
    Init();
}

Player::~Player()
{

    for (int i = 0; i < kMaxBullet; ++i) {
        delete bullet[i];
        bullet[i] = nullptr;
    }
}

void Player::Update()
{

    // キー入力による移動
    if (input->GetControl(Press, UP)) {
        pos.y -= velocity.y;
    }

    if (input->GetControl(Press, DOWN)) {
        pos.y += velocity.y;
    }

    if (input->GetControl(Press, LEFT)) {
        pos.x -= velocity.x;
    }

    if (input->GetControl(Press, RIGHT)) {
        pos.x += velocity.x;
    }

    // i番目の弾を見つけ弾発射
    if (input->GetPress(DIK_SPACE)) {

        // インターバル
        if (shotCoolTime > 0) {
            shotCoolTime--;
        } else {
            shotCoolTime = kShotCoolTimeInterval;
        }

        if (shotCoolTime <= 0) {

            for (int i = 0; i < kMaxBullet; i++) {
                if (!bullet[i]->GetIsShot()) {
                    bullet[i]->SetIsShot(true);
                    bullet[i]->SetPos(pos);

                    break;
                }
            }
        }
    }

    // 弾がactiveなら更新
    for (int i = 0; i < kMaxBullet; i++) {
        if (bullet[i]->GetIsShot()) {
            bullet[i]->Update();
        }
    }
}

void Player::Draw()
{
    for (int i = 0; i < kMaxBullet; i++) {

        bullet[i]->Draw();
    }

    if (isAlive) {

        Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y),
            static_cast<int>(radius), static_cast<int>(radius),
            0.0f, GREEN, kFillModeSolid);
    }
}

void Player::SetPos(Vector2 setPos)
{
    this->pos = setPos;
}
