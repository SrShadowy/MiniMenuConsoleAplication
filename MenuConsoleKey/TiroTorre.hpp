#pragma once
#include "head.h"

POINT quadrado = { 30,15 };
int downSpeed = 1;

class Bullet
{
public:
	Bullet(){}
	Bullet(int x, int y)
	{
		bx = x;
		by = y;
	}
	void shoot();
	bool finish = false;
	int bx = 0;
	int by = 0;
private:
	std::string bullet = "|";
	int velo = 1;
};

void Bullet::shoot()
{
	setCursorPosition(bx, by);
	std::cout << bullet;
	by -= velo;

	if (by <= 0) 
	{
		by = 99;
		finish = false;;
	}
		
}

int tiro_points = 0;
int tiro_vida = 1;

class Player
{
public:
	Player(){}
	void me();
	void setVida(int qtVida)
	{
		tiro_vida += qtVida;
	}
	void incPoint(int moreP)
	{
		tiro_points += moreP;
	}

	int  showPoints()
	{
		return tiro_points;
	}
	std::vector<Bullet> myShoot = { Bullet() };

	int mybullets()
	{
		return	myShoot.size();
	}
	void incBullets()
	{
		myShoot.push_back({ Bullet() });
	}
	
	int x = (quadrado.x / 2) - 2;
	int y = quadrado.y - 3;

private:
	
	
};

inline void Player::me()
{

	setCursorPosition(x, y);
	std::cout << " @";
	setCursorPosition(x, y + 1);
	std::cout << "@@@";

	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < mybullets(); ++i)
		{
			if (!myShoot[i].finish)
			{
				myShoot[i] = Bullet(x + 1, y - 1);
				myShoot[i].finish = true;
				break;
			}
		}

	}

	if (GetAsyncKeyState('a') || GetAsyncKeyState('A'))
	{
		--x;
		if (x <= quadrado.x - (quadrado.x - 1)) x = quadrado.x - (quadrado.x - 1);
	}

	if (GetAsyncKeyState('d') || GetAsyncKeyState('D'))
	{
		++x;
		if (x >= quadrado.x - 2) x = quadrado.x - 2;
	}

	for (int i = 0; i< mybullets(); ++i)
	{
		if (myShoot[i].finish)
		{
			myShoot[i].shoot();
		}
	}

}


class Bloco
{
public:
	Bloco()
	{
		srand((unsigned)time(NULL));
		posXBloco = rand() % quadrado.x + 1;;
	}
	Bloco(int posBlc)
	{
		posXBloco = posBlc;
		if (posXBloco > quadrado.x) posXBloco -= quadrado.x;
	}
	void showBloco(Player PB);
	void updateBloco();
	
	bool destroy = false;
private:
	std::string bloco = "#";
	int va = 1;
	int posXBloco = 0;

};

inline void Bloco::showBloco(Player PB)
{
	setCursorPosition(posXBloco, va);
	
	for(auto bullet : PB.myShoot)
	{ 
		if (bullet.bx == posXBloco && bullet.by == va)
		{
			PB.incPoint(2);
			destroy = true;
		}
	}
	if (posXBloco <= PB.x + 1 && posXBloco >= PB.x - 1 && va <= PB.y)
	{
		PB.setVida(-1);
		destroy = true;
	}
	
	std::cout << bloco;
	std::cout.flush();
}

inline void Bloco::updateBloco()
{
	va+= downSpeed;
	if (va > quadrado.y)
		va = 0;
}


int update = 50;
void gaming()
{
	cls();
	Player Me;
	Me.incBullets();
	Me.incBullets();
	std::vector<Bloco> blocks;
	blocks.push_back({});
	int count = 0; // 50 counts of 50ms new block 
	bool lose = true;
	while(lose)
	{
		square(quadrado.x, quadrado.y, 1, 0, 0);
		if (count >= update)
		{
			for (size_t i = 0; i < blocks.size(); i++)
				blocks[i].updateBloco();

			int newblocs = rand() % quadrado.x + 1;
			if (newblocs > 1)
			{
				for(int i = 0; i < newblocs; ++i)
					blocks.push_back({newblocs+i});
			}

			blocks.push_back({});
			count = 0;
		}
		for (size_t i = 0; i < blocks.size(); i++)
		{
			blocks[i].showBloco(Me);

			if (blocks[i].destroy)
				blocks.erase(blocks.begin() + i);
		}

		Me.me();
		setCursorPosition(0 , quadrado.y+1);
		std::cout << "Pontos:"<< Me.showPoints();
		std::string thisBullets = "";
		for (size_t i = 0; i < Me.mybullets(); i++)
			thisBullets += "/";
		
		setCursorPosition((quadrado.x / 2), quadrado.y + 1);
		std::cout <<"Vida: " << tiro_vida << " Balas: " << thisBullets;
		if (tiro_vida < 0) lose = false;
		std::cout.flush();
		

		count++;
		Sleep(50);
	}
	cls();
	std::cout << "Voce perdeu sua pontuacao eh: " << tiro_points << std::endl;

}

void Menu_tiro()
{
	cls();

	bool change = true;
	int pos = 0;
	int max = 0;
	bool menu = true;
	TrackBar velo("Velocidade", 1, 10, update/10 , 0);

	while (menu)
	{
		if (change)
		{
			int i = 0;
			std::cout << "\t Game de nave";
			square(30, 4, 2, 0, 1);
			setCursorPosition(3, 2);
			velo.Show(pos);
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
			velo.changeValue(pos);
			update = velo.value * 10;
			if (pos == max) menu = !menu;
			change = true;
		}


		Sleep(100);
	}
	cls();
	gaming();

}