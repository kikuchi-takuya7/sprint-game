#pragma once
#include "Engine/GameObject.h"


//空を飛ぶ敵の球を管理するクラス
class BulletSky : public GameObject
{
	int hModel_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	BulletSky(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};