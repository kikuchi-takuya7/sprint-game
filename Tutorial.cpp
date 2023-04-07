#include "Tutorial.h"
#include  "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Tutorial::Tutorial(GameObject* parent)
	: GameObject(parent, "Tutorial")
{
}

//初期化
void Tutorial::Initialize()
{
}

//更新
void Tutorial::Update()
{

	if (Input::IsKeyDown(DIK_SPACE)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAIN);

	}

}

//描画
void Tutorial::Draw()
{
}

//開放
void Tutorial::Release()
{
}