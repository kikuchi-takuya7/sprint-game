#include "EnemyPatternFirst.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "GameClear.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/CsvReader.h"

#define MAXENEMY 16

//コンストラクタ
EnemyPatternFirst::EnemyPatternFirst(GameObject* parent)
	:GameObject(parent, "EnemyPatternFirst"), hModel_(-1), epattern_(0), height_(0), count_(0), x_(0), tmp_(true)
{
	CsvReader csv;
	csv.Load("Enemy pattern First.csv");

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
EnemyPatternFirst::~EnemyPatternFirst()
{
}

//初期化
void EnemyPatternFirst::Initialize()
{

}

//更新
void EnemyPatternFirst::Update()
{

	int r = 0;
	int l = 1;
	
	if (x_ < epattern_) {
		if (count_ % 60 == 0 && table_[x_][r] == 1) {
			Instantiate<EnemyRight>(this);
		}

		if (count_ % 60 == 0 && table_[x_][l] == 1) {
			Instantiate<EnemyLeft>(this);
		}

		count_++;

	}

	if (count_ % 60 == 0) {
		x_++;
	}

	if (epattern_ <= x_) {
		//ゲームクリア
		GameObject* pGameobject = FindObject("EnemyLeft");
		GameObject* pGame = FindObject("EnemyRight");
		if ( !pGameobject && !pGame && tmp_ ) {
			
			Instantiate<GameClear>(this);
			tmp_ = false;
		}

		if (Input::IsKeyDown(DIK_RETURN) && !tmp_) {

			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_SECOND);
		}
	}

}

//描画
void EnemyPatternFirst::Draw()
{
	
}

//開放
void EnemyPatternFirst::Release()
{

	for (int x = 0; x < epattern_; x++) {
		delete[] table_[x];
	}
	delete[] table_;

}