#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemySky : public GameObject
{
    int hModel_;
    int attack_;
    int randm_;

public:
    //�R���X�g���N�^
    EnemySky(GameObject* parent);

    //�f�X�g���N�^
    ~EnemySky();

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