#include "GameOver.h"
#include "Engine/Image.h"

//コンストラクタ
GameOver::GameOver(GameObject* parent)
	: GameObject(parent, "GameOver"), hPict_(-1), opacity_(255)
{
}

//初期化
void GameOver::Initialize()
{

	hPict_ = Image::Load("explosion.png");
	assert(hPict_ >= 0);

	

}

//更新
void GameOver::Update()
{

	Image::SetAlpha(hPict_, opacity_);

	opacity_ -= 3;

}

//描画
void GameOver::Draw()
{

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

}

//開放
void GameOver::Release()
{
}