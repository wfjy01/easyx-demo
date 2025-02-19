#pragma once
#include <graphics.h>

// ��ť��
class CButton
{
public:
	CButton();								// ���캯��
	~CButton();								// ��������

	void set_X_Y(int x, int y);				// ��������
	void set_Image(IMAGE image);			// �������
	int get_X() const; int get_Y() const;	// ��ȡ����
	IMAGE get_Image() const;				// ��ȡ���
	void draw_Button() const;				// ���ư�ť
	bool if_Mouse_On(MOUSEMSG &m) const;	// ��ť��

private:
	int x, y;								// ��ť����
	IMAGE image;							// ��ť���
};
// ��ť��