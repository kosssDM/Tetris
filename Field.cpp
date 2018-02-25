#include "Field.h"

/**
 Конструктор
   на входе  : *
   на выходе : *
*/
TetrisField::TetrisField() {
	Clear();
};

/**
 Функция очистки поля
   на входе  : *
   на выходе : *
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
 Функция перестроения поля если были удалены линии в середине
   на входе  : *
   на выходе : *
*/
void TetrisField::Rebuild()//TODO Можно улучшить отслеживанием максимальной высоты заполненности поля, чтоб не делать лишнюю работу
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
 Функция добавления детали на поле
   на входе  : l_stDot *in_sDetal деталь которую необходимо перенести на поле
   на выходе : int число перенесенных блоков если линия заполнена то еще + количество очищеных блоков на линии
*/
int TetrisField::AddDetal(l_stDot *in_sDetal)//Перенос детали на поле
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
 Функция определения заполненной
   на входе  : short Номер линии
   на выходе : bool состояние заполнена ли линия
*/
bool TetrisField::TestLine(short in_shLineNumber)//Проверка линии на заполненность, если что, то очистить ее
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
 Функция очистки линии
   на входе  : short Номер линии
   на выходе : *
*/
void TetrisField::ClearLine(short in_shLineNumber)//Проверка линии на заполненность, если что, то очистить ее
{
	for (int x = 1; x <= CW; x++)
	{
		m_sfield[x][in_shLineNumber].dot = false;
	}
}

/**
 Функция определения пустой линии
   на входе  : short Номер линии
   на выходе : bool состояние пуста ли линия
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
 Функция определения возможности детали динуться в право
   на входе  : l_stDot *in_sDetal Деталь возможность движения которой необходимо проверить
   на выходе : bool состояние возможности движения
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
 Функция определения возможности детали динуться в лево
   на входе  : l_stDot *in_sDetal Деталь возможность движения которой необходимо проверить
   на выходе : bool состояние возможности движения
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
 Функция определения состояния детали 
   на входе  : l_stDot *in_sDetal Деталь
   на выходе : l_shState 	NONE = 0,   Все нормально можно двигаться дальше
							STOP,       Дальше двигаться некуда
							END         Дальше двигаться некуда и мы за пределами поля
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
 Функция рисования разлиновки и краев поля
   на входе  : *
   на выходе : *
*/
void TetrisField::Drow()
{
	// Выберем цвет
	glColor3fv(g_aRed);
	// Нарисуем занятые квадраты на поле
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
	// Нарисуем сетку поля
	// Выберем цвет
	glColor3fv(g_aLightRed);
	// Тип фигур
	glBegin(GL_LINES);
	// Нарисуем вертикальные линии
	for (GLfloat i = 0; i <= GWIDTH; i += SQUARESCALE)
	{
		glVertex2f(i, SQUARESCALE); glVertex2f(i, GHEIGHT);
	}
	// Нарисуем горизонтальные линии
	for (GLfloat j = 0; j <= GHEIGHT; j += SQUARESCALE)
	{
		glVertex2f(SQUARESCALE, j); glVertex2f(GWIDTH, j);
	}
}