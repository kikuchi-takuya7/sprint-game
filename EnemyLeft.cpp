#include "EnemyLeft.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//�R���X�g���N�^
EnemyLeft::EnemyLeft(GameObject* parent)
	:GameObject(parent, "EnemyLeft"), hModel_(-1)
{
}

//�f�X�g���N�^
EnemyLeft::~EnemyLeft()
{
}

//������
void EnemyLeft::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = -25;


	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

}

//�X�V
void EnemyLeft::Update()
{

	transform_.position_.x += 0.1f;

}

//�`��
void EnemyLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void EnemyLeft::Release()
{
}

void EnemyLeft::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "PanchRight")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "PanchLeft")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "FireCollision")
	{
		KillMe();
	}

}