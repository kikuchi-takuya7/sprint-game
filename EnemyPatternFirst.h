#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyPatternFirst : public GameObject
{
    int x_;
    int count_;
    int hModel_;
    int epattern_;
    int height_;
    int** table_;

public:
    //�R���X�g���N�^
    EnemyPatternFirst(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyPatternFirst();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};