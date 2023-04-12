#include "Core.h"
#include "GameOver.h"
#include "GameScene.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"

//コンストラクタ
Core::Core(GameObject* parent)
    :GameObject(parent, "Core"), hModel_(-1), die_(1)
{
}

//デストラクタ
Core::~Core()
{
}

//初期化
void Core::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("core.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2, 1));
	AddCollider(collision);
	
}

//更新
void Core::Update()
{
	transform_.rotate_.y += 1;

}

//描画
void Core::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Core::Release()
{
}

//何かに当たった
void Core::OnCollision(GameObject* pTarget)
{
	//当たったときの処理
	if (pTarget->GetObjectName() == "EnemyRight")
	{
		KillMe();
	}

	if (pTarget->GetObjectName() == "EnemyLeft")
	{
		KillMe();
	}
}