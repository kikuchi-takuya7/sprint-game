#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemyPatternSecond : public GameObject
{
    int x_; //CSVの一列目から順番に読み取る為の変数
    int count_; //毎フレームのカウント
    int hModel_;
    int epattern_; //enemy pattern 敵の最大数
    int height_; //行数が難行あるか
    int** table_; //ポインタ配列にCSVデータを入れる
    bool tmp_; //クリアしたかどうか

public:
    //コンストラクタ
    EnemyPatternSecond(GameObject* parent);

    //デストラクタ
    ~EnemyPatternSecond();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};