#pragma once
#include "Engine/GameObject.h"

class PanchRight : public GameObject

{

    int hModel_;
    int limit_;
    int tmp_;

public:

    PanchRight(GameObject* parent);
    ~PanchRight();

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