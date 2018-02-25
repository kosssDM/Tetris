#include "Detal.h"	

#include <random> 

//��� ����� �����������
std::random_device rd;   // non-deterministic generator  
std::mt19937 gen(rd());  // to seed mersenne twister.  
std::uniform_int_distribution<> GenDetal(0, 6); // �������� 0 - 7
std::uniform_int_distribution<> GenXPos(3, 8);
std::uniform_int_distribution<> GenDetalPos(0, 3);

/**
 �����������
   �� ����� :  *
   �� ������ : *
*/
TetrisDetal::TetrisDetal()
{
	Change();
}

/**
 ������� ��������� ��������� ������ �� ��������� �������� �� ������
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::Change()
{
	m_nNowPos = GenDetalPos(gen);
	m_nNowDetal = GenDetal(gen);
	m_sDetal[0].y = STARTHEIGHT;
	m_sDetal[0].x = GenXPos(gen);
}

/**
 ������� ��������� ������� ������(��������)
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::ChangePos()
{
	m_nNowPos == 3 ? m_nNowPos = 0 : m_nNowPos++;
}

/**
 ������� �������� � ����
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::GoLeft()
{
	for (int i = 0; i < DS; i++)
		m_sDetal[i].x--;
}

/**
 ������� �������� � ����
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::GoRight()
{
	for (int i = 0; i < DS; i++)
		m_sDetal[i].x++;
}

/**
 ������� �������� � ���
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::GoDown()
{
	for (int i = 0; i < DS; i++)
			m_sDetal[i].y--;
}

/**
 ������� ��������� ������
   �� ����� :  *
   �� ������ : *
*/
void TetrisDetal::Drow()
{
	// ������ ��� ������ ����� ������
	for (int i = 0; i < DS; i++)
	{
		if (m_sDetal[i].y <= CH && m_sDetal[i].y >= 1)
		{
			glColor3fv(g_aLightBlue);
			glRectf((GLfloat)(m_sDetal[i].x + 0.01)*SQUARESCALE, (GLfloat)(m_sDetal[i].y + 0.01)*SQUARESCALE, (GLfloat)(m_sDetal[i].x + 0.99)*SQUARESCALE, (GLfloat)(m_sDetal[i].y + 0.99)*SQUARESCALE);
		}
	}
}