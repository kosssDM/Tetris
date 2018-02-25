#pragma once
#include "Detal.h"
#include "Selector.h"
#include "Stats.h"

							     
// Нумератор клавиш управления
enum ButtonKeys
{
	KEYLEFT = 100,     // Клавиша стрелка в лево
	KEYUP,             // Клавиша стрелка в верх
	KEYRIGHT,		   // Клавиша стрелка в право
	KEYDOWN			   // Клавиша стрелка в низ
};

	void Display();
	void Timer(int);
	void DetalWork(int);
	void KeySwitch(int in_nKey, int a, int b);
	void TetrisRun(int argc, char **argv);        // Основной цикл
