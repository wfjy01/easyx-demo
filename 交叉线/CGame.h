#pragma once
#include "Head.h"

class CGame
{
public:
	CGame();
	~CGame();
	virtual void inter_Face_Running() = 0; // ����ӿ�
protected:
	void clear_Board(); // ���Ʊ���
};

