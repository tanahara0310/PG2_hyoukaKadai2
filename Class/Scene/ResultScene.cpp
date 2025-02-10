#include "ResultScene.h"
#include <Novice.h>

// 次のシーンの読み込み
#include "TitleScene.h"

ResultScene::ResultScene()
{
    Init();
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{

    pos = { 640.0f, 360.0f };
}

void ResultScene::Update()
{
}

void ResultScene::Draw()
{
    Novice::ScreenPrintf(static_cast<int>(pos.x), static_cast<int>(pos.y), "ResultScene");
    
}

IScene* ResultScene::GetNextScene()
{
    return new TitleScene();
}
