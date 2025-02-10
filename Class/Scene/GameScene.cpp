#include "GameScene.h"
#include <vector>
// 次シーンの読み込み
#include "ResultScene.h"

void GameScene::Init()
{
    objects.clear();
    objects.push_back(new Player());
    objects.push_back(new Enemy());

    for (auto& obj : objects) {
        obj->Init();
    }

    isTransition = false;
}

GameScene::GameScene()
{
    Init();
}

GameScene::~GameScene()
{

    objects.clear();
}

void GameScene::Update()
{

    // 敵の更新
    for (auto& obj : objects) {
        obj->Update();
    }

    // 敵と弾当たり判定
    for (int i = 0; i < kMaxBullet; i++) {

        if (dynamic_cast<Player*>(objects[0])->GetBullet(i)->GetIsShot() && objects[1]->GetIsAlive()) {
            if (Distance(dynamic_cast<Player*>(objects[0])->GetBullet(i)->GetPos(), objects[1]->GetPos()) <= dynamic_cast<Player*>(objects[0])->GetBullet(i)->GetRadius() + objects[1]->GetRadius()) {
                objects[1]->SetIsAlive(false);
            }
        }
    }

    // 自機と敵の当たり判定
    if (objects[0]->GetIsAlive() && objects[1]->GetIsAlive()) {
        if (Distance(objects[0]->GetPos(), objects[1]->GetPos()) <= objects[0]->GetRadius() + objects[1]->GetRadius()) {
            objects[0]->SetIsAlive(false);
            isTransition = true;
        }
    }
}

void GameScene::Draw()
{
    for (auto& obj : objects) {
        obj->Draw();
    }
}

// 次のシーンの読み込み
IScene* GameScene::GetNextScene()
{
    return new ResultScene();
}
