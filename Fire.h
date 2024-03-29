#pragma once
#include "Engine/GameObject.h"

//炎を管理するクラス
class Fire : public GameObject
{
    int hModel_;
    int limit_; //地面に着いてからの持続
    XMFLOAT3 fireV_; //炎の向き
    XMFLOAT3 fireP_; //炎の位置

public:
    //コンストラクタ
    Fire(GameObject* parent);

    //デストラクタ
    ~Fire();

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