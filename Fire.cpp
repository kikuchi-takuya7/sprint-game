#include "Fire.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/VFX.h"

#define LIMIT 120

//�R���X�g���N�^
Fire::Fire(GameObject* parent)
	:GameObject(parent, "Fire"), hModel_(-1), limit_(0)
{
}

//�f�X�g���N�^
Fire::~Fire()
{
}

//������
void Fire::Initialize()
{
	

	transform_.position_.y = 2;

}

//�X�V
void Fire::Update()
{
	
	limit_++;


	//��
	{
		EmitterData data;
		data.textureFileName = "cloudA.png";
		//data.position = XMFLOAT3(-4, 4, 4);
		data.positionRnd = XMFLOAT3(0.1, 0, 0.1);
		data.delay = 5;
		data.number = 1;
		data.lifeTime = 60;
		data.gravity = -0.002f;
		data.direction = XMFLOAT3(0, 1, 0);
		data.directionRnd = XMFLOAT3(0, 0, 0);
		data.speed = 0.01f;
		data.speedRnd = 0.0;
		data.size = XMFLOAT2(1.5, 1.5);
		data.sizeRnd = XMFLOAT2(0.4, 0.4);
		data.scale = XMFLOAT2(1.01, 1.01);
		data.color = XMFLOAT4(1, 1, 0, 1);
		data.deltaColor = XMFLOAT4(0, -0.03, 0, -0.02);
		VFX::Start(data);

		//�΂̕�
		data.number = 3;
		data.positionRnd = XMFLOAT3(0.8, 0, 0.8);
		data.direction = XMFLOAT3(0, 1, 0);
		data.directionRnd = XMFLOAT3(10, 10, 10);
		data.size = XMFLOAT2(0.2, 0.2);
		data.scale = XMFLOAT2(0.95, 0.95);
		data.lifeTime = 120;
		data.speed = 0.1f;
		data.gravity = 0;
		VFX::Start(data);
	}

	if (data.position.y >= 0) {

		data.position.x += 0.1;
		data.position.y -= 0.2;

	}

	if (limit_ >= LIMIT) {
		KillMe();
	}

}

//�`��
void Fire::Draw()
{
	
}

//�J��
void Fire::Release()
{
}

//�����ɓ�������
void Fire::OnCollision(GameObject* pTarget)
{
	//���������Ƃ��̏���

}