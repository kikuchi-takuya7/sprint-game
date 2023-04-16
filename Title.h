#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//タイトルを管理するクラス
class Title : public GameObject
{
	int hPict_;    //画像番号
	Text* pText_;
	int tmp_; //時間差で画面が切り替わるように
	int flash_; //pleas spaceの点滅
	int start_; //点滅を早くする為の変数

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Title(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};