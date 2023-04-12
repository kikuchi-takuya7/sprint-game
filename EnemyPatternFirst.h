#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemyPatternFirst : public GameObject
{
    int x_;
    int count_;
    int hModel_;
    int epattern_;
    int height_;
    int** table_;
    bool tmp_;

public:
    //コンストラクタ
    EnemyPatternFirst(GameObject* parent);

    //デストラクタ
    ~EnemyPatternFirst();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};