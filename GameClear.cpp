#include "GameClear.h"

//�R���X�g���N�^
GameClear::GameClear(GameObject* parent)
	: GameObject(parent, "GameClear")
{
}

//������
void GameClear::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//�X�V
void GameClear::Update()
{
}

//�`��
void GameClear::Draw()
{

	pText_->Draw(550, 200, "GAME CLEAR");
	pText_->Draw(525, 250, "NEXTSTAGE ENTER");

}

//�J��
void GameClear::Release()
{
}