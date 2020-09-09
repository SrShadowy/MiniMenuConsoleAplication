#include "head.h"
//My Vars
bool atravessar = true;
bool cobra_tail = false;
int vida = 1;
int score = 0;

int drawnX = 35;
int drawnY = 15;

//Snake vars
POINT playerPos = { drawnX / 2,drawnY / 2 };
bool  positions[4] = {};
int   tam = 1;
std::vector<int> posX;
std::vector<int> posY;
int anteriorX, anteriorX2;
int anteriorY, anteriorY2;


void player()
{
	if (atravessar)
	{
		if (playerPos.x >= drawnX + 1)
			playerPos.x = 2;
		if (playerPos.y >= drawnY + 1)
			playerPos.y = 2;

		if (playerPos.x <= 1)
			playerPos.x = drawnX;
		if (playerPos.y <= 1)
			playerPos.y = drawnY;
	}
	else
	{
		if (playerPos.x >= drawnX || playerPos.x <= 0 || playerPos.y >= drawnY || playerPos.y <= 0)
		{
			--vida;
			playerPos = { drawnX / 2,drawnY / 2 };
		}
		for (int i = 0; i < tam; ++i)
			if (playerPos.x == posX[i] && playerPos.y == posY[i])
				--vida;
	}

	setCursorPosition(playerPos.x, playerPos.y);
	setConsoleColour(0xE);
	std::cout << "*";


	if (cobra_tail)
	{

	}

	anteriorX = posX[0];
	anteriorY = posY[0];
	posX[0] = playerPos.x;
	posY[0] = playerPos.y;

	for (int i = 1; i < tam; i++)
	{
		setCursorPosition(anteriorX, anteriorY);
		std::cout << '#';

		anteriorX2 = posX[i];
		anteriorY2 = posY[i];
		posX[i] = anteriorX;
		posY[i] = anteriorY;
		anteriorX = anteriorX2;
		anteriorY = anteriorY2;

	}

	std::cout.flush();
}

int xFrute = rand() % (drawnX - 2) + 1;
int yFrute = rand() % (drawnY - 2) + 1;

void frute(POINT player)
{
	setCursorPosition(xFrute, yFrute);
	setConsoleColour(0xC);
	std::cout << 'o';
	if (player.x == xFrute and player.y == yFrute)
	{
		score += 5;
		++tam;
		posX.push_back(0);
		posY.push_back(0);
		xFrute = rand() % (drawnX - 2) + 2;
		yFrute = rand() % (drawnY - 2) + 2;
	}
	std::cout.flush();
}

void snake()
{
	
	posX.push_back(0);
	positions[2] = true;
	posY.push_back(0);
	srand((unsigned)time(NULL));
	square(35, 15, 1, 1, 1);
	bool pause = true;
	bool quit = true;
	while (quit)
	{

		if (GetAsyncKeyState('p') || GetAsyncKeyState('P'))
			pause = !pause;

		setCursorPosition(0, 0);
		std::cout << "  Vida: " << vida << "\t\tPontos: " << score;
		if (pause)
		{
			square(drawnX, drawnY, 1, 1, 1);


			if (vida <= 0)
				quit = false;

			if (GetAsyncKeyState(VK_UP))
			{
				for (int i = 0; i < 4; ++i) positions[i] = false;
				positions[0] = true;
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				for (int i = 0; i < 4; ++i) positions[i] = false;
				positions[1] = true;
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				for (int i = 0; i < 4; ++i) positions[i] = false;
				positions[2] = true;
			}

			if (GetAsyncKeyState(VK_LEFT))
			{
				for (int i = 0; i < 4; ++i) positions[i] = false;
				positions[3] = true;
			}


			if (positions[0]) //Up
				--playerPos.y;
			if (positions[1]) //Down
				++playerPos.y;
			if (positions[2]) //Esquerda
				++playerPos.x;
			if (positions[3]) //Direita
				--playerPos.x;


			player();
			frute(playerPos);
		}
		std::cout.flush();
		Sleep(50);
	}

}


void menu_snake()
{
	cls();
	bool change = true;
	checkbox check_atr("Atravessar", atravessar);
	TrackBar Vidas("vidas", 1, 10, vida, 1);
	int pos = 0;
	int max = 0;
	bool menu = true;
	while (menu)
	{
		if (change)
		{
			int i = 0;
			std::cout << "\t Game da cobrinha";
			square(30, 4, 2, 0, 1);
			setCursorPosition(3, 2);
			check_atr.show(pos);
			++i;

			setCursorPosition(3, 3);
			Vidas.Show(pos);
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
			check_atr.ChangeValue(pos);
			Vidas.changeValue(pos);

			atravessar = check_atr.check;
			vida = Vidas.value;
			if (pos == max) menu = !menu;
			change = true;
		}

		Sleep(100);
	}
	cls();
	snake();
	cls();
	std::cout << "O jogo acabou sua pontuacao eh: " << score;
	std::cout << std::endl;
}
