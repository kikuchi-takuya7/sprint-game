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

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), gravity_(GRAVITY), velocity_(0), panch_(100), fire_(200), firePX_(0), firePY_(0), firetmp_(0), fireVec_(0)
{
	/*CsvReader csv;
	csv.Load("jamp.csv");*/

}

//初期化
void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

	transform_.rotate_.y = 180;
}

//更新
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

		//本来なら地面についてから200カウントしたら炎が消えるからそこから出せるようにしたかったけど常に0が入るから利用しちゃおう
		if (fireP.y <= 0) {
			fire_ = 0;
		}
	}

}

//描画
void Player::Draw()
{
	
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}


//何かに当たった
void Player::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
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
