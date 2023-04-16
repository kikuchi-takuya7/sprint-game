#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyPatternSecond : public GameObject
{
    int x_; //CSV�̈��ڂ��珇�Ԃɓǂݎ��ׂ̕ϐ�
    int count_; //���t���[���̃J�E���g
    int hModel_;
    int epattern_; //enemy pattern �G�̍ő吔
    int height_; //�s������s���邩
    int** table_; //�|�C���^�z���CSV�f�[�^������
    bool tmp_; //�N���A�������ǂ���

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