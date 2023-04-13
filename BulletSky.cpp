#include "BulletSky.h"
#include "Engine/Model.h"


//コンストラクタ
BulletSky::BulletSky(GameObject* parent)
	: GameObject(parent, "BulletSky"), hModel_(-1)
{
}

//初期化
void BulletSky::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);

	transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);
}

//更新
void BulletSky::Update()
{
	transform_.position_.y -= 0.1f;

	if (transform_.position_.y <= 0) {
		KillMe();
	}
}

//描画
void BulletSky::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void BulletSky::Release()
{
}