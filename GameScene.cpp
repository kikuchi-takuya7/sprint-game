#include "GameScene.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternFirst.h"
#include "MainCamera.h"
#include "Engine/Input.h"


//�R���X�g���N�^
GameScene::GameScene(GameObject* parent)
	: GameObject(parent, "GameScene"), tmp_(true)
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

	GameObject* pGameaObject = FindObject("Core");
	if (pGameaObject == nullptr) {
		
		if (tmp_) {
			Instantiate<GameOver>(this);
			tmp_ = false;
		}

		GameObject* pGame = FindObject("GameOver");
		if (pGame && Input::IsKeyDown(DIK_RETURN)) {

			KillAllChildren();
			Instantiate<EnemyPatternFirst>(this);
			Instantiate<Player>(this);
			Instantiate<Stage>(this);
			Instantiate<MainCamera>(this);
			Instantiate<Core>(this);
			tmp_ = true;
		}
	}

}

//�`��
void GameScene::Draw()
{
}

//�J��
void GameScene::Release()
{
}
