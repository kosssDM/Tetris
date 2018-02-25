#pragma once

#include <GL/glut.h> 

#define SQUARESCALE  20           // ������ ������

#define WWIDTH       340          // ������ ����
#define WHEIGHT      480          // ������ ����

#define GWIDTH       220          // ������ �������� ����
#define GHEIGHT      460          // ������ �������� ����

#define CW           10           // ���������� ������� ������ � ������
#define CH           22           // ���������� ������� ������ � ������  

#define DS           4            // ����������� ����� ������

extern GLfloat g_aRed[3];         // �������
extern GLfloat g_aLightRed[3];	  // ������ �������
extern GLfloat g_aLightBlue[3];	  // ������ �����

//��������� �����
struct l_stDot { int x; int y; };