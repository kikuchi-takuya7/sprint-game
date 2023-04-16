#pragma once
#include "Engine/GameObject.h"

//���X�e�[�W���Ǘ�����N���X
class GameScene : public GameObject
{

	bool tmp_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};