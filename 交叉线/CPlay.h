#pragma once
#include "CGame.h"

// ��Ϸ������
class CPlay : public CGame
{
public:
	CPlay();						// ���캯��
	~CPlay();						// ��������

	void inter_Face_Running();		// ��Ϸ����
	void read_Level();				// ��ȡ�ؿ�
	void draw_Title();				// ���Ʊ���
	void draw_Paper();				// ����ֽ��
	void draw_Graph();				// ����ͼ
	void point_Move(int point_id);	// �ƶ���
	void clear();					// ���
	bool if_Win();					// ʤ���ж�

	static int point_num, line_num;	// ����������
};
// ��Ϸ������