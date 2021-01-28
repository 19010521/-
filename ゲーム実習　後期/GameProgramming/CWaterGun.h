#ifndef CWATERGUN_H
#define CWATERGUN_H
#include"CCharacter.h"
#include"CCollider.h"
class CWaterGun :public CCharacter{
public:
	//�R���C�_
	CCollider mCollider;
	//�O�p�`
	CTriangle mT;
	CVector mForward; //�O��
	//���Ɖ��s���̐ݒ�
	//set(��,���s)
	void Set(float w, float d);
	//��������
	int mLife;
	CWaterGun();
	CWaterGun(CModel *model, CVector position, CVector rotation, CVector scale);
	float mVelovcityGun;
	//�X�V
	void Update();
	
	//�Փˏ���
	//Ccllision(�R���C�_1,�R���C�_2)
	void Collision(CCollider*m, CCollider*y);
	//�`��
	void Render();
};
#endif