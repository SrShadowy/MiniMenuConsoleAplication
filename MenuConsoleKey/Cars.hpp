#include "head.h"

POINT Tam;
POINT sq = { 40,45 };
POINT gamePos;
int points = 0;
int position = 5;


POINT PlayerPos;
int vidaPlayer = 3;
void playercar()
{
	setCursorPosition(PlayerPos.x, gamePos.y);
	setConsoleColour(0x4);
	std::cout << "#";
	setCursorPosition(PlayerPos.x - 1, gamePos.y + 1);
	std::cout << "###";
	setCursorPosition(PlayerPos.x, gamePos.y + 2);
	std::cout << "#";
	setCursorPosition(PlayerPos.x - 1, gamePos.y + 3);
	std::cout << "# #";
}


void maximize_window()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
}

class EnimyCar
{
public:
	EnimyCar();
	void Run();
	void destroyme();
	int y = sq.y - (sq.y - 2);
	int velo = 1;

private:
	int pox_max = sq.x;
	int pox_min = sq.x - (sq.x - 3);
	int x = rand() % pox_max + pox_min;
};


EnimyCar::EnimyCar()
{


}

void EnimyCar::Run()
{

	setCursorPosition(x, y);
	setConsoleColour(0x3C);
	std::cout << "#";
	setCursorPosition(x - 1, y + 1);
	std::cout << "###";
	setCursorPosition(x, y + 2);
	std::cout << "#";
	setCursorPosition(x - 1, y + 3);
	std::cout << "###";
	y += velo;

	if (GetAsyncKeyState(VK_UP)) y += 1;

	if ((y + 2) >= PlayerPos.y && x <= PlayerPos.x + 2 && x >= PlayerPos.x - 2)
	{
		--vidaPlayer;
		destroyme();
	}

	if (y >= sq.y)
		destroyme();

}

void EnimyCar::destroyme()
{
	y = sq.y - (sq.y - 2);
	pox_max = sq.x - 2;
	pox_min = sq.x - (sq.x - 3);
	x = rand() % pox_max + pox_min;
	points += 2;
}



int x = 0;
EnimyCar Car1;
EnimyCar Car2;
EnimyCar Car3;
EnimyCar Car4;
EnimyCar Car5;
bool loser = true;

void DrawnPist()
{
	setCursorPosition(5, 1);
	std::cout << "Pontos: " << points << " Vidas: " << vidaPlayer;
	square(sq.x, sq.y, 2, 1, 2);
	Car1.Run();
	if (points > 20)
		Car2.Run();
	if (points > 50)
		Car3.Run();
	if (points > 250)
		Car4.Run();
	if (points > 550)
		Car5.Run();

	playercar();
	if (GetAsyncKeyState(VK_RIGHT))
	{
		++PlayerPos.x;
		if (PlayerPos.x >= sq.x) PlayerPos.x = sq.x;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		--PlayerPos.x;
		if (PlayerPos.x <= sq.x - (sq.x - 3)) PlayerPos.x = sq.x - (sq.x - 3);
	}



	std::cout.flush();
}


void game_car()
{
	
	Car2.velo = 2;
	Car3.velo = 4;
	Car4.velo = 2;
	Car5.velo = 4;
	while (loser)
	{
		srand((unsigned)time(NULL));
		DrawnPist();
		setConsoleColour(0xA0);
		vidaPlayer <= 0 ? loser = false : loser = true;

		Sleep(50);
	}
	cls();
	std::cout << "Voce perdeu\nSua pontacao eh: " << points;
}

void MenuCar()
{

	cls();
	
	maximize_window();
	Tam.x = 2;
	Tam.y = 2;
	gamePos.x = (sq.x / 2);
	gamePos.y = (sq.y - 4);
	PlayerPos.x = gamePos.x;
	PlayerPos.y = gamePos.y;
	TrackBar CarVida("Vidas", 1, 10);

	bool change = true;
	int pos = 0;
	int max = 0;
	bool menu = true;
	while (menu)
	{
		if (change)
		{
			int i = 0;
			std::cout << "\t Game de carrinhos";
			square(30, 4, 2, 0, 1);
			setCursorPosition(3, 2);
			CarVida.Show(pos);
			++i;

			setCursorPosition(3, 4);
			pos == i ? std::cout << "> " << "Start" << std::endl
				: std::cout << "  " << "Start" << std::endl;

			std::cout.flush();
			max = i;
			change = false;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			--pos;
			if (pos < 0)
				pos = max;
			change = true;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			++pos;
			if (pos > max)
				pos = 0;
			change = true;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			CarVida.changeValue(pos);
			vidaPlayer = CarVida.value;

			if (pos == max) menu = !menu;
			change = true;
		}


		Sleep(100);
	}
	cls();
	game_car();
}