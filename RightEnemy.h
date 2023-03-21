#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class RightEnemy : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    RightEnemy(GameObject* parent);

    //�f�X�g���N�^
    ~RightEnemy();

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