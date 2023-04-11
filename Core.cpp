#include "Core.h"
#include "GameOver.h"
#include "GameScene.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Core::Core(GameObject* parent)
    :GameObject(parent, "Core"), hModel_(-1), die_(1)
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

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
	
}

//�X�V
void Core::Update()
{
	transform_.rotate_.y += 1;

	if (die_ == 0) {
		KillMe();
	}
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

//�����ɓ�������
void Core::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "EnemyRight")
	{
		die_ = 0;
		Instantiate<GameOver>(this);
	}

	if (pTarget->GetObjectName() == "EnemyLeft")
	{
		die_ = 0;
		Instantiate<GameOver>(this);
	}
}