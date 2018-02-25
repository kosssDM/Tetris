#include "Detal.h"	

#include <random> 

//Для пущей случайности
std::random_device rd;   // non-deterministic generator  
std::mt19937 gen(rd());  // to seed mersenne twister.  
std::uniform_int_distribution<> GenDetal(0, 6); // Диапазон 0 - 7
std::uniform_int_distribution<> GenXPos(3, 8);
std::uniform_int_distribution<> GenDetalPos(0, 3);

/**
 Конструктор
   на входе :  *
   на выходе : *
*/
TetrisDetal::TetrisDetal()
{
	Change();
}

/**
 Функция установки случайной дитали со случайной позицией на страрт
   на входе :  *
   на выходе : *
*/
void TetrisDetal::Change()
{
	m_nNowPos = GenDetalPos(gen);
	m_nNowDetal = GenDetal(gen);
	m_sDetal[0].y = STARTHEIGHT;
	m_sDetal[0].x = GenXPos(gen);
}

/**
 Функция изменения позиции детали(варщение)
   на входе :  *
   на выходе : *
*/
void TetrisDetal::ChangePos()
{
	m_nNowPos == 3 ? m_nNowPos = 0 : m_nNowPos++;
}

/**
 Функция движения в лево
   на входе :  *
   на выходе : *
*/
void TetrisDetal::GoLeft()
{
	for (int i = 0; i < DS; i++)
		m_sDetal[i].x--;
}

/**
 Функция движения в прво
   на входе :  *
   на выходе : *
*/
void TetrisDetal::GoRight()
{
	for (int i = 0; i < DS; i++)
		m_sDetal[i].x++;
}

/**
 Функция движения в низ
   на входе :  *
   на выходе : *
*/
void TetrisDetal::GoDown()
{
	for (int i = 0; i < DS; i++)
			m_sDetal[i].y--;
}

/**
 Функция отрисовки детали
   на входе :  *
   на выходе : *
*/
void TetrisDetal::Drow()
{
	// Рисуем все четыре точки детали
	for (int i = 0; i < DS; i++)
	{
		if (m_sDetal[i].y <= CH && m_sDetal[i].y >= 1)
		{
			glColor3fv(g_aLightBlue);
			glRectf((GLfloat)(m_sDetal[i].x + 0.01)*SQUARESCALE, (GLfloat)(m_sDetal[i].y + 0.01)*SQUARESCALE, (GLfloat)(m_sDetal[i].x + 0.99)*SQUARESCALE, (GLfloat)(m_sDetal[i].y + 0.99)*SQUARESCALE);
		}
	}
}