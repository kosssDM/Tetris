#pragma once

#include <GL/glut.h> 
#include <random> 

#define SQUARESCALE  20           // ������ ������
								   
#define WWIDTH       360           // ������ ����
#define WHEIGHT      480          // ������ ����
								   
#define GWIDTH       220          // ������ �������� ����
#define GHEIGHT      460          // ������ �������� ����
								   
#define CW           10           // ���������� ������� ������ � ������
#define CH           22           // ���������� ������� ������ � ������  
								   
#define DS           4             // ����������� ����� ������

extern GLfloat g_aWhite[3];  
extern GLfloat g_aLightWhite[3];

// ��������� �����
struct l_stDot { 
	int x; 
	int y;
	GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
};

// �������� ��������� ����
void GetRandomColor(GLfloat in_sColor[DS]);