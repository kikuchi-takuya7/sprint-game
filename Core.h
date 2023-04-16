#pragma once
#include "Engine/GameObject.h"

//コアを管理するクラス
class Core : public GameObject
{
    int hModel_;

public:
    //コンストラクタ
    Core(GameObject* parent);

    //デストラクタ
    ~Core();

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