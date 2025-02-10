#pragma once
#include "Common/InputManager.h"
#include "IScene.h"

class SceneManager {
public:



    // 初期化、更新、描画
    void Init();
    void Update();
    void Draw();

private:
    int gameStage;

    // キー入力受付クラス
    InputManager* input = InputManager::GetInstance();

    // シーン管理用ポインタ
    IScene* scene;
};
