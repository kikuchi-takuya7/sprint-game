#include "EnemyPatternTutorial.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "EnemySky.h"
#include "GameClear.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/CsvReader.h"

#define MAXENEMY 16

//コンストラクタ
EnemyPatternTutorial::EnemyPatternTutorial(GameObject* parent)
	:GameObject(parent, "EnemyPatternTutorial"), hModel_(-1), epattern_(0), height_(0), count_(0), x_(0)
{
	CsvReader csv;
	csv.Load("Enemy pattern Tutorial.csv");

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

//デストラクタ
EnemyPatternTutorial::~EnemyPatternTutorial()
{
}

//初期化
void EnemyPatternTutorial::Initialize()
{

}

//更新
void EnemyPatternTutorial::Update()
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
			//空飛ぶ敵
			Instantiate<EnemySky>(this);
		}

		count_++;

	}

	if (count_ % 60 == 0) {
		x_++;
	}

}

//描画
void EnemyPatternTutorial::Draw()
{

}

//開放
void EnemyPatternTutorial::Release()
{

	for (int x = 0; x < epattern_; x++) {
		delete[] table_[x];
	}
	delete[] table_;

}