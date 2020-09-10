#pragma once
#include "head.h"
void ExConsole();
void setCursorPosition(int x, int y);
void setConsoleColour(unsigned short colour);
void cls();
void helpQuard();
void square(int width, int hight, int type, int posX, int posY);
void help();

class checkbox
{
public:
	checkbox(std::string name, bool check, int id);
	checkbox(std::string name, bool check);
	checkbox(std::string name);

	void show(int pos);
	void ChangeValue(int pos);

	std::string name; bool check;
private:
	int id;

};

class TextEdit
{
public:
	TextEdit(std::string textedit, int lenght, std::string buffer, int id);
	TextEdit(std::string textedit, std::string buffer);
	TextEdit(std::string textedit, int lenght);

	void show(int pos);
	void changeValue(int pos);

	std::string name; size_t length;
private:
	std::string buffer;
	int id;
};

class TrackBar
{
public:
	TrackBar(std::string textBar, int min, int max, int value, UINT32 id);
	TrackBar(std::string textBar, int min, int max, UINT32 id);
	TrackBar(std::string textBar, int min, int max);
	void Show(int pos);
	void changeValue(int pos);
	std::string name; int value;
private:
	int max, min;
	int id;
};

class ComboBox
{
public:
	ComboBox(std::string name, std::vector<std::string>list, std::string text, UINT id);
	ComboBox(std::string name, UINT id);
	ComboBox(std::string name);
	void Show(int pos);
	void ChangeValue(int pos);

	std::vector<std::string>list;
	std::string text;
private:
	UINT id;
	std::string name;


};

class ProgressBar
{
public:
	ProgressBar(std::string name, float value, UINT id);
	ProgressBar(std::string name, float value);
	ProgressBar(std::string name);
	void Show(int pos);
	void ChangeValue(int pos);

	float value;


private:
	UINT id;
	float max = 100.0f;
	float min = 0.0f;

	std::string name;
};