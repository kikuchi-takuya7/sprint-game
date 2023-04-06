#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class Title : public GameObject
{
	int hPict_;    //画像番号
	int opacity_;
	Text* pText_;
	int tmp_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Title(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};