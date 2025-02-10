#pragma once
class IScene {
public:
    // コンストラクタとデストラクタ定義
    IScene() = default;
    virtual ~IScene() = default;

    // 初期化、更新、描画
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    // ゲームシーン取得
    virtual IScene* GetNextScene() = 0;
    virtual int GetThisScene() = 0;

    // シーン遷移しようとしているか
    virtual bool GetIsTransition() = 0;
};
