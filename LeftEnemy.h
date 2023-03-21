#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class LeftEnemy : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    LeftEnemy(GameObject* parent);

    //�f�X�g���N�^
    ~LeftEnemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};