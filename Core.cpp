#include "Core.h"
#include "Engine/Model.h"

//コンストラクタ
Core::Core(GameObject* parent)
    :GameObject(parent, "Core"), hModel_(-1)
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