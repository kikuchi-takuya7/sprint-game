#include "FireCollision.h"
#include "Fire.h"
#include "Engine/SphereCollider.h"
#include "Engine/Model.h"

//コンストラクタ
FireCollision::FireCollision(GameObject * parent)
	:GameObject(parent, "FireCollision")
{
}

//デストラクタ
FireCollision::~FireCollision()
{
}

//初期化
void FireCollision::Initialize()
{
	
	fireCP_ = { 0, 0, 0 };

}

//更新
void FireCollision::Update()
{

	Fire* pFire = static_cast<Fire*>(this->GetParent());

	XMFLOAT3 fireP = pFire->GetPosition();
	fireCP_ = pFire->GetPosition();
	//XMFLOAT3 fireP = pFire->fireP_;

	ClearCollider();
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0,0,0), 0.8f);
	AddCollider(collision);


}

//描画
void FireCollision::Draw()
{
	CollisionDraw();
}

//開放
void FireCollision::Release()
{
}

//何かに当たった
void FireCollision::OnCollision(GameObject* pTarget)
{
	//当たったときの処理

}