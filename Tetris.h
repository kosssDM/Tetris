#pragma once
#include "Detal.h"
#include "NextDetal.h"
#include "Selector.h"
#include "Stats.h"
							     
// ��������� ������ ����������
enum ButtonKeys
{
	KEYLEFT = 100,     // ������� ������� � ����
	KEYUP,             // ������� ������� � ����
	KEYRIGHT,		   // ������� ������� � �����
	KEYDOWN			   // ������� ������� � ���
};

void Display();                               // ������� ����������� ���� ���������
void Timer(int);                              // ������� ������� ��� �����
void DetalWork();							  // ��������� ������� ������	
void KeySwitch(int in_nKey, int a, int b);    // ��������� ������� ������ ����������
void TetrisRun(int argc, char **argv);        // �������� ����
