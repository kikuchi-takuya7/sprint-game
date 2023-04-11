#include "Title.h"
#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
//#include "Engine/Text.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Title::Title(GameObject* parent)
	: GameObject(parent, "Title"),hPict_(-1), pText_(nullptr), tmp_(0), flash_(0), start_(0)
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

		start_ = 1;

	}

	if (tmp_ >= 60) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TUTORIAL);
	}

	if (start_ == 1) {
		tmp_++;
	}

	flash_++;
	if (flash_ >= 60) {
		flash_ = 0;
	}
	

}

//�`��
void Title::Draw()
{
	
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	if (start_ == 0) {
		if (flash_ < 30) {

			pText_->Draw(550, 600, "Pleas SPACE");
		}
	}
	

	if (start_ == 1) {
		if (flash_ % 10 == 0) {
			pText_->Draw(550, 600, "Pleas SPACE");
		}
	}

}

//�J��
void Title::Release()
{
}
