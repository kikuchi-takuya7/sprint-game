#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�����V�[�����Ǘ�����N���X
class Tutorial : public GameObject
{

	Text* pText_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Tutorial(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};