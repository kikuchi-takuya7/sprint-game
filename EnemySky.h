#pragma once
#include "Engine/GameObject.h"

//����ԓG���Ǘ�����N���X
class EnemySky : public GameObject
{
    int hModel_;
    int attack_; //�U���̃^�C�~���O���Ǘ�
    int randm_; //���E�ǂ������痈�邩�����_��

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