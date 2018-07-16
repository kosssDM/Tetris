#include "NextDetal.h"


TetrisNextDetal::TetrisNextDetal()
{
}


TetrisNextDetal::~TetrisNextDetal()
{
}

/**
  Функция копирования характеристик детали
    на входе: in_Detal указатель на принимающую деталь
   на выходе: *
*/
void TetrisNextDetal::ToDetal(TetrisDetal* in_Detal)
{
	// Скопируем тип и позицию
	in_Detal->m_nNowDetal = m_nNowDetal;
	in_Detal->m_nNowPos = m_nNowPos;

	// Скопируем цвет каждой секции детали
	in_Detal->m_sDetal[0].color[0] = m_sDetal[0].color[0];
	in_Detal->m_sDetal[0].color[1] = m_sDetal[1].color[1];
	in_Detal->m_sDetal[0].color[2] = m_sDetal[2].color[2];

	in_Detal->m_sDetal[1].color[0] = m_sDetal[0].color[0];
	in_Detal->m_sDetal[1].color[1] = m_sDetal[1].color[1];
	in_Detal->m_sDetal[1].color[2] = m_sDetal[2].color[2];

	in_Detal->m_sDetal[2].color[0] = m_sDetal[0].color[0];
	in_Detal->m_sDetal[2].color[1] = m_sDetal[1].color[1];
	in_Detal->m_sDetal[2].color[2] = m_sDetal[2].color[2];

	in_Detal->m_sDetal[3].color[0] = m_sDetal[0].color[0];
	in_Detal->m_sDetal[3].color[1] = m_sDetal[1].color[1];
	in_Detal->m_sDetal[3].color[2] = m_sDetal[2].color[2];
}

/**
  Функция перемещения детали на позицию для отображения
     на входе: что то чтоб показать куда двигаться
    на выходе: *
*/
void TetrisNextDetal::ToPosition(int in_iX, int in_iY)
{
	// Инициализируем что бы запомнить
	int x, y;

	// Скопируем стартовую позицию 
	x = m_sDetal[0].x;
	y = m_sDetal[0].y;

	// Назначим новое положение с учетом отношения к главной секции
	for (int i = 0; i < DS; i++)
	{
		m_sDetal[i].x = in_iX + (m_sDetal[i].x - x);
		m_sDetal[i].y = in_iY + (m_sDetal[i].y - y);
	}
}
