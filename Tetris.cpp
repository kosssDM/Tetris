#include "Tetris.h"

	TetrisField Field;
	TetrisStats Stats;
	TetrisDetal Detal;
	TetrisNextDetal NextDetal;

/**
 Основная функция отрисовки
   на входе  : *
   на выходе : *
*/
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Stats.Drow();
	NextDetal.Drow();
	Detal.Drow();
	Field.Drow();

	glEnd();
	glFlush();
	glutSwapBuffers();
}

/**
  Функция обработки состо¤ни¤ детали
   на входе  : *
   на выходе : *
*/
void DetalWork()
{
	switch (Field.GetState(Detal.m_sDetal))
	{
	case NONE:
		Detal.GoDown();
		break;
	case STOP:
		// Запишем очки
		Stats.IncScore(Field.AddDetal(Detal.m_sDetal));

		// Сменим позицию наначало
		Detal.Change();

		// Скопируем деталь из той, которую просто показывали
		NextDetal.ToDetal(&Detal);

		// Отрисуем основную деталь
		Selector(Field.m_sfield, Detal.m_sDetal, Detal.m_nNowDetal, Detal.m_nNowPos);

		// Сгенерируем слоедующую деталь
		NextDetal.Change();
		
		// Отпозиционируем 
		Selector(Field.m_sfield, NextDetal.m_sDetal, NextDetal.m_nNowDetal, NextDetal.m_nNowPos);

		// Поместим на позицию отображения
		NextDetal.ToPosition(14,19);
		break;
	case END:
		Stats.Reset();
		Field.Clear();
		break;
	}
	Display(); 
}

/**
  Функция обработки нажатий клавиш
   на входе  : *
   на выходе : *
*/
void KeySwitch(int in_nKey, int a, int b)
{
	switch (in_nKey)
	{
	case KEYUP:
		Detal.ChangePos();
		Selector(Field.m_sfield, Detal.m_sDetal, Detal.m_nNowDetal, Detal.m_nNowPos);
		break;
	case KEYRIGHT:
		if (Field.CanRight(Detal.m_sDetal))
			Detal.GoRight();
		break;
	case KEYLEFT:
		if (Field.CanLeft(Detal.m_sDetal))
			Detal.GoLeft();
		break;
	case KEYDOWN:
		DetalWork();
		break;
	}
	Display();
}

/**
  Основной таймер
   на входе  : *
   на выходе : *
*/
void Timer(int = 0)
{
	DetalWork();
	glutTimerFunc(Stats.GetTimer(), Timer, 0);
}

/**
 Инициализация тетриса
   на входе  : *
   на выходе : *
*/
void TetrisRun(int argc, char **argv)
{
	// По старту деталь не инициализирована, инициализируем
	Selector(Field.m_sfield, Detal.m_sDetal, Detal.m_nNowDetal, Detal.m_nNowPos);
	Selector(Field.m_sfield, NextDetal.m_sDetal, NextDetal.m_nNowDetal, NextDetal.m_nNowPos);
	// Поместим на позицию отображения
		NextDetal.ToPosition(14,19);
	// Спрячем консоль
	FreeConsole();
	// Иницализация глута
	glutInit(&argc, argv);
	glutInitWindowSize(WWIDTH, WHEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tetris");
	gluOrtho2D(0, WWIDTH, 0, WHEIGHT);
	glutSpecialFunc(KeySwitch);
	glutTimerFunc(Stats.GetTimer(), Timer, 0);
	// Основной глут луп
	glutMainLoop();
}
