#include "EnemyPatternSecond.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "GameClear.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

#define MAXENEMY 16

//�R���X�g���N�^
EnemyPatternSecond::EnemyPatternSecond(GameObject* parent)
	:GameObject(parent, "EnemyPatternSecond"), hModel_(-1), epattern_(0), height_(0), count_(0), x_(0), tmp_(true)
{
	CsvReader csv;
	csv.Load("Second enemy pattern.csv");

	epattern_ = csv.GetWidth();
	height_ = csv.GetHeight();

	table_ = new int* [epattern_];

	for (int x = 0; x < epattern_; x++) {
		table_[x] = new int[height_];
	}

	for (int x = 0; x < epattern_; x++) {
		for (int z = 0; z < height_; z++) {

			table_[x][z] = csv.GetValue(x, z);
		}
	}

}

//�f�X�g���N�^
EnemyPatternSecond::~EnemyPatternSecond()
{
}

//������
void EnemyPatternSecond::Initialize()
{

}

//�X�V
void EnemyPatternSecond::Update()
{

	int r = 0;
	int l = 1;
	int s = 2;

	if (x_ < epattern_) {
		if (count_ % 60 == 0 && table_[x_][r] == 1) {
			Instantiate<EnemyRight>(this);
		}

		if (count_ % 60 == 0 && table_[x_][l] == 1) {
			Instantiate<EnemyLeft>(this);
		}

		if (count_ % 60 == 0 && table_[x_][s] == 1) {
			//���ԓG
			//Instantiate<EnemyLeft>(this);
		}

		count_++;

	}

	if (count_ % 60 == 0) {
		x_++;
	}

	if (epattern_ <= x_) {
		//�Q�[���N���A
		GameObject* pEnemyL = FindObject("EnemyLeft");
		GameObject* pEnemyR = FindObject("EnemyRight");
		GameObject* pEnemyS = FindObject("EnemySky");
		if (pEnemyL == nullptr && pEnemyR == nullptr && pEnemyS == nullptr && tmp_ == true) {
			Instantiate<GameClear>(this);
			tmp_ = false;
		}
	}

}

//�`��
void EnemyPatternSecond::Draw()
{

}

//�J��
void EnemyPatternSecond::Release()
{

	for (int x = 0; x < epattern_; x++) {
		delete[] table_[x];
	}
	delete[] table_;

}