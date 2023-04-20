#include "NewWeaponFirst.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "MainCamera.h"
#include  "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
NewWeaponFirst::NewWeaponFirst(GameObject* parent)
	: GameObject(parent, "NewWeaponFirst"), texttime_(0)
{
}

//初期化
void NewWeaponFirst::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void NewWeaponFirst::Update()
{

	texttime_++;

	if (Input::IsKeyDown(DIK_A)) {

	}

	if (Input::IsKeyDown(DIK_D)) {

	}

}

//描画
void NewWeaponFirst::Draw()
{
	
	pText_->Draw(50, 150, "core break = you die");

	if (0 <= texttime_ && texttime_ <= 120) {
		pText_->Draw(10, 20, "");
	}
	if (120 <= texttime_ && texttime_ <= 300) {

	}

}

//開放
void NewWeaponFirst::Release()
{
}