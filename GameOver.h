#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//ゲームオーバーシーンを管理するクラス
class GameOver : public GameObject
{

	int hPict_;    //画像番号
	int opacity_; //爆発を徐々に解除していく
	Text* pText_; // gameover

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameOver(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};