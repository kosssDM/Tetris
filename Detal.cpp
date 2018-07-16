#include "Detal.h"	

// ��� ����� �����������
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

	GLfloat l_gfColor[3] = { 0,0,0 };

	GetRandomColor(l_gfColor);

	m_sDetal[0].color[0] = l_gfColor[0];
	m_sDetal[0].color[1] = l_gfColor[1];
	m_sDetal[0].color[2] = l_gfColor[2];

	m_sDetal[1].color[0] = l_gfColor[0];
	m_sDetal[1].color[1] = l_gfColor[1];
	m_sDetal[1].color[2] = l_gfColor[2];

	m_sDetal[2].color[0] = l_gfColor[0];
	m_sDetal[2].color[1] = l_gfColor[1];
	m_sDetal[2].color[2] = l_gfColor[2];

	m_sDetal[3].color[0] = l_gfColor[0];
	m_sDetal[3].color[1] = l_gfColor[1];
	m_sDetal[3].color[2] = l_gfColor[2];
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
		if (m_sDetal[i].y <= CH)
		{
			glColor3fv(m_sDetal[i].color);
			glRectf((GLfloat)(m_sDetal[i].x)*SQUARESCALE, (GLfloat)(m_sDetal[i].y)*SQUARESCALE, (GLfloat)(m_sDetal[i].x + 1)*SQUARESCALE, (GLfloat)(m_sDetal[i].y + 1)*SQUARESCALE);
		}
	}
}