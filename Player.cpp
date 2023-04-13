#include "Player.h"
#include "Panch.h"
#include "Fire.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/CsvReader.h"
#include "Engine/VFX.h"

#define VELOCITY 0.4
#define GRAVITY 0.02

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), gravity_(GRAVITY), velocity_(0), panch_(100), fire_(200), firePX_(0), firePY_(0), firetmp_(0), fireVec_(0)
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

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

	transform_.rotate_.y = 180;
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



	if (Input::IsKey(DIK_RIGHT))
	{
		if (transform_.position_.x <= 20) {
			
			transform_.position_.x += 0.15f;
		}

		if (panch_ >= 60) {

			transform_.rotate_.y = 90;
		}
			

	}
	if (Input::IsKey(DIK_LEFT))
	{
		if (transform_.position_.x >= -20) {

			transform_.position_.x -= 0.15f;
		}

		if (panch_ >= 60) {

			transform_.rotate_.y = -90;
		}
	}

	

	if (Input::IsKeyDown(DIK_V) && panch_ >= 100)
	{
		
		Instantiate<Panch>(this);
		panch_ = 0;
	}

	if (Input::IsKeyDown(DIK_F) && fire_ >= 2)
	{
		Instantiate<Fire>(this);

	}
	if (FindChildObject("Fire")) {
		Fire* pFire = static_cast<Fire*>(this->GetParent());
		XMFLOAT3 fireP = pFire->GetPosition();

		//�{���Ȃ�n�ʂɂ��Ă���200�J�E���g�����牊�������邩�炻������o����悤�ɂ������������Ǐ��0�����邩�痘�p�����Ⴈ��
		if (fireP.y <= 0) {
			fire_ = 0;
		}
	}

}

//�`��
void Player::Draw()
{
	
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
	if (pTarget->GetObjectName() == "EnemyRight")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "EnemyLeft")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "BulletSky")
	{
		KillMe();
	}

}

void Player::Cooldown()
{
	panch_++;
	fire_++;
}
