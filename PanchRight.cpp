#include "PanchRight.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

#define LIMIT 60

//コンストラクタ
PanchRight::PanchRight(GameObject* parent)
	:GameObject(parent, "PanchRight"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//デストラクタ
PanchRight::~PanchRight()
{
}

//初期化
void PanchRight::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	AddCollider(collision);
	
}

//更新
void PanchRight::Update()
{

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	Debug::Log(transform_.position_.x);

}

//描画
void PanchRight::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void PanchRight::Release()
{
}

//何かに当たった
void PanchRight::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	

}