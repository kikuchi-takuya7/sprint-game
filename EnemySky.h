#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemySky : public GameObject
{
    int hModel_;
    int attack_;
    int randm_;

public:
    //コンストラクタ
    EnemySky(GameObject* parent);

    //デストラクタ
    ~EnemySky();

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