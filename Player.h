#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
	int hModel_;    //モデル番号
	int AhModel_;
	int panch_;

	float gravity_, velocity_;//重力と初速

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};