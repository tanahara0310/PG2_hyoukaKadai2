#pragma once
#include <Novice.h>

enum ControlKey {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    JUMP,
};

enum keyState {
    Triger,
    Press,
    Release,
};

class InputManager final {
public:
    // シングルトン
    static InputManager* GetInstance()
    {
        static InputManager instance;
        return &instance;
    }

    // キー取得更新処理
    void Update();

    //キー入力取得
    int GetNone(int key);
    int GetTriger(int key);
    int GetPress(int key);
    int GetRelease(int key);

    /// <summary>
    /// キーまとめ変数
    /// </summary>
    /// <param name="keyState">判定方法</param>
    /// <param name="control">操作種類</param>
    /// <returns>押されている = ture</returns>
    int GetControl(keyState keyState, ControlKey control);

private:
    // キー入力結果を受け取る
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // コンストラクタをプライベートに
    InputManager() = default;
    ~InputManager() = default;

    // コピーコンストラクタを無効
    InputManager(const InputManager&) = delete;
    // 代入演算子の無効
    InputManager& operator=(const InputManager&) = delete;
};