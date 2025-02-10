#pragma once
#include "Common/MyMath.h"
#include "IScene.h"
class ResultScene : public IScene {
public:

    ResultScene();
    ~ResultScene();

    void Init() override;
    void Update() override;
    void Draw() override;
    IScene* GetNextScene() override;
    int GetThisScene() override { return 2; }
    bool GetIsTransition() override { return isTransition; }

private:
    bool isTransition;

    Vector2 pos;
};
