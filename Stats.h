#pragma once
#include <iostream>
#include "Gui.h"

#define TIMESTEP       5             // Шаг ускорения движения
#define SCORESTEP      5             // Минимальное колличество очков для начала ускорения

#define STARTTIME      500           // Стартовый промежуток времени между движениями вниз
#define STARTSPEED     1             // Стартовое значение счетчика скорости
#define STARTSCORE     0             // Стартовое колличество очков
								     
class TetrisStats 
{				     
	int m_nTimer;                    // Текущий промежуток времени между движениями вниз
	int m_nSpeed;                    // Текущий уровень скорости
	int m_nScore;                    // Текущее колличество очков

	int m_nMaxSpeed;                    // Текущий уровень скорости
	int m_nMaxScore;                    // Текущее колличество очков
								     
	char m_cBuffer[128];             // Буфер для вывода строк

	void renderBitmapString(int x, int y, char *string); // Функция оторисовки строки
	char * inttostr_(int in_Number); // Перевод числа в строку

public:

	TetrisStats();                   // Конструктор
	void Reset();                    // Сброс значений
	void IncScore(short in_shCount); // Увеличение колличества очков
	void Drow();                     // Отрисовка текущих значений
	int GetTimer();                  // Выдача текущего значения таймера
};