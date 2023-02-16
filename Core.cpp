#include "Core.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Core::Core(GameObject* parent)
    :GameObject(parent, "Core"), hModel_(-1)
{
}

//�f�X�g���N�^
Core::~Core()
{
}

//������
void Core::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("core.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Core::Update()
{
	transform_.rotate_.y += 1;
}

//�`��
void Core::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Core::Release()
{
}