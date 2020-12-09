#include "CEye.h"
#include"CKey.h"
#include"CSceneGame.h"

#define MOUSE_SENSE 3
CEye *CEye::mpthis = 0;

CEye::CEye(CModel*model, CVector position, CVector rotation, CVector scale)
{
	//���f��,�ʒu,��],�g�k��ݒ肷��
	mpModel = model;     //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̈ʒu
	mScale = scale;      //�g�k�̐ݒ�
	
	
}

void CEye::Update(){

	static int mMouseCount = 0;
	++mMouseCount %= MOUSE_SENSE;
	if (mMouseCount == 0){

		//�}�E�X�J�[�\�����N�����̍��W�Ɉړ�
		CInput::SetMousePos(mMouseX, mMouseY);
	}


	//�}�E�X�J�[�\���̍��W���擾oo
	int mx, my;
	//�}�E�X�̈ړ��l
	float m(3.0);
	CInput::GetMousePos(&mx, &my);
	

		if (mx < mMouseX) {
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mY += (mMouseX - mx) / m;
		}
		if (mMouseX < mx) {
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mY += (mMouseX - mx) / m;
		}
		if (my < mMouseY) {
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mX -= (mMouseY - my) / m;
		}
		if (mMouseY < my) {
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mX -= (mMouseY - my) / m;
		}
	
	CCharacter::Update();

}