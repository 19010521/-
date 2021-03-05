#ifndef CWATERGUN_H
#define CWATERGUN_H
#include"CCharacter.h"
#include"CCollider.h"
class CWaterGun :public CCharacter{
private:
	//�R���C�_
	CCollider mCollider;
	//�O�p�`
	CTriangle mT;
	
	//���Ɖ��s���̐ݒ�
	//set(��,���s)
	
	//��������
	int mLife;

	float mVelovcityGun;
	//�X�V
	void Update();

	//�Փˏ���
	//Ccllision(�R���C�_1,�R���C�_2)
	void Collision(CCollider*m, CCollider*y);
	//�`��
	void Render();
public:
	
	CWaterGun();
	CWaterGun(CModel *model, CVector position, CVector rotation, CVector scale);
	
	CVector mForward; //�O��

	void Set(float w, float d);
};
#endif