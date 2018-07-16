#include "Gui.h"
#include <random> 

// Определение цветов
GLfloat g_aWhite[3]      = { 1.0f, 1.0f, 1.0f };    // Белый для стат
GLfloat g_aLightWhite[3] = { 0.2f, 0.2f, 0.2f };    // Белый(скорее серый) светлый для разлиновки поля
												  
// Для пущей случайности						 	 
std::random_device rdC;                             // non-deterministic generator  
std::mt19937 genC(rdC());                           // to seed mersenne twister.  
std::uniform_int_distribution<> Color(50, 100);     // Диапазон 50 - 100
std::uniform_int_distribution<> ColorToNull(0,2);   // Диапазон 0 - 2

/** 
 Функция получения рандомного цвета
    на входе:       in_sColor[DS]   Ссылка на массив цвета
    на выходе: *
*/
void GetRandomColor(GLfloat in_sColor[DS])
{
	// Получим рандомный цвет
	in_sColor[0] = ((GLfloat)Color(genC) / 100 );
	in_sColor[1] = ((GLfloat)Color(genC) / 100 );
	in_sColor[2] = ((GLfloat)Color(genC) / 100 );
	
	// Для насыщенносит обнулим один случайный
	in_sColor[ColorToNull(genC)] = 0;
};