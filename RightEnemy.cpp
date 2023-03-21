#include "RightEnemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//�R���X�g���N�^
RightEnemy::RightEnemy(GameObject* parent)
	:GameObject(parent, "RightEnemy"), hModel_(-1)
{
}

//�f�X�g���N�^
RightEnemy::~RightEnemy()
{
}

//������
void RightEnemy::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 25;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
}

//�X�V
void RightEnemy::Update()
{
	transform_.position_.x -= 0.1f;
}

//�`��
void RightEnemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void RightEnemy::Release()
{
}

//�����ɓ�������
void RightEnemy::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Panch")
	{
		KillMe();
	}

}