#include "Field.h"

/**
 �����������
   �� �����  : *
   �� ������ : *
*/
TetrisField::TetrisField() {
	Clear();
};

/**
 ������� ������� ����
   �� �����  : *
   �� ������ : *
*/
void TetrisField::Clear()
{
	for (int x = 1; x < FW; x++)
	{
		for (int y = 1; y < FH; y++)
		{
			m_sfield[x][y].dot = false;
		}
	}
}

/**
 ������� ������������ ���� ���� ���� ������� ����� � ��������
   �� �����  : *
   �� ������ : *
*/
void TetrisField::Rebuild()//TODO ����� �������� ������������� ������������ ������ ������������� ����, ���� �� ������ ������ ������
{
	int l_nLineOmmited = 0;
	for (int y = 1; y <= CH;)
	{
		if (isLineClean(y) && (l_nLineOmmited <= CH))
		{
			for (int yy = y; yy <= CH; yy++)
			{
				for (int x = 1; x <= CW; x++)
				{
					m_sfield[x][yy].dot = m_sfield[x][yy + 1].dot;
				}
			}
			l_nLineOmmited++;
		}
		else
		{
			y++;
		}
	}
}

/**
 ������� ���������� ������ �� ����
   �� �����  : l_stDot *in_sDetal ������ ������� ���������� ��������� �� ����
   �� ������ : int ����� ������������ ������ ���� ����� ��������� �� ��� + ���������� �������� ������ �� �����
*/
int TetrisField::AddDetal(l_stDot *in_sDetal)//������� ������ �� ����
{
	int l_nScore = DS;
	for (int i = 0; i < DS; i++)
	{
		m_sfield[in_sDetal[i].x][in_sDetal[i].y].dot = true;
	}
	for (int i = 0; i < DS; i++)
	{
		if (TestLine(in_sDetal[i].y))
		{
			ClearLine(in_sDetal[i].y);
			l_nScore += 10;
		}
	}
	Rebuild();
	return l_nScore;
}

/**
 ������� ����������� �����������
   �� �����  : short ����� �����
   �� ������ : bool ��������� ��������� �� �����
*/
bool TetrisField::TestLine(short in_shLineNumber)//�������� ����� �� �������������, ���� ���, �� �������� ��
{
	for (int x = 1; x <= CW; x++)
	{
		if (m_sfield[x][in_shLineNumber].dot != true)
		{
			return false;
		}
	}
	return true;
}

/**
 ������� ������� �����
   �� �����  : short ����� �����
   �� ������ : *
*/
void TetrisField::ClearLine(short in_shLineNumber)//�������� ����� �� �������������, ���� ���, �� �������� ��
{
	for (int x = 1; x <= CW; x++)
	{
		m_sfield[x][in_shLineNumber].dot = false;
	}
}

/**
 ������� ����������� ������ �����
   �� �����  : short ����� �����
   �� ������ : bool ��������� ����� �� �����
*/
bool TetrisField::isLineClean(short in_shLineNumber) {
	for (int x = 1; x <= CW; x++)
	{
		if (m_sfield[x][in_shLineNumber].dot == true)
		{
			return false;
		}
	}
	return true;
}

/**
 ������� ����������� ����������� ������ �������� � �����
   �� �����  : l_stDot *in_sDetal ������ ����������� �������� ������� ���������� ���������
   �� ������ : bool ��������� ����������� ��������
*/
bool TetrisField::CanRight(l_stDot *in_sDetal)
{
	for (int i = 0; i < DS; i++)
	{
		if ((in_sDetal[i].x + 1) > CW)
		{
			return false;
		}
		else if (m_sfield[in_sDetal[i].x + 1][in_sDetal[i].y].dot == true)
		{
			return false;
		}
	}
	return true;
}

/**
 ������� ����������� ����������� ������ �������� � ����
   �� �����  : l_stDot *in_sDetal ������ ����������� �������� ������� ���������� ���������
   �� ������ : bool ��������� ����������� ��������
*/
bool TetrisField::CanLeft(l_stDot *in_sDetal)
{
	for (int i = 0; i < DS; i++)
	{
		if (in_sDetal[i].x < 2)
		{
			return false;
		}
		else if (m_sfield[in_sDetal[i].x - 1][in_sDetal[i].y].dot == true)
		{
			return false;
		}
	}
	return true;
}

/**
 ������� ����������� ��������� ������ 
   �� �����  : l_stDot *in_sDetal ������
   �� ������ : l_shState 	NONE = 0,   ��� ��������� ����� ��������� ������
							STOP,       ������ ��������� ������
							END         ������ ��������� ������ � �� �� ��������� ����
*/
short TetrisField::GetState(l_stDot *in_sDetal)
{
	short l_shState = NONE;
	for (int i = 0; i < DS; i++)
	{
		if (in_sDetal[i].y > 0)
			if (m_sfield[in_sDetal[i].x][in_sDetal[i].y - 1].dot == true || in_sDetal[i].y == 1)
			{
				l_shState = l_shState != END ? STOP : l_shState;
				if (in_sDetal[i].y > 20)
					for (int j = 0; j < DS; j++)
					{
						if (in_sDetal[j].y > CH)
							l_shState = END;
					}
			}
	}
	return l_shState;
}

/**
 ������� ��������� ���������� � ����� ����
   �� �����  : *
   �� ������ : *
*/
void TetrisField::Drow()
{
	// ������� ����
	glColor3fv(g_aRed);
	// �������� ������� �������� �� ����
	for (int x = 1; x <= CW; x++)
	{
		for (int y = 1; y <= CH; y++)
		{
			if (m_sfield[x][y].dot == true)
			{
				glRectf(
					(GLfloat)(x + 0.01)*SQUARESCALE,
					(GLfloat)(y + 0.01)*SQUARESCALE,
					(GLfloat)(x + 0.99)*SQUARESCALE,
					(GLfloat)(y + 0.99)*SQUARESCALE
				);
			}
		}
	}
	// �������� ����� ����
	// ������� ����
	glColor3fv(g_aLightRed);
	// ��� �����
	glBegin(GL_LINES);
	// �������� ������������ �����
	for (GLfloat i = 0; i <= GWIDTH; i += SQUARESCALE)
	{
		glVertex2f(i, SQUARESCALE); glVertex2f(i, GHEIGHT);
	}
	// �������� �������������� �����
	for (GLfloat j = 0; j <= GHEIGHT; j += SQUARESCALE)
	{
		glVertex2f(SQUARESCALE, j); glVertex2f(GWIDTH, j);
	}
}