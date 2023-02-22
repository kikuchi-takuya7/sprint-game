#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/CsvReader.h"

#define VELOCITY 0.5
#define GRAVITY_ 0.02

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), gravity_(0.02), velocity_(0), panch_(100)
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

	AhModel_ = Model::Load("attack player.fbx");
	assert(AhModel_ >= 0);

	

}

//更新
void Player::Update()
{
	
	panch_++;

	transform_.position_.y += velocity_;

	if (velocity_ < gravity_) {
		velocity_ -= gravity_ * 2;
	}
	else {
		velocity_ -= gravity_;
	}


	if (transform_.position_.y <= 0) {
		transform_.position_.y = 0;
	}


	//prevPosition_ = transform_.position_;

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
	if (Input::IsKeyDown(DIK_V)) 
	{

		panch_ = 0;

	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		velocity_ = VELOCITY;
	}

	XMVECTOR vMove = XMLoadFloat3(&fMove);
	vMove = XMVector3Normalize(vMove);
	vMove *= 0.2f;
	XMStoreFloat3(&fMove, vMove);

	transform_.position_.x += fMove.x;
	transform_.position_.z += fMove.z;


	//短いほうの角度だけ求める向き方向
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

	
}

//描画
void Player::Draw()
{
	if (panch_ < 60) {
		Model::SetTransform(AhModel_, transform_);
		Model::Draw(AhModel_);
	}
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}
