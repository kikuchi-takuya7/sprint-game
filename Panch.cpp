#include "Panch.h"
#include "Player.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

#define LIMIT 60

//コンストラクタ
Panch::Panch(GameObject* parent)
	:GameObject(parent, "Panch"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//デストラクタ
Panch::~Panch()
{
}

//初期化
void Panch::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	
	
}

//更新
void Panch::Update()
{


	Player* pPlayer = static_cast<Player*>(this->GetParent());
	XMFLOAT3 panchR = pPlayer->GetRotate();

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 0), XMFLOAT3(1, 0.3, 0.5));

	if (panchR.y == 90) {
		collision = new BoxCollider(XMFLOAT3(1, 1, 0), XMFLOAT3(1, 0.3, 0.5));
	}
	if (panchR.y == -90) {
		collision = new BoxCollider(XMFLOAT3(-1, 1, 0), XMFLOAT3(1, 0.3, 0.5));
	}

	ClearCollider();
	AddCollider(collision);


	limit_--;
	if (limit_ == 0) {
		KillMe();
	}

	Debug::Log(transform_.position_.x);

}

//描画
void Panch::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//開放
void Panch::Release()
{
}

//何かに当たった
void Panch::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	

}