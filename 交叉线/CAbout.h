#pragma once
#include "CGame.h"
#include "CButton.h"
#include "CButton_Image.h"

// ���ڽ�����
class CAbout : public CGame
{
public:
	CAbout();					// ���캯��
	~CAbout();					// ��������

	void inter_Face_Running();	// ���ڽ���

private:
	void draw_Text();			// �������
};
// ���ڽ�����
