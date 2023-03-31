#include "GameScene.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternFirst.h"
#include "MainCamera.h"


//�R���X�g���N�^
GameScene::GameScene(GameObject* parent)
	: GameObject(parent, "GameScene")
{
}

//������
void GameScene::Initialize()
{
	Instantiate<EnemyPatternFirst>(this);
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<MainCamera>(this);
	Instantiate<Core>(this);

}

//�X�V
void GameScene::Update()
{
}

//�`��
void GameScene::Draw()
{
}

//�J��
void GameScene::Release()
{
}
