#include "Class/Common/InputManager.h"
#include "Class/Scene/SceneManager.h"
#include <Novice.h>
const char kWindowTitle[] = "LC1A_16_タナハラ_コア_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // シーン管理クラスのインスタンスを生成
    SceneManager* scene = new SceneManager();
    scene->Init();

    // キー入力受付クラス
    InputManager* input = InputManager::GetInstance();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///

        // キー入力
        input->Update();

        // シーンの更新
        scene->Update();

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        // シーンの描画
        scene->Draw();

        Novice::ScreenPrintf(16, 16, "Press Transition Key : T");
        Novice::ScreenPrintf(16, 32, "Press Reset Key : R");

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
