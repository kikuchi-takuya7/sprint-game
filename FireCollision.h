#pragma once
#include "Engine/GameObject.h"

//炎の当たり判定を管理するクラス
class FireCollision : public GameObject
{
    
    XMFLOAT3 fireCP_; //fireクラスの座標を入れる

public:
    //コンストラクタ
    FireCollision(GameObject* parent);

    //デストラクタ
    ~FireCollision();

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

