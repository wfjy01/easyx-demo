#pragma once
#include "CGame.h"

// ���ؽ�����
class CWin : public CGame
{
public:
	CWin();						// ���캯��
	~CWin();					// ��������

	void inter_Face_Running();	// ���ؽ���

private:
	void change_Best_Time();	// �޸����ʱ��
	void draw_Title();			// ���Ʊ���
};
// ���ؽ�����
