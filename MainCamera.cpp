#include "MainCamera.h"
#include "Engine/Camera.h"


//コンストラクタ
MainCamera::MainCamera(GameObject* parent)
	: GameObject(parent, "MainCamera")
{
}

//初期化
void MainCamera::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 10, -30));

	Camera::SetTarget(XMFLOAT3(0, 5, 0));
}

//更新
void MainCamera::Update()
{
}

//描画
void MainCamera::Draw()
{
}

//開放
void MainCamera::Release()
{
}
