#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Fstage : public GameObject
{
    int x_;
    int count_;
    int hModel_;
    int epattern_;
    int height_;
    int** table_;

public:
    //�R���X�g���N�^
    Fstage(GameObject* parent);

    //�f�X�g���N�^
    ~Fstage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};