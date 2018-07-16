#include "Stats.h"

/**
 �����������
   �� ����� :  *
   �� ������ : *
*/
TetrisStats::TetrisStats()
{
	Reset();
}

/**
 ������� ������ � ��������� ���������
   �� ����� :  *
   �� ������ : *
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
 ������� ����������������� �������� �����
   �� ����� :  short in_shCount �������� �� ������� ���������� ��������� ���������� �����
   �� ������ : *
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
 ������� ������ �������� �������� �������
   �� ����� :  *
   �� ������ : int m_nTimer
*/
int TetrisStats::GetTimer()
{
	return m_nTimer;
};

/**
 ������� ��������� ������
   �� ����� :  int x ������� ������ ��������� �� x
               int y ������� ������ ��������� �� y
               char *string ������ ������� ����� ��������
   �� ������ : *
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
 ������� �������� ����� � ������
   �� ����� :  int in_Number ����� ��� ��������
   �� ������ : char * m_cBuffer �������� ������
*/
char * TetrisStats::inttostr_(int in_Number)
{
	snprintf(m_cBuffer, sizeof(m_cBuffer), "%ld", in_Number);
	return m_cBuffer;
}