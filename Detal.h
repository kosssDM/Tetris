#pragma once
#include "Gui.h"

#define STARTHEIGHT  24           // Стартовая высота для отрисовки детали

class TetrisDetal {

public:
	l_stDot  m_sDetal[DS];        // Массив структур детали

	short m_nNowPos;              // Текущая позиция поворота
	short m_nNowDetal;            // Текущий номер детали

	TetrisDetal();                // Конструктор

	void Change();                // Изменить позицию поворота и деталь
	void ChangePos();             // Изменить позицию поворота
	void GoLeft();                // Передвинуть в лево
	void GoRight();               // Передвинуть в право
	void GoDown();                // Передвинуть в низ
	void Drow();                  // Отрисовать деталь
};