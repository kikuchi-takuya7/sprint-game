#include "Fstage.h"
#include "LeftEnemy.h"
#include "RightEnemy.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

#define MAXENEMY 16

//�R���X�g���N�^
Fstage::Fstage(GameObject* parent)
	:GameObject(parent, "Fstage"), hModel_(-1), epattern_(0), height_(0), count_(0), x_(0)
{
	CsvReader csv;
	csv.Load("First enemy pattern.csv");

	epattern_ = csv.GetWidth();
	height_ = csv.GetHeight();

	table_ = new int* [epattern_];

	for (int x = 0; x < epattern_; x++) {
		table_[x] = new int[height_];
	}

	for (int x = 0; x < epattern_; x++) {
		for (int z = 0; z < height_; z++) {

			table_[x][/*height_ - 1 - */z] = csv.GetValue(x, z);
		}
	}

}

//�f�X�g���N�^
Fstage::~Fstage()
{
}

//������
void Fstage::Initialize()
{

}

//�X�V
void Fstage::Update()
{

	int r = 0;
	int l = 1;
	
	

	if (count_ % 60 == 0 && table_[x_][r] == 1) {
		Instantiate<RightEnemy>(this);
	}

	if (count_ % 60 == 0 && table_[x_][l] == 1) {
		Instantiate<LeftEnemy>(this);
	}

	if (count_ % 60 == 0 && x_ < MAXENEMY) {
		x_++;
	}

	count_++;

}

//�`��
void Fstage::Draw()
{
	
}

//�J��
void Fstage::Release()
{

	for (int x = 0; x < epattern_; x++) {
		delete[] table_[x];
	}
	delete[] table_;

}