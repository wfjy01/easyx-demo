#pragma once
#include "CGame.h"

class CBegin :public CGame
{
public:
	CBegin();
	~CBegin();
	void inter_Face_Running(); // ��ʼ����
private:
	void draw_Title(); // ���Ʊ���
};