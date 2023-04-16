#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�^�C�g�����Ǘ�����N���X
class Title : public GameObject
{
	int hPict_;    //�摜�ԍ�
	Text* pText_;
	int tmp_; //���ԍ��ŉ�ʂ��؂�ւ��悤��
	int flash_; //pleas space�̓_��
	int start_; //�_�ł𑁂�����ׂ̕ϐ�

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