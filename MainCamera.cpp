#include "MainCamera.h"
#include "Engine/Camera.h"


//�R���X�g���N�^
MainCamera::MainCamera(GameObject* parent)
	: GameObject(parent, "MainCamera")
{
}

//������
void MainCamera::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 10, -30));

	Camera::SetTarget(XMFLOAT3(0, 5, 0));
}

//�X�V
void MainCamera::Update()
{
}

//�`��
void MainCamera::Draw()
{
}

//�J��
void MainCamera::Release()
{
}
