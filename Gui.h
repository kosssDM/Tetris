#pragma once

#include <GL/glut.h> 
#include <random> 

#define SQUARESCALE  20           // Размер клетки
								   
#define WWIDTH       360           // Ширина окна
#define WHEIGHT      480          // Высота окна
								   
#define GWIDTH       220          // Ширина игрового поля
#define GHEIGHT      460          // Высота игрового поля
								   
#define CW           10           // Количество видимых клеток в ширину
#define CH           22           // Количество видимых клеток в высоту  
								   
#define DS           4             // Колличсетво точек детали

extern GLfloat g_aWhite[3];  
extern GLfloat g_aLightWhite[3];

// Структура точки
struct l_stDot { 
	int x; 
	int y;
	GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
};

// Получить случайный цвет
void GetRandomColor(GLfloat in_sColor[DS]);