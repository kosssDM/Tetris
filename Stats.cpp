#include "Stats.h"

/**
 Конструктор
   на входе :  *
   на выходе : *
*/
TetrisStats::TetrisStats()
{
	Reset();
}

/**
 Функция сброса к стартовым значениям
   на входе :  *
   на выходе : *
*/
void TetrisStats::Reset()
{
	if (m_nSpeed > m_nMaxSpeed)
		m_nMaxSpeed = m_nSpeed;

	if (m_nScore > m_nMaxScore)
		m_nMaxScore = m_nScore;

	m_nTimer = STARTTIME;
	m_nSpeed = STARTSPEED;
	m_nScore = STARTSCORE;
}

/**
 Функция инкрементирования значения счета
   на входе :  short in_shCount значение на которое необходимо увеличить количество очков
   на выходе : *
*/
void TetrisStats::IncScore(short in_shCount)
{
	m_nScore += in_shCount;
	if (in_shCount > SCORESTEP)
	{
		m_nSpeed++;
		m_nTimer -= TIMESTEP;
	}
};

void TetrisStats::Drow()
{
	glColor3fv(g_aWhite);
	renderBitmapString(245, 300, "Welcome!");
	renderBitmapString(230, 260, "Speed: ");
	renderBitmapString(285, 260, inttostr_(m_nSpeed));
	renderBitmapString(230, 240, "Score: ");
	renderBitmapString(285, 240, inttostr_(m_nScore));
	renderBitmapString(240, 220, "Max speed");
	renderBitmapString(260, 200, inttostr_(m_nMaxSpeed));
	renderBitmapString(240, 180, "Max score");
	renderBitmapString(260, 160, inttostr_(m_nMaxScore));
}

/**
 Функция выдачи текущего значения таймера
   на входе :  *
   на выходе : int m_nTimer
*/
int TetrisStats::GetTimer()
{
	return m_nTimer;
};

/**
 Функция отрисовки строки
   на входе :  int x позиция начала отрисовки по x
               int y позиция начала отрисовки по y
               char *string строка которую будем рисовать
   на выходе : *
*/
void TetrisStats::renderBitmapString(int x, int y, char *string)
{
	char *c;
	glRasterPos2i(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
	}
}

/**
 Функция перевода числа в строку
   на входе :  int in_Number число для перевода
   на выходе : char * m_cBuffer итоговая строка
*/
char * TetrisStats::inttostr_(int in_Number)
{
	snprintf(m_cBuffer, sizeof(m_cBuffer), "%ld", in_Number);
	return m_cBuffer;
}