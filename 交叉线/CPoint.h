#pragma once
// ����
class CPoint
{
public:
	CPoint(int x = 0, int y = 0,
		bool move = 1, bool moving = 0);	// ���캯��
	~CPoint();									// ��������

	int x, y;									// ����
	bool move;									// �Ƿ���ƶ����Ƿ������ƶ�
};
// ����

