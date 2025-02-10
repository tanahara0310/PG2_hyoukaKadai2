#include "InputManager.h"

//==============================
// キー取得更新処理
//==============================
void InputManager::Update()
{

    // キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);
}

//==============================
// 特定のキーが押されていない状態
//==============================
int InputManager::GetNone(int key)
{

    // 特定キーが押されてないならtureを返す
    if (keys[key]) {

        return false;

    } else {
        return true;
    }
}

//==============================
// 特定のキーが押された状態
//==============================
int InputManager::GetTriger(int key)
{

    // 特定キーが押されたならtrueを返す
    if (keys[key] && !preKeys[key]) {

        return true;

    } else {
        return false;
    }
}

//==============================
// 特定のキーが押されている状態
//==============================
int InputManager::GetPress(int key)
{
    // 特定キーが押されているならtrueを返す
    if (keys[key]) {

        return true;

    } else {

        return false;
    }
}

//==============================
// 特定のキーから離れた状態
//==============================
int InputManager::GetRelease(int key)
{

    // 特定キーから離れたらtrueを返す
    if (!keys[key] && preKeys[key]) {

        return true;

    } else {

        return false;
    }
}

int InputManager::GetControl(keyState keyState, ControlKey control)
{
    switch (keyState) {
    case Triger:
        switch (control) {
        case UP:

            if (keys[DIK_W] && !preKeys[DIK_W] || keys[DIK_UP] && !preKeys[DIK_UP]) {

                return true;
            }

            break;
        case DOWN:

            if (keys[DIK_S] && !preKeys[DIK_S] || keys[DIK_DOWN] && !preKeys[DIK_DOWN]) {

                return true;
            }
            break;
        case LEFT:

            if (keys[DIK_A] && !preKeys[DIK_A] || keys[DIK_LEFT] && !preKeys[DIK_LEFT]) {

                return true;
            }
            break;
        case RIGHT:

            if (keys[DIK_D] && !preKeys[DIK_D] || keys[DIK_RIGHT] && !preKeys[DIK_RIGHT]) {

                return true;
            }
            break;
        case JUMP:

            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

                return true;
            }
            break;
        default:
            break;
        }

        break;

    case Press:

        switch (control) {
        case UP:

            if (keys[DIK_W] || keys[DIK_UP]) {

                return true;
            }

            break;
        case DOWN:

            if (keys[DIK_S] || keys[DIK_DOWN]) {

                return true;
            }
            break;
        case LEFT:

            if (keys[DIK_A] || keys[DIK_LEFT]) {

                return true;
            }
            break;
        case RIGHT:

            if (keys[DIK_D] || keys[DIK_RIGHT]) {

                return true;
            }
            break;
        case JUMP:

            if (keys[DIK_SPACE]) {

                return true;
            }
            break;
        default:
            break;
        }
        break;
    case Release:

        switch (control) {
        case UP:

            if (!keys[DIK_W] && preKeys[DIK_W] || !keys[DIK_UP] && preKeys[DIK_UP]) {

                return true;
            }

            break;
        case DOWN:

            if (!keys[DIK_S] && preKeys[DIK_S] || !keys[DIK_DOWN] && preKeys[DIK_DOWN]) {

                return true;
            }
            break;
        case LEFT:

            if (!keys[DIK_A] && preKeys[DIK_A] || !keys[DIK_LEFT] && preKeys[DIK_LEFT]) {

                return true;
            }
            break;
        case RIGHT:

            if (!keys[DIK_D] && preKeys[DIK_D] || !keys[DIK_RIGHT] && preKeys[DIK_RIGHT]) {

                return true;
            }
            break;
        case JUMP:

            if (!keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

                return true;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 0;
}
