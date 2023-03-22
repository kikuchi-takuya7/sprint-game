#include "EnemyRight.h"
#include "Engine/BoxCollider.h"
#include "Engine/CsvReader.h"
#include "Engine/Model.h"

//コンストラクタ
EnemyRight::EnemyRight(GameObject* parent)
	:GameObject(parent, "EnemyRight"), hModel_(-1)
{
}

//デストラクタ
EnemyRight::~EnemyRight()
{
}

//初期化
void EnemyRight::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 25;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
}

//更新
void EnemyRight::Update()
{
	transform_.position_.x -= 0.1f;
}

//描画
void EnemyRight::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void EnemyRight::Release()
{
}

//何かに当たった
void EnemyRight::OnCollision(GameObject* pTarget)
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
}