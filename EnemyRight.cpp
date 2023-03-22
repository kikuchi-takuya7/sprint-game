#include "EnemyRight.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//�R���X�g���N�^
EnemyRight::EnemyRight(GameObject* parent)
	:GameObject(parent, "EnemyRight"), hModel_(-1)
{
}

//�f�X�g���N�^
EnemyRight::~EnemyRight()
{
}

//������
void EnemyRight::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 25;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
}

//�X�V
void EnemyRight::Update()
{
	transform_.position_.x -= 0.1f;
}

//�`��
void EnemyRight::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void EnemyRight::Release()
{
}

//�����ɓ�������
void EnemyRight::OnCollision(GameObject* pTarget)
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
}