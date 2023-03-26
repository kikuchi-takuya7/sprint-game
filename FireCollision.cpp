#include "FireCollision.h"
#include "Fire.h"
#include "Engine/SphereCollider.h"
#include "Engine/Model.h"

//�R���X�g���N�^
FireCollision::FireCollision(GameObject * parent)
	:GameObject(parent, "FireCollision")
{
}

//�f�X�g���N�^
FireCollision::~FireCollision()
{
}

//������
void FireCollision::Initialize()
{
	
	fireCP_ = { 0, 0, 0 };

}

//�X�V
void FireCollision::Update()
{

	Fire* pFire = static_cast<Fire*>(this->GetParent());

	XMFLOAT3 fireP = pFire->GetPosition();
	fireCP_ = pFire->GetPosition();
	//XMFLOAT3 fireP = pFire->fireP_;

	ClearCollider();
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0,0,0), 0.8f);
	AddCollider(collision);


}

//�`��
void FireCollision::Draw()
{
	CollisionDraw();
}

//�J��
void FireCollision::Release()
{
}

//�����ɓ�������
void FireCollision::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���

}