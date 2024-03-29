#pragma once
#include "Engine/GameObject.h"

class Panch : public GameObject

{

    int hModel_;
    int limit_; //パンチの持続時間

public:

    Panch(GameObject* parent);
    ~Panch();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;

};