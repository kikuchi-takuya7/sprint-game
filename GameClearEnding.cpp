#include "GameClearEnding.h"

//�R���X�g���N�^
GameClearEnding::GameClearEnding(GameObject* parent)
	: GameObject(parent, "GameClearEnding")
{
}

//������
void GameClearEnding::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//�X�V
void GameClearEnding::Update()
{
}

//�`��
void GameClearEnding::Draw()
{

	pText_->Draw(550, 200, "GAME CLEAR");
	pText_->Draw(525, 250, "THANK YOU FOR PLAYNG");

}

//�J��
void GameClearEnding::Release()
{
}