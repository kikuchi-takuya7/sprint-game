#include "EnemySky.h"
#include "BulletSky.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//コンストラクタ
EnemySky::EnemySky(GameObject* parent)
	:GameObject(parent, "EnemySky"), hModel_(-1), attack_(0), randm_(0)
{
}

//デストラクタ
EnemySky::~EnemySky()
{
}

//初期化
void EnemySky::Initialize()
{
	//モデルデータのロード
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

//更新
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

//描画
void EnemySky::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void EnemySky::Release()
{
}

//何かに当たった
void EnemySky::OnCollision(GameObject* pTarget)
{
	
}