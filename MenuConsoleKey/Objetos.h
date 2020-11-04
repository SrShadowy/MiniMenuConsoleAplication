#pragma once
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


class timer
{
private:
	uint64_t internal_tick = 0;
	uint32_t interval = 0;
	bool enable = true;
	bool tick_count = false;
	void tick()
	{
		if (enable)
			tick_count = (GetTickCount64() > internal_tick);
		else
			tick_count = false;

		if (tick_count)
			internal_tick = GetTickCount64() + interval;
	}

public:

	timer()
	{
		timer::interval = 100;
		timer::enable = true;
		internal_tick = GetTickCount64() + interval;
	}

	timer(int interval, bool enable)
	{
		timer::interval = interval;
		timer::enable = enable;
		internal_tick = GetTickCount64() + interval;
	}

	// check_tick
	bool timer_on()
	{
		tick();
		return tick_count;
	}
	// stop tick
	void stop()
	{
		enable = false;
	}
	// start again
	void start()
	{
		enable = true;
	}
	// change interval
	void set_new_interval(int new_interval)
	{
		interval = new_interval;
	}
};