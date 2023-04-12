#include "GameClear.h"

//コンストラクタ
GameClear::GameClear(GameObject* parent)
	: GameObject(parent, "GameClear")
{
}

//初期化
void GameClear::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void GameClear::Update()
{
}

//描画
void GameClear::Draw()
{

	pText_->Draw(550, 200, "GAME CLEAR");
	pText_->Draw(525, 250, "NEXTSTAGE ENTER");

}

//開放
void GameClear::Release()
{
}