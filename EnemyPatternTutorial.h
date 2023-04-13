#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyPatternTutorial : public GameObject
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
    EnemyPatternTutorial(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyPatternTutorial();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};