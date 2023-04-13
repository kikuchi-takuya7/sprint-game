#include "EnemySky.h"
#include "BulletSky.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//�R���X�g���N�^
EnemySky::EnemySky(GameObject* parent)
	:GameObject(parent, "EnemySky"), hModel_(-1), attack_(0), randm_(0)
{
}

//�f�X�g���N�^
EnemySky::~EnemySky()
{
}

//������
void EnemySky::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("EnemySky.fbx");
	assert(hModel_ >= 0);

	transform_.position_.y = 17;

	//std::srand(time(NULL));
	randm_ = rand() % 2;

	if (randm_ == 0) {
		transform_.position_.x = 25;
	}

	if (randm_ == 1) {
		transform_.position_.x = -25;
	}

}

//�X�V
void EnemySky::Update()
{
	attack_++;
	
	if (attack_ % 180 == 0) {
		//Instantiate<BulletSky>(this);
		BulletSky* pBullet = Instantiate<BulletSky>(GetParent());
		pBullet->SetPosition(transform_.position_);
	}
	
	
	
	transform_.rotate_.y += 0.5f;
	
	if (randm_ == 0) {
		transform_.position_.x -= 0.08f;
		if (transform_.position_.x <= -25) {
			KillMe();
		}
	}
	if (randm_ == 1) {
		transform_.position_.x += 0.08f;
		if (transform_.position_.x >= 25) {
			KillMe();
		}
	}

}

//�`��
void EnemySky::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void EnemySky::Release()
{
}

//�����ɓ�������
void EnemySky::OnCollision(GameObject* pTarget)
{
	
}