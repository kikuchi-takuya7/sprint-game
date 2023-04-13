#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//■■シーンを管理するクラス
class NewWeaponFirst : public GameObject
{

	Text* pText_;

	int texttime_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	NewWeaponFirst(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};