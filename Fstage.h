#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Fstage : public GameObject
{
    int x_;
    int count_;
    int hModel_;
    int epattern_;
    int height_;
    int** table_;

public:
    //コンストラクタ
    Fstage(GameObject* parent);

    //デストラクタ
    ~Fstage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};