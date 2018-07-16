#pragma once
#include "Detal.h"
// Класс для отображения слежующей детали
class TetrisNextDetal :
	public TetrisDetal
{
public:

	TetrisNextDetal();
	~TetrisNextDetal();

	void ToDetal(TetrisDetal* in_Detal);    // Копирование следующей дететали в текущую
	void ToPosition(int in_iX, int in_iY);  // Установка на позицию отображения
};

