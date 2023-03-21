#include "RightEnemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//コンストラクタ
RightEnemy::RightEnemy(GameObject* parent)
	:GameObject(parent, "RightEnemy"), hModel_(-1)
{
}

//デストラクタ
RightEnemy::~RightEnemy()
{
}

//初期化
void RightEnemy::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 25;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
}

//更新
void RightEnemy::Update()
{
	transform_.position_.x -= 0.1f;
}

//描画
void RightEnemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void RightEnemy::Release()
{
}

//何かに当たった
void RightEnemy::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Panch")
	{
		KillMe();
	}

}