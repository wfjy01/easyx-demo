#include <graphics.h>
#include <conio.h>

#define WIDTH 40//�������ʮ������
#define HEIGHT 30
#define SIZE 20

int Blocks[WIDTH][HEIGHT] = { 0 };
char moveDirection, oldMoveDirection;
int foodX, foodY;
int isFailure = 0;

void initGame();
void show();//ÿһ������ʱ���»����ߺ�ʳ���ͼ��
void updateWithInput();//�������йصĸ���
void updateWithoutInput();//�������޹صĸ���
void moveSnake();//���˶�

int main() {
	initGame();
	while (1) {
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}

void initGame() {
	initgraph(WIDTH * SIZE, HEIGHT * SIZE, 1);
	setbkcolor(LIGHTGRAY);
	BeginBatchDraw();
	cleardevice();
	setlinecolor(WHITE);
	int i;
	for (i = SIZE; i < WIDTH * SIZE; i += SIZE)
		line(i, 0, i, HEIGHT * SIZE);
	for (i = SIZE; i < HEIGHT * SIZE; i += SIZE)
		line(0, i, WIDTH * SIZE, i);
	moveDirection = oldMoveDirection = 'd';
	Blocks[WIDTH / 2][HEIGHT / 2] = 1;
	for (i = 1; i < 4; i++)
		Blocks[WIDTH / 2 - i][HEIGHT / 2] = i + 1;
	foodX = rand() % (WIDTH - 2) + 1;//1��38
	foodY = rand() % (HEIGHT - 2) + 1;
}

void show() {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (Blocks[i][j] != 0)
				setfillcolor(HSVtoRGB((float)(Blocks[i][j] * 10), 0.9f, 1.0f));
			else
				setfillcolor(LIGHTGRAY);
			fillrectangle(i * SIZE, j * SIZE, (i + 1) * SIZE, (j + 1) * SIZE);
		}
	}
	setfillcolor(LIGHTGREEN);
	fillrectangle(foodX * SIZE, foodY * SIZE, (foodX + 1) * SIZE, (foodY + 1) * SIZE);

	if (isFailure) {
		settextcolor(LIGHTRED);
		settextstyle(80, 0, _T("����"));
		setbkmode(TRANSPARENT);
		outtextxy(240, 220, _T("��Ϸʧ��"));
	}

	FlushBatchDraw();
}

void updateWithInput() {
	if (_kbhit() && !isFailure) {
		char input = _getch();
		if (input == 'a' || input == 's' || input == 'd' || input == 'w') {
			moveDirection = input;
			if (moveDirection == 'a' && oldMoveDirection == 'd')
				moveDirection = 'd';
			else if (moveDirection == 's' && oldMoveDirection == 'w')
				moveDirection = 'w';
			else if (moveDirection == 'd' && oldMoveDirection == 'a')
				moveDirection = 'a';
			else if (moveDirection == 'w' && oldMoveDirection == 's')
				moveDirection = 's';
			else oldMoveDirection = input;
			moveSnake();
		}
	}
}

void updateWithoutInput() {
	if (isFailure)
		return;
	static int waitIndex = 1;
	waitIndex++;
	if (waitIndex == 6) {
		moveSnake();
		waitIndex = 1;
	}
}

void moveSnake() {
	int i, j;
	//�ճ����������
	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++)
			if (Blocks[i][j] != 0)
				Blocks[i][j]++;
	//Ѱ�Ҿ���ͷ�;���β��xy����
	int oldHeadX, oldHeadY, oldTailX, oldTailY;
	int tailBlocks = 0;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			if (tailBlocks < Blocks[i][j]) {
				tailBlocks = Blocks[i][j];
				oldTailX = i;
				oldTailY = j;
			}
			if (Blocks[i][j] == 2) {
				oldHeadX = i;
				oldHeadY = j;
			}
		}
	}
	//�����ߵ��ƶ���������ֵ����ͷ��xy����
	int newHeadX = oldHeadX, newHeadY = oldHeadY;
	switch (moveDirection) {
	case'a':
		newHeadX -= 1;
		break;
	case 's':
		newHeadY += 1;
		break;
	case 'd':
		newHeadX += 1;
		break;
	case 'w':
		newHeadY -= 1;
		break;
	}
	//�ж���Ϸ�Ƿ�ʧ��
	if (newHeadX >= WIDTH || newHeadX < 0 || newHeadY >= HEIGHT || newHeadY < 0 || Blocks[newHeadX][newHeadY] != 0) {
		isFailure = 1;
		return;
	}
	//����ͷ�Ĵ���
	Blocks[newHeadX][newHeadY] = 1;
	//�ԳԵ�ʳ���Լ���β�Ĵ���
	if (newHeadX == foodX && newHeadY == foodY) {
		foodX = rand() % (WIDTH - 2) + 1;
		foodY = rand() % (HEIGHT - 2) + 1;
	}
	else
		Blocks[oldTailX][oldTailY] = 0;
}
