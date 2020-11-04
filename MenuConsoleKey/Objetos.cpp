#include "head.h"
#include "objetos.h"

UINT ID_itens = 0;
// Checkbox
void ExConsole()
{
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD NewSBSize;
	int Status;

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	NewSBSize.X = SBInfo.dwSize.X;
	NewSBSize.Y = SBInfo.dwSize.Y;

	Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
	if (Status == 0)
	{
		Status = GetLastError();
		std::cout << "SetConsoleScreenBufferSize() failed! Reason : " << Status << std::endl;
		exit(Status);
	}

	GetConsoleScreenBufferInfo(hOut, &SBInfo);
}
std::string Shadow[5] = { "","\xB0","\xB1","\xB2"," " };
std::string  Style[5][12] = {
{""," "," "," "," "," "," "," "," "," "," "," " },
{"","\xDA","\xC4","\xBF","\xB3","\xD9","\xC0","\xC3","\xB4","\xC2","\xB3","\xC1"},
{"","\xC9","\xCD","\xBB","\xBA","\xBC","\xC8","\xCC","\xB9","\xCB","\xBA","\xCA"},
{"","\xD5","\xCD","\xB8","\xB3","\xBE","\xD4","\xC6","\xB9","\xD1","\xB3","\xCF"},
{"","\xD6","\xC4","\xB7","\xBA","\xBD","\xD3","\xC7","\xC6","\xD2","\xBA","\xD0"}
};

void helpQuard()
{
	std::cout << "SHADOW" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << " " << Shadow[i];
	std::cout << std::endl;
	std::cout << "Quard type 1" << std::endl;
	for (int i = 0; i < 12; ++i)
		std::cout << Style[1][i];
	std::cout << std::endl;
	std::cout << "Quard type 2" << std::endl;
	for (int i = 0; i < 12; ++i)
		std::cout << Style[2][i];
	std::cout << std::endl;
	std::cout << "Quard type 3" << std::endl;
	for (int i = 0; i < 12; ++i)
		std::cout << Style[3][i];
	std::cout << std::endl;
	std::cout << "Quard type 4" << std::endl;
	for (int i = 0; i < 12; ++i)
		std::cout << Style[4][i];

}

void help()
{
	cls();
	std::cout << "Help command use HELP or ?\n";

	std::cout << "\t\t*HELP*\n";
	std::cout << "[quard] use this for drawn a square you need this paraments : widht, hight, type, Position X and Y\n";
	std::cout << "[SetCursorPosition] use this for set position for next text or drawn, paraments needed is : Position X and Y\n";
	std::cout << "[setConsoleColour] use this for set color for next text or drawn, paraments needed is : int color\n";
	std::cout << "[cls] use this for clear all text\n";
	std::cout << "[checkbox] Drawn one checkbox, for set true or false value return, paraments needed is : name, check, id\n";
	std::cout << "Or only Name, for use this is .show() and change value is .ChangeValue(POSITION)\n";
	std::cout << "[TextEdit] Drawn one TextEdit, for set new text value, paraments needed is: name, lenght , buffer, id\n";
	std::cout << "for show use .show(), and change value use .ChangeValue(POSITION)\n";
	std::cout << "[TrackBar] Drawn one TrackBar, for set value or change value, paraments needed is: name, min, max, value, id\n";
	std::cout << "Or only Name,  Min, Max, for show this use : .show(), and chenge value is .ChangeValue(POSIITION)\n";
	std::cout << "[ComboBox] Drawn one ComboBox, for set  new text value, paraments needed is: name, list, lenght, id\n";
	std::cout << "Or only Name, for show this use : .show(), and chenge value is .ChangeValue(POSIITION)\n";
	std::cout << "[ProgressBar] Drawn one progressBar, for show and value or load anything, paramets needed is: name, value, max and id\n";
	std::cout << "Or only Name, for show this use : .show(), and chenge value is .ChangeValue(POSIITION)\n";
}


void square(int width, int hight, int type, int posX, int posY)
{

	std::string space = std::string(width, ' ');
	//Desenha a primiera curva superior
	setCursorPosition(posX, posY);
	std::cout << Style[type][1];

	//Desenha a superior inferior horizontal
	for (int i = 0; i < width; ++i) std::cout << Style[type][2];
	//Desenha a segunda curva superior
	std::cout << Style[type][3];
	int line = 1;
	for (line = 1; line < hight; ++line)
	{
		//Desenha a primeira linha vertical
		setCursorPosition(posX, posY + line);
		std::cout << Style[type][4];

		//Limpa as linhas
		setCursorPosition(posX + 1, posY + line);
		std::cout << space;

		//Desenha a segunda linha vertical
		setCursorPosition(width + 1, posY + line);
		std::cout << Style[type][4];
	}
	//desenha a primeira curva inferior
	setCursorPosition(posX, posY + line);
	std::cout << Style[type][6];

	//Desenha a linha inferior horizontal
	for (int i = 0; i < width; ++i) std::cout << Style[type][2];
	//desenha a segunda curva inferior
	std::cout << Style[type][5];

}

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void setConsoleColour(unsigned short colour)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleTextAttribute(hOut, colour);
}

void cls()
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };
	std::cout.flush();
	if (!GetConsoleScreenBufferInfo(hOut, &csbi))
		abort();

	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
	SetConsoleCursorPosition(hOut, topLeft);
}

/*
* Name, check and id
*/
checkbox::checkbox(std::string name, bool check, int id)
{
	checkbox::check = check;
	checkbox::id = id;
	checkbox::name = name;
	++ID_itens;
}
/*
*	 Name and check
*/
checkbox::checkbox(std::string name, bool check)
{
	checkbox::check = check;
	checkbox::id = ID_itens;
	checkbox::name = name;
	++ID_itens;
}
/*
*	 Name only
*/
checkbox::checkbox(std::string name)
{
	checkbox::check = false;
	checkbox::id = ID_itens;
	checkbox::name = name;
	++ID_itens;
}

void checkbox::show(int pos)
{
	if (pos == checkbox::id)
		checkbox::check ? std::cout << "> [X]" << checkbox::name << "\n"
		: std::cout << "> [*]" << checkbox::name  << "\n";
	else
		checkbox::check ? std::cout << "  [X]" << checkbox::name << "\n"
		: std::cout << "  [*]" << checkbox::name << "\n";
}

void checkbox::ChangeValue(int pos)
{
	if (id == pos)
		checkbox::check = !checkbox::check;
}

//Text Edit

/*
	Needed name length and buffer with ID
*/
TextEdit::TextEdit(std::string textedit, int lenght, std::string buffer, int id)
{
	TextEdit::name = textedit;
	TextEdit::length = lenght;
	TextEdit::buffer = buffer;
	TextEdit::id = id;	
	++ID_itens;
}
/*
	Only Name and Buffer Length is according to the buffer
*/
TextEdit::TextEdit(std::string textedit, std::string buffer)
{
	TextEdit::name = textedit;
	TextEdit::length = buffer.length()+2;
	TextEdit::buffer = buffer;
	TextEdit::id = ID_itens;
	++ID_itens;
}
/*
	Only Name and Length
*/
TextEdit::TextEdit(std::string textedit, int lenght)
{
	TextEdit::name = textedit;
	TextEdit::length = lenght;
	TextEdit::buffer = "";
	TextEdit::id = ID_itens;
	++ID_itens;
}


void TextEdit::show(int pos)
{
	std::string ca = "_";

	std::string texts = name;
	texts.clear();
	texts.append("[");
	for (size_t x = 0; x < length - 2; ++x)
		texts.append(ca);

	texts.erase(1, buffer.size());
	texts.insert(1, buffer);
	if (texts.size() > length)
		texts.erase(length - 1, name.size() + 1);

	texts.append("]");

	if ((id == pos))
		std::cout  << "> " << texts << name << std::endl;
	else
		std::cout  << "  " << texts << name << std::endl;
}

void TextEdit::changeValue(int pos)
{
	if (pos == TextEdit::id)
	{
		cls();
		std::cout << "Write Now: ";
		std::getline(std::cin, TextEdit::buffer);
		cls();
	}

}
// TrackBar

/*
*	Name, min value, max value, value current and ID
*/
TrackBar::TrackBar(std::string textBar, int min, int max, int value, UINT32 id)
{
	TrackBar::name = textBar;
	TrackBar::id = id;
	TrackBar::max = max;
	TrackBar::min = min;
	TrackBar::value = value;
	++ID_itens;
}

/*
*	Name, min value, max value and ID
*/

TrackBar::TrackBar(std::string textBar, int min, int max, UINT32 id)
{
	TrackBar::name = textBar;
	TrackBar::id = id;
	TrackBar::max = max;
	TrackBar::min = min;
	TrackBar::value = 0;
	++ID_itens;
}

/*
*	Name, min value and max value
*/
TrackBar::TrackBar(std::string textBar, int min, int max)
{
	TrackBar::name = textBar;
	TrackBar::id = ID_itens;
	TrackBar::max = max;
	TrackBar::min = min;
	TrackBar::value = 0;
	++ID_itens;
}

void TrackBar::Show(int pos)
{
	std::string points = ".";
	std::string track = "|";

	std::string texts;
	texts.clear();
	texts.append("[");
	for (int x = 0; x <= max; ++x)
	{
		if (x == value)
			texts.append(track);
		else if (x < value)
			texts.append("-");
		else
			texts.append(points);
	}
	texts.append("]");

	if ((id == pos))
		std::cout  << "> " << texts << name << std::endl;
	else
		std::cout  << "  " << texts << name << std::endl;
}

void TrackBar::changeValue(int pos)
{
	if (id == pos)
	{
		++value;
		if (value > max)	
			value = min;
	}
}

/*
*	name, list, text show and ID
*/
ComboBox::ComboBox(std::string name, std::vector<std::string> list, std::string text, UINT id)
{
	ComboBox::id = id;
	ComboBox::name = name;
	ComboBox::list = list;
	ComboBox::text = text;
	++ID_itens;
}

/*
*	name and ID
*/
ComboBox::ComboBox(std::string name, UINT id)
{

	ComboBox::id = id;
	ComboBox::name = name;
	ComboBox::text = "";
	++ID_itens;
}

/*
*	name only
*/
ComboBox::ComboBox(std::string name)
{
	ComboBox::id = ID_itens;
	//ComboBox::id = id;
	ComboBox::name = name;
	ComboBox::text = "";
	++ID_itens;
}

void ComboBox::Show(int pos)
{
	std::string box;
	box.append("[");
	box.append(text);
	box.append("]");

	if ((id == pos))
		std::cout << "> " << box << name << std::endl;
	else
		std::cout << "  " << box << name << std::endl;

}

void ComboBox::ChangeValue(int pos)
{
	if (pos == id)
	{
		cls();
	bool complete = true;
	int lis_pos = 0, total = 3;
	std::string options[] = { "|Add|", "|Remove|", "|Select|", "|End|" };
	bool ReWrite = true;
		while (complete)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				
				--lis_pos;
				if (lis_pos < 0)
					lis_pos = total;

				ReWrite = true;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				++lis_pos;
				if (lis_pos > total)
					lis_pos = 0;

				ReWrite = true;
			}
			if (ReWrite)
			{
				system("cls");
				std::cout << std::endl;
				std::cout << "---------------------" << std::endl;
				for (auto line : list)
				{
					std::cout << "[" << line << "]" << std::endl;
				}
				std::cout << "---------------------" << std::endl;
				std::cout << "->" << "  " << options[lis_pos] << std::endl;
				ReWrite = false;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				if (lis_pos == 0)
				{
					std::string newItem;
					std::cout << "Write new item: ";
					std::cin >> newItem;
					std::cin.clear();
					list.push_back(newItem);
					text = list[0];
					ReWrite = true;

				}
				if (lis_pos == 1)
				{
					int rm_num = 0;
					for (auto line : list)
					{
						std::cout << "["<< rm_num << "][" << line << "]" << std::endl;
						rm_num++;
					}
					std::cout << "Write number of want delete > ";
					std::cin >> rm_num;
					std::cin.clear();
					list.erase(list.begin() + rm_num);
					ReWrite = true;
				}
				if (lis_pos == 2)
				{
					int rm_num = 0;
					for (auto line : list)
					{
						std::cout << "[" << rm_num << "][" << line << "]" << std::endl;
						rm_num++;
					}
					std::cout << "Number of you want show: ";
					std::cin >> rm_num;
					std::cin.clear();
					text = list[rm_num];
					std::cout << "Text: " << text << std::endl;
					
					ReWrite = true;
				}
				if (lis_pos == total)
				{
					complete = false;
					cls();
				}
					
				
			}
			
			Sleep(100);
		}
	}

}

ProgressBar::ProgressBar(std::string name, float value, UINT id)
{
	ProgressBar::id = id;
	ProgressBar::name = name;
	ProgressBar::value = value;
}

ProgressBar::ProgressBar(std::string name, float value)
{
	ProgressBar::id = ID_itens;
	ProgressBar::name = name;
	ProgressBar::value = value;
	++ID_itens;
}

ProgressBar::ProgressBar(std::string name)
{
	ProgressBar::id = ID_itens;
	ProgressBar::name = name;
	ProgressBar::value = 0;
	++ID_itens;
}
 
void ProgressBar::Show(int pos)
{
	std::string bar;
	bar.clear();
	bar.append("[");
	for (int x = 0; x <= max; ++x)
	{
		if (x <= value)
			bar.append("|");
		else	
			bar.append(".");
	}
	bar.append("]");
	std::cout << bar << name << std::endl;

}

void ProgressBar::ChangeValue(int pos)
{
	value += 0.5f;
}
