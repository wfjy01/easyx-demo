#include "CGame.h"

extern MOUSEMSG msg; // �����Ϣ

CGame::CGame()
{
}

CGame::~CGame()
{
}

void CGame::clear_Board()
{
	setbkcolor(BKCOLOR);
	cleardevice();
}
