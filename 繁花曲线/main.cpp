#include <stdio.h>
#include <easyx.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <tchar.h>
#define PI 3.1415926

int fgbs(int n1, int n2) {
	int hcf, temp, lcm;


	hcf = n1;
	temp = n2;

	while (hcf != temp)
	{
		if (hcf > temp)
			hcf -= temp;
		else
			temp -= hcf;
	}

	lcm = (n1 * n2) / hcf;

	return lcm;
}

inline void calcDrawingPoint(long & resX, long & resY, long cenX, long centY, float angleRotation, float angleRevolution, float radiusInner, float radiusDraw) {
	long innerCenterX = sin(angleRevolution) * radiusInner;
	long innerCenterY = cos(angleRevolution) * radiusInner;

	long drawX = innerCenterX + sin(angleRotation) * radiusDraw;
	long drawY = innerCenterY + cos(angleRotation) * radiusDraw;

	resX = cenX + drawX;
	resY = centY + drawY;

}

void initRand() {
	srand((int)time(0));
}

void swapInteger(int * a, int * b) {
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;;
}

int getNextRandomInteger(int min, int max) {
	if (min > max) {
		swapInteger(&min, &max);
	}
	return (rand() % (max - min)) + min;
}

void drawSth() {
	float radiusBig = 400;//���ְ뾶
	initgraph(radiusBig * 2, radiusBig * 2);	// ������ͼ���ڣ���СΪ 640x480 ����

	for (int t = 0; t < 5; t++) {
		//float radiusSmall = 105;//���ְ뾶
		float radiusSmall = getNextRandomInteger(40, radiusBig - 20);
		//float toSide = 20;//���ֻ���߾�
		float toSide = getNextRandomInteger(3, radiusSmall - 20);
		long radiusScale = 10;//�ǶȷŴ���
		long stepRadiusScaled = 1;//��ͼ����

		//ÿȦ�Դ��Ƕ� ��Ԫ����СԲʱ,��ת���Ƕ�,��������,����ΪСԲת��Ȧ��,����360��Ϊ�Ƕ�(СԲΪ����ת��)
		float innerSelfRadiusPerRound = 0.0 - ((radiusBig - radiusSmall) * 2 * PI / radiusSmall);
		//ÿȦ��ת�Ƕ�
		float innerPublicRadiusPerRound = 2 * PI;

		float toCenter = radiusSmall - toSide;//���ֻ���ƫ�ľ�


		//circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
		//circle(radiusBig, radiusBig, radiusBig);
		int cr = getNextRandomInteger(10, 255);
		int cg = getNextRandomInteger(10, 255);
		int cb = getNextRandomInteger(10, 255);
		setlinecolor(RGB(cr, cg, cb));

		//linerel(10, 10);
		//lineto(20, 15);
		//lineto(25, 30);

		//��������ԭ��
		float outCx = radiusBig;
		float outCy = radiusBig;

		//�������ֳ�ʼԭ��
		//float innerC0x = outCx - radiusBig + radiusSmall;
		//float innerC0y = outCy;

		float ric = 0;//����Բ��λ�ýǶ�
		float rid = 0;//���ֻ�оλ�ýǶ�

		int gbs = fgbs(radiusBig, radiusSmall);

		int pass = gbs / radiusBig;//�ܹ�Ҫ����Ȧת����Ȧ

		printf("%d\n", pass);

		if (pass > 120) {//Ȧ������,����
			t--;
			continue;
		}

		//double passed = 0;
		long roundStepNum = 360 * radiusScale; //ÿԲ����
		long totalStepNum = roundStepNum * pass;
		long currentStepIdx = 0; //��ǰ�����α�
		while (currentStepIdx < totalStepNum) {
			long dx = 0;
			long dy = 0;
			ric = (currentStepIdx / (360.0 * radiusScale)) * innerPublicRadiusPerRound;
			rid = (currentStepIdx / (360.0 * radiusScale)) * innerSelfRadiusPerRound;
			calcDrawingPoint(dx, dy, outCx, outCy, rid, ric, radiusBig - radiusSmall, toCenter);

			//printf_s("currentStepIdx:%ld,rid:%f,ric:%f,X:%ld,Y:%ld\n", currentStepIdx,rid,ric, dx, dy);

			if (currentStepIdx) {//�ǵ�һ����
				lineto(dx, dy);
			}
			else {
				printf("moverel\n");
				moveto(dx, dy);
				lineto(dx, dy);
			}

			currentStepIdx += stepRadiusScaled;
		}
	}

	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
}

int main()
{
	initRand();
	drawSth();
	return 0;
}

