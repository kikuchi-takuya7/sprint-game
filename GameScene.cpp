#include "GameScene.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "GameOver.h"
#include "EnemyPatternFirst.h"
#include "MainCamera.h"


//コンストラクタ
GameScene::GameScene(GameObject* parent)
	: GameObject(parent, "GameScene")
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
}

//描画
void GameScene::Draw()
{
}

//開放
void GameScene::Release()
{
}
