#include "GameClearEnding.h"

//コンストラクタ
GameClearEnding::GameClearEnding(GameObject* parent)
	: GameObject(parent, "GameClearEnding")
{
}

//初期化
void GameClearEnding::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void GameClearEnding::Update()
{
}

//描画
void GameClearEnding::Draw()
{

	pText_->Draw(550, 200, "GAME CLEAR");
	pText_->Draw(525, 250, "THANK YOU FOR PLAYNG");

}

//開放
void GameClearEnding::Release()
{
}