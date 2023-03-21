#include "Player.h"
#include "Panch.h"
#include "Fire.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/CsvReader.h"

#define VELOCITY 0.5
#define GRAVITY_ 0.02

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), gravity_(0.02), velocity_(0), panch_(100), fire_(300)
{
	/*CsvReader csv;
	csv.Load("jamp.csv");*/

}

//������
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	/*AhModel_ = Model::Load("attack player.fbx");
	assert(AhModel_ >= 0);*/

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

}

//�X�V
void Player::Update()
{
	
	Cooldown();

	transform_.position_.y += velocity_;

	if (velocity_ < gravity_) {
		velocity_ -= gravity_ * 2;
	}
	else {
		velocity_ -= gravity_;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		velocity_ = VELOCITY;
	}

	if (transform_.position_.y <= 0) {
		transform_.position_.y = 0;
	}


	XMFLOAT3 fMove = XMFLOAT3(0, 0, 0);

	if (Input::IsKey(DIK_D))
	{
		if (transform_.position_.x <= 20) {
			fMove.x += 0.1f;
		}
	}
	if (Input::IsKey(DIK_A))
	{
		if (transform_.position_.x >= -20)
			fMove.x -= 0.1f;
	}

	XMVECTOR vMove = XMLoadFloat3(&fMove);
	vMove = XMVector3Normalize(vMove);
	vMove *= 0.2f;
	XMStoreFloat3(&fMove, vMove);

	transform_.position_.x += fMove.x;


	//�Z���ق��̊p�x�������߂��������
	XMVECTOR vLength = XMVector3Length(vMove);
	float length = XMVectorGetX(vLength);

	if (length != 0) {
		XMVECTOR vFront = { 0,0,1,0 };
		vMove = XMVector3Normalize(vMove);

		XMVECTOR vDot = XMVector3Dot(vFront, vMove);
		float dot = XMVectorGetX(vDot);
		float angle = acos(dot);

		XMVECTOR vCross = XMVector3Cross(vFront, vMove);
		if (XMVectorGetY(vCross) < 0) {

			angle *= -1;
		}
		transform_.rotate_.y = XMConvertToDegrees(angle);
	}


	if (Input::IsKeyDown(DIK_V) && panch_ >= 100)
	{

		Instantiate<Panch>(this);
		panch_ = 0;

	}

	if (Input::IsKeyDown(DIK_F) && fire_ >= 200)
	{

		Instantiate<Fire>(this);
		fire_ = 0;

	}

}

//�`��
void Player::Draw()
{
	/*if (panch_ < 60) {
		Model::SetTransform(AhModel_, transform_);
		Model::Draw(AhModel_);
	}*/
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}


//�����ɓ�������
void Player::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���
	if (pTarget->GetObjectName() == "RightEnemy")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "LeftEnemy")
	{
		KillMe();
	}

}

void Player::Cooldown()
{
	panch_++;
	fire_++;
}
