#pragma once
#include "IScene.h"
#include "Common/InputManager.h"
#include "Object/Player.h"
#include "Object/Enemy.h"
#include "Object/Bullet.h"
#include "Object/Object.h"
#include <vector>
class GameScene : public IScene {
public:

    GameScene();
    ~GameScene();

    void Init() override;
    void Update() override;
    void Draw() override;
    IScene* GetNextScene() override;
    int GetThisScene() override { return 1; }
    bool GetIsTransition() override { return isTransition; }

private:
    int isTransition;

    std::vector<Object*> objects; 
   
    InputManager* input = InputManager::GetInstance();

    IScene* nextScene;
};
