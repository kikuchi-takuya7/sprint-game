#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
	int hModel_;    //モデル番号
	int panch_; //パンチのクールダウン
	int fire_; //fireのクールダウン
	bool jump_; //ジャンプは一回だけ

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

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;

	void Cooldown();
};