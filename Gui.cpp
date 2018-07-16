#include "Gui.h"
#include <random> 

// ����������� ������
GLfloat g_aWhite[3]      = { 1.0f, 1.0f, 1.0f };    // ����� ��� ����
GLfloat g_aLightWhite[3] = { 0.2f, 0.2f, 0.2f };    // �����(������ �����) ������� ��� ���������� ����
												  
// ��� ����� �����������						 	 
std::random_device rdC;                             // non-deterministic generator  
std::mt19937 genC(rdC());                           // to seed mersenne twister.  
std::uniform_int_distribution<> Color(50, 100);     // �������� 50 - 100
std::uniform_int_distribution<> ColorToNull(0,2);   // �������� 0 - 2

/** 
 ������� ��������� ���������� �����
    �� �����:       in_sColor[DS]   ������ �� ������ �����
    �� ������: *
*/
void GetRandomColor(GLfloat in_sColor[DS])
{
	// ������� ��������� ����
	in_sColor[0] = ((GLfloat)Color(genC) / 100 );
	in_sColor[1] = ((GLfloat)Color(genC) / 100 );
	in_sColor[2] = ((GLfloat)Color(genC) / 100 );
	
	// ��� ������������ ������� ���� ���������
	in_sColor[ColorToNull(genC)] = 0;
};