#include "Panch.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

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

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	BoxCollider* collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));

	if (Input::IsKey(DIK_D)) {
		collision = new BoxCollider(XMFLOAT3(1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	}

	if (Input::IsKey(DIK_A)) {
		collision = new BoxCollider(XMFLOAT3(-1, 0, 0), XMFLOAT3(1, 0.3, 0.5));
	}

	AddCollider(collision);

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