#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"
#include"CXEnemy.h"
#include"CClean.h"
class CPuddle :public CCharacter{
private:

	CCollider mPuddle;

	CModel *Puddle;
	CModel *MudPuddle;

	CCollider*mpCollider;
	CXEnemy *mEnemy;

	CXEnemy2 *mEnemy2;
	//static�ϐ��̍쐬
	int frame;//�t���[�����̃J�E���g
	int frame1;//�t���[�����̃J�E���g
	int EnemyCount;//�G�l�~�[�̏o����
	int EnemyCount1;//�G�l�~�[�̏o��������2
	int mCount;//���̉�
	int mCountMax;//���̉�
	int mnumber;
	int mClean_upCount;//���򉻂܂ł̃J�E���g
	int mClean_upCountMax;//���򉻂܂ł̃J�E���g
	
	bool usefrag;
	bool rock;

	
	
	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;//���炷���Ƃ�
	float mxMax, mzMax;//�ő�l�̂��Ƃ�
	void Update();

public:

	
	
	static CPuddle*mpPuddle;

	
	static 	bool mClean_upCountflag;
	
	//�G�̏o��
	static bool Enemy;
	static bool Enemy2;

	CPuddle(CModel*model, CModel*model2, CVector position, CVector rotation, CVector scale);

	static int mclearcount;
	
	
	
	
	//void Render();

};
#endif
