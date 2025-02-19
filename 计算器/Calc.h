#pragma once
#include <graphics.h>
#include <string>
#include <conio.h>
#include <cmath>
#include <algorithm>

using namespace std;

// �궨��
#define _CRT_SECURE_NO_WARNINGS
#define WIDTH		420													// ���ڿ��
#define HEIGHT		600													// ���ڸ߶�
#define BKCOLOR		RGB(LIGHTRED, LIGHTGREEN, 0)						// ������ɫ
#define WNDCOLOR    RGB(238, 224, 229)									// ������ɫ
#define COLOR1		RGB(244, 36, 198)									// ��ť��ɫ 1
#define COLOR2		RGB(116, 47, 250)									// ��ť��ɫ 2
#define COLOR3		RGB(255, 128, 0)									// ��ť��ɫ 3

// ��ť��
class GButton
{
private:
	int x;
	int y;
	int cx;
	int cy;
	string String;
	COLORREF color;
public:
	GButton();
	void GButtonX(int x1, int y1, int cx1, int cy1, char *str, COLORREF colors);
	void GButtonX(int x1, int y1, int cx1, int cy1, char c, COLORREF colors);
	void PaintButton();
	void PainButtonWall(COLORREF color);
	string ReturnButtonString();
};

// �༭����
class GEdit {
private:
	int x;
	int y;
	int cx;
	int cy;
	int maxsize;
	string String;
public:
	GEdit();
	void GEditX(int x1, int y1, int size);
	void PaintEdit();
	void ShowEdit();
	void SetEditString(string Strings);
};

class GCount {
private:
	string String;
	GEdit edit;
	GButton button[6][4];
	MOUSEMSG msg;
	int xNow;			// ��ǰ��ť
	int yNow;			// ��ǰ��ť
	int xPre;			// ��һ�ΰ�ť
	int yPre;			// ��һ�ΰ�ť
	bool flag;
	string left;
	string right;
	char oper;
	double number1;
	double number2;
	char str1[100]; 
public:
	GCount();
	void Run();
	void CreateCount(); 
	void ProcessMsg();
	bool OnLocate(int x, int y);				// ��λ
	void OnMouseMoveButton(int x, int y);		// ����ƶ�����ť��
	void OnLeftButtonDown(int x, int y);		// ����������
	void OnSetData();
	void OnCompute();							// ����
	void OnAdd();								// �ӷ�����
	void OnSub();								// ��������
	void OnMul();								// �˷�����
	void OnDiv();								// ��������
	void OnMod();								// ȡģ����
	void OnSqu();								// ��ƽ��
	void OnExp();								// ָ������
	void OnRec();								// ����
	void OnSqr();								// ��ƽ��
};

extern void Retangle(int x1, int y1, int x2, int y2, COLORREF color);