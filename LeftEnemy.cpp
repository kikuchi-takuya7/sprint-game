#include "LeftEnemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//コンストラクタ
LeftEnemy::LeftEnemy(GameObject* parent)
	:GameObject(parent, "LeftEnemy"), hModel_(-1)
{
}

//デストラクタ
LeftEnemy::~LeftEnemy()
{
}

//初期化
void LeftEnemy::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = -25;


	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

}

//更新
void LeftEnemy::Update()
{

	transform_.position_.x += 0.1f;

}

//描画
void LeftEnemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void LeftEnemy::Release()
{
}

void LeftEnemy::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "Panch")
	{
		KillMe();
	}

}