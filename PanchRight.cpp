#include "PanchRight.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

#define LIMIT 60

//�R���X�g���N�^
PanchRight::PanchRight(GameObject* parent)
	:GameObject(parent, "PanchRight"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//�f�X�g���N�^
PanchRight::~PanchRight()
{
}

//������
void PanchRight::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	AddCollider(collision);
	
}

//�X�V
void PanchRight::Update()
{

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	Debug::Log(transform_.position_.x);

}

//�`��
void PanchRight::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void PanchRight::Release()
{
}

//�����ɓ�������
void PanchRight::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	

}