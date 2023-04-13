#include "GameSceneSecond.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternSecond.h"
#include "MainCamera.h"
#include "Engine/Input.h"


//コンストラクタ
GameSceneSecond::GameSceneSecond(GameObject* parent)
	: GameObject(parent, "GameSceneSecond"), tmp_(true)
{
}

//初期化
void GameSceneSecond::Initialize()
{
	Instantiate<EnemyPatternSecond>(this);
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<MainCamera>(this);
	Instantiate<Core>(this);

}

//更新
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

//描画
void GameSceneSecond::Draw()
{
}

//開放
void GameSceneSecond::Release()
{
}
