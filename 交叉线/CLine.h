#pragma once

// ����
class CLine
{
public:
	CLine(int a = 0, int b = 0);				// ���캯��
	~CLine();									// ��������

	double vector_Mult(int a, int b, int c);	// �������
	bool line_Cross(CLine l);					// �ж��߶��Ƿ񽻲�

	int a, b;									// ���
};
// ����
