#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Core : public GameObject
{
    int hModel_;

public:
    //�R���X�g���N�^
    Core(GameObject* parent);

    //�f�X�g���N�^
    ~Core();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};