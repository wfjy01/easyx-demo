#include "pch.h"
#include "Command.h"


Command::Command()
{
	click = false;
	LBdown = false;
}

bool Command::getClick()
{
	return click;
}

void Command::setClick(bool state)
{
	click = state;
}

bool Command::getLBdown()
{
	return LBdown;
}

void Command::setLBdown(bool state)
{
	LBdown = state;
}


Command::~Command()
{
}

// ��������Ϣ

DWORD WINAPI Thread_GetMouseMsg(PVOID pMypara)
{
	while (1) {
		// ��ȡ�����Ϣ
		if (MouseHit())
		{
			cmd.msg = GetMouseMsg();
			if (!cmd.getLBdown() && cmd.msg.mkLButton) {
				cmd.setLBdown(true);
				cmd.setClick(true);
			}
			if (cmd.msg.uMsg == WM_LBUTTONUP)
				cmd.setLBdown(false);
		}
		// ��ȡ������Ϣ
		if (_kbhit())
			if (_getch() == ' ')
				cmd.setClick(true);
		Sleep(5);
	}
	return 0;
}
Command cmd;
