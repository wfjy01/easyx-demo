#pragma once
class Game
{
	friend class Floor;
	friend class Ball;

public:
	Game();
	~Game();

	void start(); // ������Ϸ
	bool run;
	bool exit;   // �˳���ϷʱΪtrue
	bool restart; // ���¿�ʼ

	void Draw();
	void Move();
	void Act(double x0, double y0);
private:
	float FloorColor; 
	double speed;
	const double BASE_SPEED;
	const double SPEED;
	const double FLOOR_AFTER;
	const double FLOOR_BEFORE;

	void Init(); // ��ʼ��
	void Option();
	void addFloor(); 
	void DrawCosmo();
	void DrawFloor();
	void FloorColorChange();
	void deleteHeadFloor();
	void deleteAllFloor();
	void deleteCosmo();
	void Speed();
	bool JudgeNext();
	void JudgeDie();
	bool JudgeOut();

	void ChangeDirect();
	
	void PrintScore();
	bool $return();
	bool $restart();

	bool wait;
	void End();
	void Wait();
	void Play();
	void GetCommand();

	Floor* GetLastFloor();
	int score;
	Floor* headfloor;
	Ball* cosmo;
	void bkcolorgrad(COLORREF bkcolor);

	void sleep();
};

extern Game *game;
// �߳����ڻ���ͼ��
DWORD WINAPI Thread_MoveAndDraw(PVOID pMyPara);

