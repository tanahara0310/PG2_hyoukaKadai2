#include "SceneManager.h"
#include "Common/InputManager.h"

// シーン読み込み
 #include "TitleScene.h"
#include "GameScene.h"
 #include "ResultScene.h"

void SceneManager::Init()
{

    scene = new TitleScene();
   /* scene = new GameScene();
    scene = new ResultScene();*/

    // シーンの初期化
    scene->Init();
}

void SceneManager::Update()
{
    if (input->GetTriger(DIK_R)) {
        scene->Init();
    }

    scene->Update();

    if (input->GetTriger(DIK_T)) {

        // シーンの遷移
        IScene* temp = scene->GetNextScene();

        // 別のシーンだったら次のシーンへ
        if (temp) {
            delete scene;
            scene = temp;
            scene->Init();
        }
    }
}

void SceneManager::Draw()
{

    scene->Draw();
}
