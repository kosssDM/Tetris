#pragma once
#include "Gui.h"

#define STARTHEIGHT  24           // ��������� ������ ��� ��������� ������

class TetrisDetal {

public:
	l_stDot  m_sDetal[DS];        // ������ �������� ������

	short m_nNowPos;              // ������� ������� ��������
	short m_nNowDetal;            // ������� ����� ������

	TetrisDetal();                // �����������

	void Change();                // �������� ������� �������� � ������
	void ChangePos();             // �������� ������� ��������
	void GoLeft();                // ����������� � ����
	void GoRight();               // ����������� � �����
	void GoDown();                // ����������� � ���
	void Drow();                  // ���������� ������
};