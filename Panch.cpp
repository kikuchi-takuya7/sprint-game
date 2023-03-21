#include "Panch.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#define LIMIT 60

//�R���X�g���N�^
Panch::Panch(GameObject* parent)
	:GameObject(parent, "Panch"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//�f�X�g���N�^
Panch::~Panch()
{
}

//������
void Panch::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	
	
}

//�X�V
void Panch::Update()
{

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	BoxCollider* collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));

	if (Input::IsKey(DIK_D)) {
		collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	}

	if (Input::IsKey(DIK_A)) {
		collision = new BoxCollider(XMFLOAT3(-1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	}

	AddCollider(collision);

}

//�`��
void Panch::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Panch::Release()
{
}

//�����ɓ�������
void Panch::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	

}