#include "Fire.h"
#include "Player.h"
#include "Engine/SphereCollider.h"
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
	
	Player* pPlayer = static_cast<Player*>(this->GetParent());
	fireP_ = pPlayer->GetPosition();
	fireV_ = pPlayer->GetRotate();
	fireP_.y += 2;

	
	
	

}

//更新
void Fire::Update()
{

	ClearCollider();
	SphereCollider* collision = new SphereCollider(XMFLOAT3(fireP_), 0.8f);
	AddCollider(collision);


	Debug::Log(fireP_.x);


	EmitterData data;
	data.textureFileName = "cloudA.png";
	data.position = XMFLOAT3(fireP_);
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

	if (fireP_.y >= 0 && fireV_.y == 90) {
		fireP_.y -= 0.02f;
		fireP_.x += 0.1f;
	}

	if (fireP_.y >= 0 && fireV_.y == -90) {
		fireP_.y -= 0.02f;
		fireP_.x -= 0.1f;
	}

	if (fireP_.y <= 0) {
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

	CollisionDraw();
	
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