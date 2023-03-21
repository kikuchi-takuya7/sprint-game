#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class LeftEnemy : public GameObject
{
    int hModel_;

public:
    //コンストラクタ
    LeftEnemy(GameObject* parent);

    //デストラクタ
    ~LeftEnemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};