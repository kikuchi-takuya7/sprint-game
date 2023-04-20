#include "NewWeaponFirst.h"
#include "Player.h"
#include "Stage.h"
#include "Core.h"
#include "MainCamera.h"
#include  "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
NewWeaponFirst::NewWeaponFirst(GameObject* parent)
	: GameObject(parent, "NewWeaponFirst"), texttime_(0)
{
}

//������
void NewWeaponFirst::Initialize()
{

	pText_ = new Text;
	pText_->Initialize();

}

//�X�V
void NewWeaponFirst::Update()
{

	texttime_++;

	if (Input::IsKeyDown(DIK_A)) {

	}

	if (Input::IsKeyDown(DIK_D)) {

	}

}

//�`��
void NewWeaponFirst::Draw()
{
	
	pText_->Draw(50, 150, "core break = you die");

	if (0 <= texttime_ && texttime_ <= 120) {
		pText_->Draw(10, 20, "");
	}
	if (120 <= texttime_ && texttime_ <= 300) {

	}

}

//�J��
void NewWeaponFirst::Release()
{
}