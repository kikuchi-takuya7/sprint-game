#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
	int hModel_;    //���f���ԍ�
	int panch_; //�p���`�̃N�[���_�E��
	int fire_; //fire�̃N�[���_�E��
	bool jump_; //�W�����v�͈�񂾂�

	float gravity_, velocity_;//�d�͂Ə���

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;

	void Cooldown();
};