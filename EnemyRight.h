#pragma once
#include "Engine/GameObject.h"

//�E���炭��G���Ǘ�����N���X
class EnemyRight : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    EnemyRight(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyRight();

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