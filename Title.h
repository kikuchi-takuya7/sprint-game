#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Title : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int opacity_;
	Text* pText_;
	int tmp_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Title(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};