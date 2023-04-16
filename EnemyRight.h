#pragma once
#include "Engine/GameObject.h"

//右からくる敵を管理するクラス
class EnemyRight : public GameObject
{
    int hModel_;

public:
    //コンストラクタ
    EnemyRight(GameObject* parent);

    //デストラクタ
    ~EnemyRight();

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