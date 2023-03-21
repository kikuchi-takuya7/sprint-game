#include "LeftEnemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//�R���X�g���N�^
LeftEnemy::LeftEnemy(GameObject* parent)
	:GameObject(parent, "LeftEnemy"), hModel_(-1)
{
}

//�f�X�g���N�^
LeftEnemy::~LeftEnemy()
{
}

//������
void LeftEnemy::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = -25;


	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

}

//�X�V
void LeftEnemy::Update()
{

	transform_.position_.x += 0.1f;

}

//�`��
void LeftEnemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void LeftEnemy::Release()
{
}

void LeftEnemy::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "Panch")
	{
		KillMe();
	}

}