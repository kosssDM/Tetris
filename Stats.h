#pragma once
#include <iostream>
#include "Gui.h"

#define TIMESTEP       5             // ��� ��������� ��������
#define SCORESTEP      5             // ����������� ����������� ����� ��� ������ ���������

#define STARTTIME      500           // ��������� ���������� ������� ����� ���������� ����
#define STARTSPEED     1             // ��������� �������� �������� ��������
#define STARTSCORE     0             // ��������� ����������� �����
								     
class TetrisStats 
{				     
	int m_nTimer;                    // ������� ���������� ������� ����� ���������� ����
	int m_nSpeed;                    // ������� ������� ��������
	int m_nScore;                    // ������� ����������� �����

	int m_nMaxSpeed;                    // ������� ������� ��������
	int m_nMaxScore;                    // ������� ����������� �����
								     
	char m_cBuffer[128];             // ����� ��� ������ �����

	void renderBitmapString(int x, int y, char *string); // ������� ���������� ������
	char * inttostr_(int in_Number); // ������� ����� � ������

public:

	TetrisStats();                   // �����������
	void Reset();                    // ����� ��������
	void IncScore(short in_shCount); // ���������� ����������� �����
	void Drow();                     // ��������� ������� ��������
	int GetTimer();                  // ������ �������� �������� �������
};