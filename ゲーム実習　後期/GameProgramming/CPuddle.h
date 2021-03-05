#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"
#include"CXEnemy.h"
class CPuddle :public CCharacter{
private:

	CCollider mPuddle;

	CModel *Puddle;
	CModel *MudPuddle;

	CXEnemy *mEnemy;

	//static�ϐ��̍쐬
	int frame;//�t���[�����̃J�E���g
	int frame1;//�t���[�����̃J�E���g
	int mCount;//���̉�
	int mCountMax;//���̉�
	int mnumber;
	bool usefrag;
	
	
	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;//���炷���Ƃ�
	float mxMax, mzMax;//�ő�l�̂��Ƃ�
	void Update();

public:

	
	
	static CPuddle*mpPuddle;

	
	
	static bool rock;
	//�G�̏o��
	static bool Enemy;
	static bool Enemy1;

	CPuddle(CModel*model, CModel*model2, CVector position, CVector rotation, CVector scale);

	static int mclearcount;
	
	
	
	
	//void Render();

};
#endif
