#pragma once
#include "Engine/GameObject.h"

//���̓����蔻����Ǘ�����N���X
class FireCollision : public GameObject
{
    
    XMFLOAT3 fireCP_; //fire�N���X�̍��W������

public:
    //�R���X�g���N�^
    FireCollision(GameObject* parent);

    //�f�X�g���N�^
    ~FireCollision();

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

