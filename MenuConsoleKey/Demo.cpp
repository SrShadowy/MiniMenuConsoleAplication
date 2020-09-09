#include "head.h"
#include "TiroTorre.hpp"
#include "snake.hpp"
#include "Cars.hpp"


int main()
{

	


	bool change = true;
	int pos = 0;
	int max = 0;
	bool menu = true;
	while (menu)
	{
		if (change)
		{
			int i = 0;
			std::cout << "\t Demo menu";
			square(30, 5, 2, 0, 1);
			setCursorPosition(3, 2);

			pos == i ? std::cout << "> " << "Cars" << std::endl
				: std::cout << "  " << "Cars" << std::endl;

			++i;

			setCursorPosition(3, 3);

			pos == i ? std::cout << "> " << "Snake" << std::endl
				: std::cout << "  " << "Snake" << std::endl;

			++i;

			setCursorPosition(3, 4);

			pos == i ? std::cout << "> " << "Nave" << std::endl
				: std::cout << "  " << "Nave" << std::endl;

			++i;

			setCursorPosition(3, 5);

			pos == i ? std::cout << "> " << "Sair" << std::endl
				: std::cout << "  " << "Sair" << std::endl;

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
			if ( pos == 0 )
				MenuCar();
			if (pos == 1)
				menu_snake();
			if (pos == 2)
				Menu_tiro();
			if (pos == max) menu = !menu;
			change = true;
		}


		Sleep(100);
	}
	cls();
	
	
	std::cin.get();
	
	
	return 0;
}
