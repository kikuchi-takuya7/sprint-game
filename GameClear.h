#pragma once
#include "Engine/Text.h"
#include "Engine/GameObject.h"


//�����V�[�����Ǘ�����N���X
class GameClear : public GameObject
{
	Text* pText_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClear(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};