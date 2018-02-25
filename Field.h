#pragma once

#include "Gui.h"

#define FW           15           // Размер в ширину считаемого поля
#define FH           35           // Размер в высоту считаемого поля

// Нумератор деталей
enum Detail
{
	I = 0,
	T,
	Q,
	Z,
	S,
	J,
	L
};

// Нумератор сосотяний детали на поле
enum DetalState
{
	NONE = 0,    // Все нормально можно двигаться дальше
	STOP,        // Дальше двигаться некуда
	END          // Дальше двигаться некуда и мы за пределами поля
};

//Структура поля
struct l_stField { bool dot = false; };

class TetrisField {
public:
	l_stField m_sfield[FW][FH];              // Массив массивов структур точек поля
	TetrisField();							 // Конструктор
	void Clear();							 // Очистить поле
	void Drow();							 // Отрисовать поле
	void Rebuild();							 // Перестроить поле(если была удалена строка)
	bool isLineClean(short in_shLineNumber); // Пуста ли строка
	bool TestLine(short in_shLineNumber);	 // Заполнена ли строка
	void ClearLine(short in_shLineNumber);	 // Очистить строку
	int AddDetal(l_stDot *in_sDetal);		 // Добавить деталь на поле
	bool CanRight(l_stDot *in_sDetal);		 // Можно ли деталь сдинуть в право
	bool CanLeft(l_stDot *in_sDetal);		 // Можно ли деталь сдинуть в лево
	short GetState(l_stDot *in_sDetal);		 // Получить состояние детали на поле
};