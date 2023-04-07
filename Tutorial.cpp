#include "Tutorial.h"
#include  "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Tutorial::Tutorial(GameObject* parent)
	: GameObject(parent, "Tutorial")
{
}

//������
void Tutorial::Initialize()
{
}

//�X�V
void Tutorial::Update()
{

	if (Input::IsKeyDown(DIK_SPACE)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAIN);

	}

}

//�`��
void Tutorial::Draw()
{
}

//�J��
void Tutorial::Release()
{
}