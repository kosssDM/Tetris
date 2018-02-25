#include "Tetris.h"

	TetrisField Field;
	TetrisStats Stats;
	TetrisDetal Detal;

/**
 ќсновна¤ функци¤ отрисовки
   на входе  : *
   на выходе : *
*/
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Stats.Drow();
	Detal.Drow();
	Field.Drow();

	glEnd();
	glFlush();
	glutSwapBuffers();
}

/**
  ‘ункци¤ обработки состо¤ни¤ детали
   на входе  : *
   на выходе : *
*/
void DetalWork(int = 0)
{
	switch (Field.GetState(Detal.m_sDetal))
	{
	case NONE:
		Detal.GoDown();
		break;
	case STOP:
		Stats.IncScore(Field.AddDetal(Detal.m_sDetal));
		Detal.Change();
		Selector(Field.m_sfield, Detal.m_sDetal, Detal.m_nNowDetal, Detal.m_nNowPos);
		break;
	case END:
		Stats.Reset();
		Field.Clear();
		break;
	}
	Display(); 
	
}

/**
  ‘ункци¤ обработки нажати¤ клавиш
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
  ќсновной таймер
   на входе  : *
   на выходе : *
*/
void Timer(int = 0)
{
	DetalWork();
	glutTimerFunc(Stats.GetTimer(), Timer, 0);
}

/**
  »нициализаци¤ тетриса
   на входе  : *
   на выходе : *
*/
void TetrisRun(int argc, char **argv)
{
	// ѕо старту деталь не отрисована, отрисуем
	Selector(Field.m_sfield, Detal.m_sDetal, Detal.m_nNowDetal, Detal.m_nNowPos);
	// —пр¤чем консоль
	FreeConsole();
	// »ницализаци¤ √лута
	glutInit(&argc, argv);
	glutInitWindowSize(WWIDTH, WHEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tetris");
	gluOrtho2D(0, WWIDTH, 0, WHEIGHT);
	glutSpecialFunc(KeySwitch);
	glutTimerFunc(Stats.GetTimer(), Timer, 0);
	// ќсновной глут луп
	glutMainLoop();
}