#pragma once
#include "Engine/Text.h"
#include "Engine/GameObject.h"


//�Q�[�����S�N���A���Ǘ�����N���X
class GameClearEnding : public GameObject
{
	Text* pText_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClearEnding(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};