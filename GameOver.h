#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�Q�[���I�[�o�[�V�[�����Ǘ�����N���X
class GameOver : public GameObject
{

	int hPict_;    //�摜�ԍ�
	int opacity_; //���������X�ɉ������Ă���
	Text* pText_; // gameover

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameOver(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};