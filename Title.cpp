#include "Title.h"
#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
//#include "Engine/Text.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Title::Title(GameObject* parent)
	: GameObject(parent, "Title"),hPict_(-1), opacity_(255), pText_(nullptr), tmp_(0)
{
}

//������
void Title::Initialize()
{

	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Title.png");
	assert(hPict_ >= 0);

	pText_ = new Text;

	pText_->Initialize();
	
}

//�X�V
void Title::Update()
{

	if (Input::IsKeyDown(DIK_SPACE)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAIN);

	}

	Image::SetAlpha(hPict_, opacity_);

	if (opacity_ >= 255) {
		tmp_ = 0;
	}
	if(opacity_ <= 0) {
		tmp_ = 1;
	}

	if (tmp_ == 0) {
		opacity_ -= 3;

	}
	
	if (tmp_ == 1) {
		opacity_ += 3;
	
	}


	pText_->Draw(0, 0, "Pleas SPACE");

}

//�`��
void Title::Draw()
{
	
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

}

//�J��
void Title::Release()
{
}
