#include "GameScene.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternFirst.h"
#include "MainCamera.h"
#include "Engine/Input.h"


//コンストラクタ
GameScene::GameScene(GameObject* parent)
	: GameObject(parent, "GameScene"), tmp_(true)
{
}

//初期化
void GameScene::Initialize()
{
	Instantiate<EnemyPatternFirst>(this);
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<MainCamera>(this);
	Instantiate<Core>(this);

}

//更新
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

//描画
void GameScene::Draw()
{
}

//開放
void GameScene::Release()
{
}
