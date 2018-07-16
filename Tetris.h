#pragma once
#include "Detal.h"
#include "NextDetal.h"
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

void Display();                               // Функция отображения всех элементов
void Timer(int);                              // Функция таймера для глута
void DetalWork();							  // Обработка статуса детали	
void KeySwitch(int in_nKey, int a, int b);    // Обработка нажатия клавиш управления
void TetrisRun(int argc, char **argv);        // Основной цикл
