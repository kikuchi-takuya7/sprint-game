#include "Player.h"
#include "PanchRight.h"
#include "PanchLeft.h"
#include "Fire.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/CsvReader.h"
#include "Engine/VFX.h"

#define VELOCITY 0.5
#define GRAVITY 0.02

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), gravity_(GRAVITY), velocity_(0), panch_(100), fire_(300), firePX_(0), firePY_(0), firetmp_(0), fireVec_(0)
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



	if (Input::IsKey(DIK_D))
	{
		if (transform_.position_.x <= 20) {
			
			transform_.position_.x += 0.2f;
		}

		if (panch_ >= 60) {

			transform_.rotate_.y = 90;
		}
			

	}
	if (Input::IsKey(DIK_A))
	{
		if (transform_.position_.x >= -20) {

			transform_.position_.x -= 0.2f;
		}

		if (panch_ >= 60) {

			transform_.rotate_.y = -90;
		}
	}

	if (Input::IsKeyDown(DIK_V) && panch_ >= 100)
	{
		if (transform_.rotate_.y == 90) {
			Instantiate<PanchRight>(this);
		}
		if (transform_.rotate_.y == -90) {
			Instantiate<PanchLeft>(this);
		}
		panch_ = 0;

	}

	if (Input::IsKeyDown(DIK_F) && fire_ >= 100 || firetmp_ == 1)
	{

		Instantiate<Fire>(this);
		//if (firetmp_ == 0) {
		//	firePX_ = transform_.position_.x;
		//	firePY_ = transform_.position_.y + 2;
		//	if (transform_.rotate_.y == 90) {
		//		fireVec_ = 0.1f;
		//	}

		//	if (transform_.rotate_.y == -90) {
		//		fireVec_ = -0.1f;
		//	}
		//}

		//firetmp_ = 1;
		//

		//EmitterData data;
		//data.textureFileName = "cloudA.png";
		//data.position = XMFLOAT3(firePX_, firePY_, 0);
		//data.positionRnd = XMFLOAT3(0.1, 0, 0.1);
		//data.delay = 0;
		//data.number = 1;
		//data.lifeTime = 60;
		//data.gravity = -0.002f;
		//data.direction = XMFLOAT3(0, 1, 0);
		//data.directionRnd = XMFLOAT3(0, 0, 0);
		//data.speed = 0.01f;
		//data.speedRnd = 0.0;
		//data.size = XMFLOAT2(1.5, 1.5);
		//data.sizeRnd = XMFLOAT2(0.4, 0.4);
		//data.scale = XMFLOAT2(1.01, 1.01);
		//data.color = XMFLOAT4(1, 1, 0, 1);
		//data.deltaColor = XMFLOAT4(0, -0.03, 0, -0.02);

		//VFX::Start(data);

		////火の粉
		//data.number = 3;
		//data.positionRnd = XMFLOAT3(0.8, 0, 0.8);
		//data.direction = XMFLOAT3(0, 1, 0);
		//data.directionRnd = XMFLOAT3(10, 10, 10);
		//data.size = XMFLOAT2(0.2, 0.2);
		//data.scale = XMFLOAT2(0.95, 0.95);
		//data.lifeTime = 120;
		//data.speed = 0.1f;
		//data.gravity = 0;


		//VFX::Start(data);

		//

		//if (firePY_ >= 0) {
		//	firePY_ -= 0.02f;
		//	firePX_ += fireVec_;
		//}

		//if (firePY_ <= 0) {
		//	firetmp_ = 0;
		//	fire_ = 0;
		//}

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

}

void Player::Cooldown()
{
	panch_++;
	fire_++;
}
