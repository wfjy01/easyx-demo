#pragma once
#include "Head.h"
#include <graphics.h>

// ��ťͼ����
class CButton_Image
{
public:
	CButton_Image();																// ���캯��
	~CButton_Image();																// ��������

	IMAGE start_Button(COLORREF color);												// ��ʼ��ťͼ��
	IMAGE help_Button(COLORREF color);												// ������ťͼ��
	IMAGE close_Button(COLORREF color);												// �رհ�ťͼ��
	IMAGE level_Button(const wchar_t num[], const wchar_t tim[], COLORREF color);	// �ؿ���ťͼ��
	IMAGE return_Button(COLORREF color);											// ���ذ�ťͼ��
	IMAGE again_Button(COLORREF color);												// ������ťͼ��
	IMAGE next_Button(COLORREF color);												// ��һ�ذ�ťͼ��
	IMAGE ok_Button(COLORREF color);												// O K ��ťͼ��
};
// ��ťͼ����
