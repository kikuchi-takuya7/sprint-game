#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Fire : public GameObject
{
    int hModel_;
    int limit_;

public:
    //�R���X�g���N�^
    Fire(GameObject* parent);

    //�f�X�g���N�^
    ~Fire();

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