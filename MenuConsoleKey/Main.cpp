#include "head.h"
const char* space = "\t\t";
HWND console = nullptr;
POINT PosConsole = { 200,200 };
POINT sizeConsole = { 300,200 };

void move_console(int pos, int max)
{
	if (pos == max)
	{
		system("cls");
		std::cout << "\nUSE ARRAW TO MOVE CONSOLE\nSpace increcent the speed\nAND USE F2 TO EXIT MOVE";
	bool finish = false;
		while (!finish)
		{
			SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x , sizeConsole.y, NULL);
			int speed = 1;
			if (GetAsyncKeyState(VK_SPACE))
				speed += 2;

			if (GetAsyncKeyState(VK_UP))				
				PosConsole.y -= speed;
			
			if (GetAsyncKeyState(VK_DOWN))
				++PosConsole.y += speed;
				
			
			if (GetAsyncKeyState(VK_RIGHT))
				PosConsole.x += speed;
			
			if (GetAsyncKeyState(VK_LEFT))
				PosConsole.x -= speed;
			
			if (GetAsyncKeyState(VK_F2))
				finish = true;
			Sleep(1);
		}
	}
}

void loading()
{
	ProgressBar prog("", 0, 0);
	bool exit = true;
	while (exit)
	{
		//cls();
		setCursorPosition(0, 0);
		if (prog.value < 25)
			setConsoleColour(0x4);
		else if (prog.value < 50)
			setConsoleColour(0xE);
		else
			setConsoleColour(0xA);

		std::cout << "LOADING..." << std::endl;
		prog.Show(0);
		Sleep(10);
		prog.ChangeValue(0);
		std::cout.flush();
		if (prog.value == 100.0F)
			exit = false;
	}

}

void menu()
{
	cls();
	setConsoleColour(0x7);
	bool change = true;
	bool finish = false;
	int pos = 0;
	int max = 0;
	checkbox checkbox1("caixa1");
	checkbox checkbox2("checked", true);
	TextEdit text1("Texto","Shadowy");
	TrackBar trackbar1("Num", 0, 10);
	ComboBox cb1("Textos");



	std::string Shadow[5] = { "","\xB0","\xB1","\xB2"," " };
	std::string  Style[5][12] = {
	{""," "," "," "," "," "," "," "," "," "," "," " },
	{"","\xDA","\xC4","\xBF","\xB3","\xD9","\xC0","\xC3","\xB4","\xC2","\xB3","\xC1"},
	{"","\xC9","\xCD","\xBB","\xBA","\xBC","\xC8","\xCC","\xB9","\xCB","\xBA","\xCA"},
	{"","\xD5","\xCD","\xB8","\xB3","\xBE","\xD4","\xC6","\xB9","\xD1","\xB3","\xCF"},
	{"","\xD6","\xC4","\xB7","\xBA","\xBD","\xD3","\xC7","\xC6","\xD2","\xBA","\xD0"}
	};

	while (!finish)
	{
		if (change)
		{
			setCursorPosition(0, 0);
			std::cout << Style[2][1];
			for (int i = 0; i < 30; ++i) std::cout << Style[2][2];
			std::cout << Style[2][3];
			int line = 1;
			for (line = 1; line < 9; ++line)
			{
				setCursorPosition(0, line);
				std::cout << Style[2][4];
				for (int i = 0; i < 30; ++i) std::cout << " ";
				std::cout << Style[2][4];
			}
			setCursorPosition(0, 9);
			std::cout << Style[2][6];
			for (int i = 0; i < 30; ++i) std::cout << Style[2][2];
			std::cout << Style[2][5];
			
			setCursorPosition(8, 0);
			size_t i = 0;
			setConsoleColour(FOREGROUND_BLUE);
			std::cout << "Menu\r";
			setCursorPosition(10, 1);
			setConsoleColour(FOREGROUND_RED);
			std::cout << "Shadowy\r";
			setConsoleColour(0x7);
			std::cout << std::endl;
			setCursorPosition(2, 2);
			checkbox1.show(pos);
			++i;
			setCursorPosition(2, 3);
			checkbox2.show(pos);
			++i;
			setCursorPosition(2, 4);
			text1.show(pos);
			++i;
			setCursorPosition(2, 5);
			trackbar1.Show(pos);
			++i;
			setCursorPosition(2, 6);
			cb1.Show(pos);
			++i;
			setCursorPosition(2, 7);
			pos == i ? std::cout << "> "<< "MOVE MENU" << "\n"
				: std::cout << "  " << "MOVE MENU" << "\n";
			++i;
			setCursorPosition(2, 8);
			pos == i ? std::cout << "> " << "Exit" << "\n"
				: std::cout << "  " << "Exit" << "\n";
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
		if (GetAsyncKeyState(VK_RIGHT))
		{

			checkbox1.ChangeValue(pos);
			checkbox2.ChangeValue(pos);
			text1.changeValue(pos);
			trackbar1.changeValue(pos);
			cb1.ChangeValue(pos);
			move_console(pos, max-1);
			pos == max ? finish = true : finish = false;
			change = true;
		}

		setCursorPosition(15,8);
		setConsoleColour(FOREGROUND_BLUE);
		std::cout << "Menu";
		setCursorPosition(16,9);
		setConsoleColour(FOREGROUND_RED);
		std::cout << "Shadowy";
		setConsoleColour(0x7);
		std::cout.flush();
		Sleep(100);
	}
}

int main()
{
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE,  WS_BORDER   );
	ShowWindow(console, SW_SHOW);
	ExConsole();
	loading();
	menu();
	return 0;
}