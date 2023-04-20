#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//新しい装備取得を管理するクラス
//多分ウェポンクラスを作ってそれをプレイヤーが呼び出すことでウェポンクラスに設定されている武器を使うみたいな感じで武器切り替えみたいな事ができるかも
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