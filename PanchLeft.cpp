#include "PanchLeft.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#define LIMIT 60

//コンストラクタ
PanchLeft::PanchLeft(GameObject* parent)
	:GameObject(parent, "PanchLeft"), hModel_(-1), limit_(LIMIT), tmp_(0)
{
}

//デストラクタ
PanchLeft::~PanchLeft()
{
}

//初期化
void PanchLeft::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("attack player.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(-1, 1, 0), XMFLOAT3(1, 0.3, 0.5));
	AddCollider(collision);

}

//更新
void PanchLeft::Update()
{

	limit_--;

	if (limit_ == 0) {
		KillMe();
	}

	

}

//描画
void PanchLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//開放
void PanchLeft::Release()
{
}

//何かに当たった
void PanchLeft::OnCollision(GameObject* pTarget)
{
	//当たったときの処理


}