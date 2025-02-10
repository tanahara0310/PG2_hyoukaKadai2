#pragma once
#include "IScene.h"
#include "Common/MyMath.h"
class TitleScene:public IScene{
public:

    TitleScene();
    ~TitleScene();
    void Init() override;
    void Update() override;
    void Draw() override;
    IScene* GetNextScene() override;
    int GetThisScene() override { return 0; }
    bool GetIsTransition() override { return isTransition; }

private:

    bool isTransition;

    Vector2 pos;
};
