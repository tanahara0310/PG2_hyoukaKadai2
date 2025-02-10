#include "TitleScene.h"
#include <Novice.h>

// シーンの読み込み
#include "GameScene.h"

TitleScene::TitleScene()
{
    Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
    pos = { 640.0f, 360.0f };
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{

    Novice::ScreenPrintf(static_cast<int>(pos.x), static_cast<int>(pos.y), "TitleScene");
}

IScene* TitleScene::GetNextScene()
{
    return new GameScene();
}
