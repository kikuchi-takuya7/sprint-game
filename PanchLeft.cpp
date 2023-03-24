#include "PanchLeft.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#define LIMIT 60

//�R���X�g���N�^
PanchLeft::PanchLeft(GameObject* parent)
	:GameObject(parent, "PanchLeft"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//�f�X�g���N�^
PanchLeft::~PanchLeft()
{
}

//������
void PanchLeft::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(-1, 1, 0), XMFLOAT3(1, 0.3, 0.5));
	AddCollider(collision);

}

//�X�V
void PanchLeft::Update()
{

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	

}

//�`��
void PanchLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//�J��
void PanchLeft::Release()
{
}

//�����ɓ�������
void PanchLeft::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���


}