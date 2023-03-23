#include "Fire.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/VFX.h"
#include "Engine/Debug.h"

#define LIMIT 300

//コンストラクタ
Fire::Fire(GameObject* parent)
	:GameObject(parent, "Fire"), hModel_(-1), limit_(LIMIT), firePositionY_(2), firePositionX_(0)
{
}

//デストラクタ
Fire::~Fire()
{
}

//初期化
void Fire::Initialize()
{
	
	
	

	
}

//更新
void Fire::Update()
{
	
	EmitterData data;
	data.textureFileName = "cloudA.png";


	firePositionX_ = transform_.position_.x;

	Debug::Log(transform_.position_.x);

	data.position = XMFLOAT3(firePositionX_ , firePositionY_, 0);
	data.positionRnd = XMFLOAT3(0.1, 0, 0.1);
	data.delay = 0;
	data.number = 1;
	data.lifeTime = 60;
	data.gravity = -0.002f;
	data.direction = XMFLOAT3(0, 1, 0);
	data.directionRnd = XMFLOAT3(0, 0, 0);
	data.speed = 0.01f;
	data.speedRnd = 0.0;
	data.size = XMFLOAT2(1.5, 1.5);
	data.sizeRnd = XMFLOAT2(0.4, 0.4);
	data.scale = XMFLOAT2(1.01, 1.01);
	data.color = XMFLOAT4(1, 1, 0, 1);
	data.deltaColor = XMFLOAT4(0, -0.03, 0, -0.02);
	
	VFX::Start(data);

	//火の粉
	data.number = 3;
	data.positionRnd = XMFLOAT3(0.8, 0, 0.8);
	data.direction = XMFLOAT3(0, 1, 0);
	data.directionRnd = XMFLOAT3(10, 10, 10);
	data.size = XMFLOAT2(0.2, 0.2);
	data.scale = XMFLOAT2(0.95, 0.95);
	data.lifeTime = 120;
	data.speed = 0.1f;
	data.gravity = 0;

	VFX::Start(data);
	

	int endEmit;

	if (firePositionY_ >= 0 && transform_.rotate_.y == 90) {
		firePositionY_ -= 0.02f;
		firePositionX_ += 0.1f;
	}

	if (firePositionY_ <= 0) {
		limit_--;
	}

	if (limit_ <= 0) {
		endEmit = VFX::Start(data);
		VFX::End(endEmit);
		KillMe();
	}

}

//描画
void Fire::Draw()
{
	
}

//開放
void Fire::Release()
{
}

//何かに当たった
void Fire::OnCollision(GameObject* pTarget)
{
	//当たったときの処理

}