#include "EnemyLeft.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//コンストラクタ
EnemyLeft::EnemyLeft(GameObject* parent)
	:GameObject(parent, "EnemyLeft"), hModel_(-1)
{
}

//デストラクタ
EnemyLeft::~EnemyLeft()
{
}

//初期化
void EnemyLeft::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = -25;


	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);

}

//更新
void EnemyLeft::Update()
{

	transform_.position_.x += 0.1f;

}

//描画
void EnemyLeft::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void EnemyLeft::Release()
{
}

void EnemyLeft::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "PanchRight")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "PanchLeft")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "FireCollision")
	{
		KillMe();
	}

}