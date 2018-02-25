#pragma once

#include "Gui.h"

#define FW           15           // ������ � ������ ���������� ����
#define FH           35           // ������ � ������ ���������� ����

// ��������� �������
enum Detail
{
	I = 0,
	T,
	Q,
	Z,
	S,
	J,
	L
};

// ��������� ��������� ������ �� ����
enum DetalState
{
	NONE = 0,    // ��� ��������� ����� ��������� ������
	STOP,        // ������ ��������� ������
	END          // ������ ��������� ������ � �� �� ��������� ����
};

//��������� ����
struct l_stField { bool dot = false; };

class TetrisField {
public:
	l_stField m_sfield[FW][FH];              // ������ �������� �������� ����� ����
	TetrisField();							 // �����������
	void Clear();							 // �������� ����
	void Drow();							 // ���������� ����
	void Rebuild();							 // ����������� ����(���� ���� ������� ������)
	bool isLineClean(short in_shLineNumber); // ����� �� ������
	bool TestLine(short in_shLineNumber);	 // ��������� �� ������
	void ClearLine(short in_shLineNumber);	 // �������� ������
	int AddDetal(l_stDot *in_sDetal);		 // �������� ������ �� ����
	bool CanRight(l_stDot *in_sDetal);		 // ����� �� ������ ������� � �����
	bool CanLeft(l_stDot *in_sDetal);		 // ����� �� ������ ������� � ����
	short GetState(l_stDot *in_sDetal);		 // �������� ��������� ������ �� ����
};