#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�V���������擾���Ǘ�����N���X
//�����E�F�|���N���X������Ă�����v���C���[���Ăяo�����ƂŃE�F�|���N���X�ɐݒ肳��Ă��镐����g���݂����Ȋ����ŕ���؂�ւ��݂����Ȏ����ł��邩��
class NewWeaponFirst : public GameObject
{

	Text* pText_;

	int texttime_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	NewWeaponFirst(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};