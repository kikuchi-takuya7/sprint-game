#pragma once
#include "Engine/GameObject.h"

//�����炭��G���Ǘ�����N���X
class EnemyLeft : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    EnemyLeft(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyLeft();

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