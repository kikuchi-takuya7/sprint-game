#include "GameOver.h"
#include "GameScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
GameOver::GameOver(GameObject* parent)
	: GameObject(parent, "GameOver"), hPict_(-1), opacity_(255)
{
}

//初期化
void GameOver::Initialize()
{

	hPict_ = Image::Load("explosions.png");
	assert(hPict_ >= 0);

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void GameOver::Update()
{

	
	Image::SetAlpha(hPict_, opacity_);
	opacity_ -= 2;
	
}

//描画
void GameOver::Draw()
{

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	if (opacity_ <= 0) {
		pText_->Draw(550, 200, "GAME OVER");
		pText_->Draw(525, 250, "RESTART ENTER");
	}

}

//開放
void GameOver::Release()
{
}