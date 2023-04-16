#pragma once
#include "Engine/GameObject.h"

//第二ステージを管理するクラス
class GameSceneSecond : public GameObject
{

	bool tmp_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameSceneSecond(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};