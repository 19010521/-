#include"CMap.h"

//�f�t�H���g�R���X�g���N�^
CMap::CMap()
{
	//�n��
	mCollider[0].SetTriangle(this, CVector(200.0f, 0.0f, 200.0f), CVector(200.0f, 0.0f, -200.0f), CVector(-200.0f, 0.0f, 200.0f));
	mCollider[1].SetTriangle(this, CVector(-200.0f, 0.0f, 200.0f), CVector(200.0f, 0.0f, -200.0f), CVector(-200.0f, 0.0f, -200.0f));
	////�O��
	//mCollider[2].SetTriangle(this, CVector(135.0f, 0.0f, 135.0f), CVector(-135.0f, 0.0f, 135.0f), CVector(-110.0f, 110.0f, 110.0f));
	//mCollider[3].SetTriangle(this, CVector(110.0f, 110.0f, 110.0f), CVector(135.0f, 0.0f, 135.0f), CVector(-110.0f, 110.0f, 110.0f));
	//////�E����
	//mCollider[4].SetTriangle(this, CVector(-150.0f, 135.0f, 150.0f), CVector(-150.0f, 0.0f, 150.0f), CVector(-150.0f, 0.0f, -150.0f));
	//mCollider[5].SetTriangle(this, CVector(-150.0f, 0.0f, -150.0f), CVector(-150.0f, 135.0f, -150.0f), CVector(-150.0f, 135.0f, 150.0f));
	//////������
	//mCollider[6].SetTriangle(this, CVector(150.0f, 135.0f, 150.0f), CVector(150.0f, 135.0f, -150.0f), CVector(150.0f, 0.0f, -150.0f));
	//mCollider[7].SetTriangle(this, CVector(150.0f, 0.0f, -150.0f), CVector(150.0f, 0.0f, 150.0f), CVector(150.0f, 135.0f, 150.0f));
	//////���
	//mCollider[8].SetTriangle(this, CVector(-150.0f, 135.0f, -150.0f), CVector(-150.0f, 0.0f, -150.0f), CVector(150.0f, 0.0f, -150.0f));
	//mCollider[9].SetTriangle(this, CVector(150.0f, 0.0f, -150.0f), CVector(150.0f, 135.0f, -150.0f), CVector(-150.0f, 135.0f, -150.0f));
	////�O�V��
	//mCollider[10].SetTriangle(this, CVector(150.0f, 135.0f, 150.0f), CVector(-150.0f, 135.0f, 150.0f), CVector(0.0f, 190.0f, 0.0f));
	////
	//mCollider[11].SetTriangle(this, CVector(-150.0f, 135.0f, 150.0f), CVector(-150.0f, 135.0f, -150.0f), CVector(0.0f, 190.0f, 0.0f));
	////
	//mCollider[12].SetTriangle(this, CVector(-150.0f, 135.0f, -150.0f), CVector(150.0f, 135.0f, -150.0f), CVector(0.0f, 190.0f, 0.0f));
	////
	//mCollider[13].SetTriangle(this, CVector(150.0f, 135.0f, -150.0f), CVector(150.0f, 135.0f, 150.0f), CVector(0.0f, 190.0f, 0.0f));

}