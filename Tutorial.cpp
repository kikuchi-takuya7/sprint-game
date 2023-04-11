#include "Tutorial.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "MainCamera.h"
#include  "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Tutorial::Tutorial(GameObject* parent)
	: GameObject(parent, "Tutorial"), texttime_(0)
{
}

//初期化
void Tutorial::Initialize()
{

	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<MainCamera>(this);
	Instantiate<Core>(this);

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void Tutorial::Update()
{

	texttime_++;
	

	if (Input::IsKeyDown(DIK_RETURN)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAIN);
	}

}

//描画
void Tutorial::Draw()
{
	pText_->Draw(1000, 20, "Let's go! => ENTER");
	pText_->Draw(10, 20, "direction key => move");
	pText_->Draw(10, 55, "V => panch \rSPACE => jump");
	pText_->Draw(10, 90, "F => fire *Only one on screen ");
	pText_->Draw(10, 125, "core break = you die");

	if (0 <= texttime_ && texttime_ <= 120) {
		pText_->Draw(10, 20, "");
	}
	if (120 <= texttime_ && texttime_ <= 300) {
		
	}

}

//開放
void Tutorial::Release()
{
}