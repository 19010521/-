
#include"CRock.h"
#include"CXPlayer.h"
#include"CEffect.h"
#include"CKey.h"
CRock *CRock::mpRock = 0;

extern std::shared_ptr<CTexture>TextureExp1;
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 10.0f)
,mColBody2(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 12.0f)
{
	mColBody.mTag = CCollider::EROCK;
	mColBody2.mTag = CCollider::EROCK2;
	
	//���f��,�ʒu,�g�k��ݒ肷��
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�
	

}

void CRock::Collision(CCollider *m, CCollider *y){
	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(m, y)){
			if (y->mTag == CCollider::EPLAYEREBODY){
				if (m->mTag == CCollider::EROCK2){
					if (CKey::Once('Q')){
						if (CXPlayer::mpxPlayer->mBomb > 0){
							new CEffect(y->mPosition*y->mMatrix*y->mpParent->mMatrix, 10.0f, 10.0f, TextureExp1, 4, 4, 1);
							if (mEnabled == true){
								CXPlayer::mpxPlayer->mBomb--;
							}
							mEnabled = false;
						}
					}
				}
			}
		}
	}
}
