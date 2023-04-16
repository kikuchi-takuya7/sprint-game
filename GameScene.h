#pragma once
#include "Engine/GameObject.h"

//第一ステージを管理するクラス
class GameScene : public GameObject
{

	bool tmp_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};