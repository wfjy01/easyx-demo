#pragma once
#include "CGame.h"

// �ؿ�������
class CLevel : public CGame
{
public:
	CLevel();					// ���캯��
	~CLevel();					// ��������

	void inter_Face_Running();	// �ؿ�����

private:
	int stat();					// ͳ�ƹؿ�
};
// �ؿ�������

