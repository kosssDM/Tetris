#pragma once

#include <GL/glut.h> 

#define SQUARESCALE  20           // Размер клетки

#define WWIDTH       340          // Ширина окна
#define WHEIGHT      480          // Высота окна

#define GWIDTH       220          // Ширина игрового поля
#define GHEIGHT      460          // Высота игрового поля

#define CW           10           // Количество видимых клеток в ширину
#define CH           22           // Количество видимых клеток в высоту  

#define DS           4            // Колличсетво точек детали

extern GLfloat g_aRed[3];         // Красный
extern GLfloat g_aLightRed[3];	  // Светло красный
extern GLfloat g_aLightBlue[3];	  // Светло синий

//Структура точки
struct l_stDot { int x; int y; };