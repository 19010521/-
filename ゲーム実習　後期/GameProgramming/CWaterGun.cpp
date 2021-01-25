#include "CWaterGun.h"
#include"CSceneGame.h"
#define G (9.8f/60.0f)//�d�͉����x
#define WATERV0 (1.0f)//������
CWaterGun::CWaterGun()
:mLife(30), mCollider(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f , 1.0f , 1.0f ),1.0f)
, mVelovcityGun(0), mForward(0.0f, 1.0f, 1.0f), x(1.0f)
{
	mpModel = &CSceneGame::mGun;
	mTag = EWATERGUN;
	mVelovcityGun = WATERV0;
	mForward.mY += mVelovcityGun;
	mCollider.mTag = CCollider::EWATER;
	
}
//���Ɖ��s���̐ݒ�
//Set(��,���s)
void CWaterGun::Set(float w, float d){

	//�X�P�[���ݒ�
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//�O�p�`�̒��_�ݒ�
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(-w, 0.0f, 0.0f), CVector(0.0f, 0.0f, d));
	//�O�p�`�̖@���ݒ�
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));

}
//�X�V
void CWaterGun::Update(){

	
		mForward.mY -= G;
		//mVelovcityGun -= G;
		//�ʒu�X�V
		mPosition +=mForward;
		
	
	////�ʒu�X�V
	//�������Ԃ̔���
	
		mScale = mScale*1.1f;
		mCollider.mRadius *= 1.1f;
	
		
		//�������Ԃ̔���
		if (mLife-- > 0){
			CCharacter::Update();
		}
		else{
			//�����ɂ���

			mEnabled = false;

		}

}
//�Փˏ���
//Collision(�R���C�_1,�R���C�_2)
void CWaterGun::Collision(CCollider *m, CCollider *y){

	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(m, y)){
			if (y->mTag == CCollider::EENEMYBODY){
				//�Փ˂��Ă���Ƃ��͖����ɂ���
				mEnabled = false;
			}
		}
	}
	//���g�R���C�_�̔���^�C�v
	switch (m->mType){
	case CCollider::ESPHERE://���R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (y->mType == CCollider::ETRIANGLE){
			CVector adjust;//�����p�x�N�g��		
			if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
				//mEnabled = false;
				//mVelovcityGun = 0;
				//�ʒu�̍X�V
				//mPosition = mPosition - adjust*-1;
				//�s��̍X�V
				CCharacter::Update();

			}

		}
		break;
	}

}

//�`��
void CWaterGun::Render(){

	CCharacter::Render();
	//DIFUSE���F�ݒ�
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	//�O�p�`�`��
	mT.Render(mMatrix);
	//�m�F�p���\�b�h
	//mCollider.Render();

}
