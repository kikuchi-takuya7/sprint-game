#pragma once
#include "Engine/GameObject.h"

//�G�p�^�[���`���[�g���A�����Ǘ�����N���X
class EnemyPatternTutorial : public GameObject
{
    int x_; //CSV�̈��ڂ��珇�Ԃɓǂݎ��ׂ̕ϐ�
    int count_; //���t���[���̃J�E���g
    int hModel_; 
    int epattern_; //enemy pattern �G�̍ő吔
    int height_; //�s������s���邩
    int** table_; //�|�C���^�z���CSV�f�[�^������

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