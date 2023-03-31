#include "GameOver.h"
#include "Engine/Image.h"

//�R���X�g���N�^
GameOver::GameOver(GameObject* parent)
	: GameObject(parent, "GameOver"), hPict_(-1), opacity_(255)
{
}

//������
void GameOver::Initialize()
{

	hPict_ = Image::Load("explosion.png");
	assert(hPict_ >= 0);

	

}

//�X�V
void GameOver::Update()
{

	Image::SetAlpha(hPict_, opacity_);

	opacity_ -= 3;

}

//�`��
void GameOver::Draw()
{

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

}

//�J��
void GameOver::Release()
{
}