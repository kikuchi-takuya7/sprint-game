#pragma once
#include "Engine/GameObject.h"

class PanchRight : public GameObject

{

    int hModel_;
    int limit_;
    int tmp_;

public:

    PanchRight(GameObject* parent);
    ~PanchRight();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;

};