#ifndef CXCHARACTER_H
#define CXCHARACTER_H

#include"CModelX.h"
#include"CMatrix.h"
#include"CCharacter.h"

class CXCharacter:public CCharacter{
public:
	CModelX *mpModel;  //���f���f�[�^

	CMatrix *mpCombinedMatrix;//�����s��ޔ�

	int mAnimationIndex;  //�A�j���[�V����
	bool mAnimationLoopFlg;//true:�A�j���[�V����
	float mAnimationFrame;//�A�j���[�V�����̍Đ��t���[��
	float mAnimationFrameSize;//�A�j���[�V�����̍Đ��t���[����
	CXCharacter()
		:mpCombinedMatrix(0)
	{

	}
	virtual~CXCharacter(){
		SAFE_DELETE_ARRAY(mpCombinedMatrix);
	}
	//����������
	void Init(CModelX *model);
	//�A�j���[�V�����̕ύX
	void ChangeAnimation(int index, bool ioop, float framesize);
	//�X�V����
	void Update(CMatrix &m);
	void Update();
	//�`�揈��
    virtual void Render();

};
#endif