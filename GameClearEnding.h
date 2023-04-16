#pragma once
#include "Engine/Text.h"
#include "Engine/GameObject.h"


//ゲーム完全クリアを管理するクラス
class GameClearEnding : public GameObject
{
	Text* pText_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameClearEnding(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};