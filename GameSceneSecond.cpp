#include "GameSceneSecond.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternSecond.h"
#include "MainCamera.h"
#include "Engine/Input.h"


//�R���X�g���N�^
GameSceneSecond::GameSceneSecond(GameObject* parent)
	: GameObject(parent, "GameSceneSecond"), tmp_(true)
{
}

//������
void GameSceneSecond::Initialize()
{
	Instantiate<EnemyPatternSecond>(this);
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<MainCamera>(this);
	Instantiate<Core>(this);

}

//�X�V
void GameSceneSecond::Update()
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
			Instantiate<EnemyPatternSecond>(this);
			Instantiate<Player>(this);
			Instantiate<Stage>(this);
			Instantiate<MainCamera>(this);
			Instantiate<Core>(this);
			tmp_ = true;
		}
	}

}

//�`��
void GameSceneSecond::Draw()
{
}

//�J��
void GameSceneSecond::Release()
{
}
