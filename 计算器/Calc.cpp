#include "Calc.h"

GButton::GButton()
{
	x = 0;
	y = 0;
	cx = 0;
	cy = 0;
	String = "0";
}

void GButton::GButtonX(int x1, int y1, int cx1, int cy1, char* str, COLORREF colors)
{
	x = x1;
	y = y1;
	cx = cx1;
	cy = cy1;
	String = str;
	color = colors;
	PaintButton();
}

void GButton::GButtonX(int x1, int y1, int cx1, int cy1, char c, COLORREF colors)
{
	x = x1;
	y = y1;
	cx = cx1;
	cy = cy1;
	String = c;
	color = colors;
	PaintButton();
}

// ���ư�ť
void GButton::PaintButton()
{
	setbkmode(TRANSPARENT);
	Retangle(x, y, x + cx, y + cy, color);
	if (String.length() < 3) {
		outtextxy(x + cx / 2 - 5, y + cy / 2 - 5, String.c_str());
	}
	else if (String.length() == 3) {
		outtextxy(x + cx / 2 - 15, y + cy / 2 - 5, String.c_str());
	}
	else {
		outtextxy(x + cx / 2 - 20, y + cy / 2 - 5, String.c_str());
	}
	PainButtonWall(LIGHTGRAY);
}

void GButton::PainButtonWall(COLORREF color)
{
	setcolor(color);
	rectangle(x, y, x + cx, y + cy);
	setcolor(WNDCOLOR);
}

string GButton::ReturnButtonString()
{
	return String;
}

GEdit::GEdit()
{
	x = 0;
	y = 0;
	cx = 0;
	cy = 0;
	String = "";
}

void GEdit::GEditX(int x1, int y1, int size)
{
	x = x1;
	y = y1;
	maxsize = size;
	PaintEdit();
}

void GEdit::PaintEdit()
{
	Retangle(x, y, x + 380, y + 40, BKCOLOR);
	setcolor(LIGHTGRAY);
	rectangle(x, y, x + 380, y + 40);
	setcolor(WNDCOLOR);
}

void GEdit::ShowEdit()
{
	if (String.length() > maxsize) {
		String = String.substr(0, 44);
	}
	outtextxy(25, 35, String.c_str());
}

void GEdit::SetEditString(string Strings)
{
	String = Strings;
}

// ����������
void Retangle(int x1, int y1, int x2, int y2, COLORREF color)
{
	int points[] = { x1, y1,x1, y2,x2, y2,x2,y1 };
	setlinestyle(PS_SOLID, 5);
	setfillcolor(color);
	fillpoly(4, points);
}

GCount::GCount()
{
	int x1 = 20;
	int y1 = 100;
	xPre = 0;
	yPre = 0;
	xNow = 0;
	yNow = 0;
	String = "";
	left = "";
	right = "";
	oper = '0';
	flag = false;
	number1 = number2 = 0.0;

	CreateCount();
	settextstyle(16, 0, _T("Fixedsys"));

	// �� 0 ��
	button[0][0].GButtonX(20, 100, 80, 50, '1', COLOR1);
	button[0][1].GButtonX(120, 100, 80, 50, '2', COLOR1);
	button[0][2].GButtonX(220, 100, 80, 50, '3', COLOR1);
	button[0][3].GButtonX(320, 100, 80, 50, '0', COLOR1);

	// �� 1 ��
	button[1][0].GButtonX(20, 170, 80, 50, '4', COLOR1);
	button[1][1].GButtonX(120, 170, 80, 50, '5', COLOR1);
	button[1][2].GButtonX(220, 170, 80, 50, '6', COLOR1);
	button[1][3].GButtonX(320, 170, 80, 50, '.', COLOR1);

	// �� 2 ��
	button[2][0].GButtonX(20, 240, 80, 50, '7', COLOR1);
	button[2][1].GButtonX(120, 240, 80, 50, '8', COLOR1);
	button[2][2].GButtonX(220, 240, 80, 50, '9', COLOR1);
	button[2][3].GButtonX(320, 240, 80, 50, '%', COLOR2);

	// �� 3 ��
	button[3][0].GButtonX(20, 310, 80, 50, '+', COLOR2);
	button[3][1].GButtonX(120, 310, 80, 50, '-', COLOR2);
	button[3][2].GButtonX(220, 310, 80, 50, '*', COLOR2);
	button[3][3].GButtonX(320, 310, 80, 50, '/', COLOR2);

	// �� 4 ��
	button[4][0].GButtonX(20, 380, 80, 50, _T("+/-"), COLOR2);
	button[4][1].GButtonX(120, 380, 80, 50, _T("rec"), COLOR2);
	button[4][2].GButtonX(220, 380, 80, 50, _T("x^2"), COLOR2);
	button[4][3].GButtonX(320, 380, 80, 50, _T("exp"), COLOR2);

	// �� 5 ��
	button[5][0].GButtonX(20, 450, 80, 50, _T("sqrt"), COLOR2);
	button[5][1].GButtonX(120, 450, 80, 50, _T("<--"), COLOR3);
	button[5][2].GButtonX(220, 450, 180, 50, _T("Clear"), COLOR3);
	button[5][3].GButtonX(20, 520, 380, 50, _T("==="), COLOR2);

	edit.GEditX(20, 20, 45);
}

void GCount::Run()
{
	ProcessMsg();
	edit.ShowEdit();
}

void GCount::CreateCount()
{
	initgraph(WIDTH, HEIGHT);
	setbkcolor(BKCOLOR);
	cleardevice();
	Retangle(0, 0, WIDTH, HEIGHT, WNDCOLOR);
	setcolor(COLOR2);
	line(10, 90, 410, 90);
	line(10, 90, 10, 580);
	line(410, 90, 410, 580);
	line(110, 510, 410, 510);
	line(10, 580, 410, 580);
	line(10, 300, 310, 300);
	line(310, 230, 310, 300);
	line(310, 230, 410, 230);
	line(110, 440, 410, 440);
	line(110, 440, 110, 510);
	setcolor(WNDCOLOR);
}

void GCount::ProcessMsg()
{
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	while (MouseHit()) {						// ����������Ϣ
		msg = GetMouseMsg();					// ��ȡ����¼�
		OnMouseMoveButton(msg.x, msg.y);		// ����ƶ�����ť��
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			OnLeftButtonDown(msg.x, msg.y);		// ����������
			edit.PaintEdit();					// �ػ�༭��
			break;
		default:
			break;
		}
		if (String.length() == 0) {
			flag = false;
		}
	}
}

bool GCount::OnLocate(int x, int y)
{
	int n1 = 0, n2 = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	// ��λ���
	if (x >= 20 && x <= 540) {
		if ((y >= 100 && y <= 430) || (x <= 200 && y >= 450 && y <= 500)) {
			x1 = (x - 20) / 100;
			y1 = (y - 100) / 70;
			x2 = floor((x - 100) / 100.0);
			y2 = floor((y - 150) / 70.0);
		}

		// �ɹ���λi�ٰ�ť��
		if (x1 != x2 && y1 != y2 && (y >= 100)) {
			// �޸ĵ�ǰ��ť
			xNow = x1;
			yNow = y1;
			return true;
		}
	}

	// λ�� Clear ��ť�ڲ�
	if ((x > 220 && x <= 540) && (y >= 450 && y <= 500)) {
		xNow = 2;
		yNow = 5;
		return true;
	}

	// λ�� == ��ť�ڲ�
	if ((x >= 20 && x <= 540) && (y >= 520 && y <= 570)) {
		xNow = 3;
		yNow = 5;
		return true;
	}
	// ��λʧ��
	return false;
}

void GCount::OnMouseMoveButton(int x, int y)
{
	bool isLocate = OnLocate(x, y);
	if (isLocate) {
		// �ָ�ǰһ����ť�ı߿���ɫ
		button[yPre][xPre].PainButtonWall(LIGHTGRAY);

		// ����ǰһ�ΰ�ť��ֵ
		xPre = xNow;
		yPre = yNow;

		// ���Ƶ�ǰ��ť�ı߿���ɫ
		button[yNow][xNow].PainButtonWall(LIGHTGREEN);
	}
}

// ����������
void GCount::OnLeftButtonDown(int x, int y)
{
	bool isLocate = OnLocate(x, y);
	//printf("%d\n", isLocate);
	if (isLocate) {
		// ��ť�ϵ�һ����ĸ
		switch (button[yNow][xNow].ReturnButtonString()[0]) {
			// ����༭��
		case 'C':
			String = "";
			OnSetData();
			break;
			// ����������������ʹ���� '+' ��, һ����������, һ������ļӺ�
		case '+':
			if (button[yNow][xNow].ReturnButtonString()[1] == '/') {
				if (String[0] != '-') {
					String = '-' + String;
				}
				else {
					String = String.substr(1, String.length());
				}
				left = String;
			}
			// ������ϻ������ʹ������������, �����һ���ַ�Ϊ-��Ҳ���Խ���+����
			else if (!flag || oper == '=' || String[0] == '-') {
				flag = true;
				oper = '+';
				left = String;
				String += button[yNow][xNow].ReturnButtonString();
			}
			break;
		case '-':
		case '/':
		case '%':
		case '*':
			// ���ϻ������ԭ��ͬ��
			if (!flag || oper == '=')
			{
				flag = true;
				oper = button[yNow][xNow].ReturnButtonString()[0];
				left = String;
				String += button[yNow][xNow].ReturnButtonString();
			}
			break;
		// ����һ���ַ�
		case '<':
			String = String.substr(0, String.length() - 1);
			break;
		// ����
		case '=':
			OnCompute();
			break;
		// ��ƽ��
		case 'x':
			if (!flag || oper == '=') {
				flag = true;
				OnSqu();
			}
			break;
		// ָ������
		case 'e':
			if (!flag || oper == '=') {
				flag = true;
				OnExp();
			}
			break;
		// ����
		case 'r':
			if (!flag || oper == '=') {
				flag = true;
				OnRec();
			}
			break;
		// ��ƽ����
		case 's':
		{
			if (flag == false || oper == '=')
			{
				flag = true;
				OnSqr();											// ��ƽ��
			}
			break;
		}
		// С����
		case '.':
			// ������ڵ�String��û��С����
			if (count(String.begin(), String.end(), '.') == 0) {
				String += '.';
			}
			else if (count(String.begin(), String.end(), '.') == 1) {
				if (left != "" && oper != '0') {
					String += '.';
				}
			}
			else if (flag == true && oper == '=') {
				String = "";
				flag = false;
			}

			break;
		// ���0�����
		case '0':
			// �����һ���ַ���0�������ܳ���Ϊ1
			if (String.length() > 1 && (String[0] != '0' || String[1] != 0)) {
				String += '0';
			}
			else if (String.length() == 0) {
				String += '0';
			}
			break;
		default:
			if (flag && oper == '=') {
				String = "";
				flag = false;
			}
			String += button[yNow][xNow].ReturnButtonString();
			break;
		}
	}
	// ���±༭�������
	edit.SetEditString(String);
}

// �������һ�μ��������, һЩ���ݵ�����
void GCount::OnSetData()
{
	int length = 0;
	left = "";
	right = "";
	number1 = number2 = 0.0;
	oper = '=';

	// ��String������0ȥ��
	for (int i = String.length() - 1; i > 0; --i) {
		if (String[i] == '0' || String[i] == 46) {
			++length;
		}
		else {
			break;
		}
	}
	String = String.substr(0, String.length() - length);
}

void GCount::OnCompute()
{
	// ����ַ����ǿ�
	if (!String.empty()) {
		right = String.substr(left.length() + 1, String.length());
	}
	// ������Ҳ���������Ϊ��
	if (!left.empty() && !right.empty()) {
		switch (oper)
		{
		case '+':
			OnAdd();			// �ӷ�����
			break;
		case '-':
			OnSub();			// ��������
			break;
		case '*':
			OnMul();			// �˷�����
			break;
		case '/':
			OnDiv();			// ��������
			break;
		case '%':
			OnMod();			// ȡģ����
			break;
		default:

			break;
		}
		oper = '=';
	}
}

void GCount::OnAdd()
{
	// �������Ҳ�����
	number1 = atof(left.c_str());
	number2 = atof(right.c_str());
	number1 += number2;

	// ����ʱ��
	sprintf_s(str1, "%lf", number1);
	String = str1;
	OnSetData();
}

void GCount::OnSub()
{
	// �������Ҳ�����
	number1 = atof(left.c_str());
	number2 = atof(right.c_str());
	number1 -= number2;

	// ����ʱ��
	sprintf_s(str1, "%lf", number1);
	String = str1;
	OnSetData();
}

void GCount::OnMul()
{
	// �������Ҳ�����
	number1 = atof(left.c_str());
	number2 = atof(right.c_str());
	number1 *= number2;

	// ��������
	sprintf_s(str1, "%lf", number1);
	String = str1;

	OnSetData();
}

void GCount::OnDiv()
{
	// �������Ҳ�����
	number1 = atof(left.c_str());
	number2 = atof(right.c_str());

	// �Ҳ���������Ϊ 0 
	if (number2 != 0)
	{
		number1 /= number2;
		sprintf_s(str1, "%lf", number1);
		String = str1;
	}
	else
	{
		String = _T("����! ����Ϊ0");
	}

	OnSetData();
}

void GCount::OnMod()
{
	// �������Ҳ�����
	number1 = atof(left.c_str());
	number2 = atof(right.c_str());

	// �Ҳ���������Ϊ 0
	if (number2 != 0)
	{
		number1 = fmod(number1, number2);
		sprintf_s(str1, "%lf", number1);
		String = str1;
	}
	else
	{
		String = _T("����! ģ��Ϊ0");
	}

	OnSetData();
}

void GCount::OnSqu()
{
	// �����������
	left = String;
	number1 = atof(left.c_str());
	number1 = number1 * number1;

	// ��������
	sprintf_s(str1, "%lf", number1);
	String = str1;

	OnSetData();
}

void GCount::OnExp()
{
	// �����������
	left = String;
	number1 = atof(left.c_str());
	number1 = exp(number1);

	// ��������
	sprintf_s(str1, "%lf", number1);
	String = str1;

	OnSetData();
}

void GCount::OnRec()
{
	// �����������
	left = String;
	number1 = atof(left.c_str());
	if (number1 != 0) {
		number1 = 1 / number1;

		// ��������
		sprintf_s(str1, "%lf", number1);
		String = str1;
	}
	else {
		String = _T("����! 0��������");
	}


	OnSetData();
}

void GCount::OnSqr()
{
	// �����������
	left = String;
	number1 = atof(left.c_str());

	// ����������ΪС�� 0 
	if (number1 >= 0)
	{
		number1 = sqrt(number1);
		sprintf_s(str1, "%lf", number1);
		String = str1;
	}
	else
	{
		String = _T("����! ���ܿ�ƽ��");
	}

	OnSetData();
}
