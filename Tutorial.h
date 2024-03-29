#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//■■シーンを管理するクラス
class Tutorial : public GameObject
{

	Text* pText_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Tutorial(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};