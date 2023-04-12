#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyPatternSecond : public GameObject
{
    int x_;
    int count_;
    int hModel_;
    int epattern_;
    int height_;
    int** table_;
    bool tmp_;

public:
    //�R���X�g���N�^
    EnemyPatternSecond(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyPatternSecond();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};