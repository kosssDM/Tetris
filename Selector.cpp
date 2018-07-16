#include "Selector.h"

/**
 Функция выбора и поворота детали
 на входе:        l_stField in_sField[FW][FH]     Ссылка на поле в котором происходит изменение поворот детали
				 l_stDot   in_sDetal[DS]         Поворачиваемая/изменяемая деталь
				 short     in_shNowDetal         Номер текущей детали
				 short     in_shNowPos           Позиция текущей детали
 на выходе: *
*/
void Selector(l_stField in_sField[FW][FH], l_stDot in_sDetal[DS], short in_shNowDetal, short in_shNowPos)
{
	switch (in_shNowDetal) {
	case I:
		switch (in_shNowPos)
		{
		case 0:
		case 2:
			if ((in_sDetal[0].y + 3 <= FH))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 3].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 2, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x, in_sDetal[0].y + 3, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
		case 3:
			if ((in_sDetal[0].x - 1 > 0) && (in_sDetal[0].x + 2 <= CW))
				if (!in_sField[in_sDetal[0].x - 1][in_sDetal[0].y].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot && !in_sField[in_sDetal[0].x + 2][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x - 1, in_sDetal[0].y, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 2, in_sDetal[0].y, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		}
		break;
	case T:
		switch (in_shNowPos)
		{
		case 0:
			if ((in_sDetal[0].y + 1 <= FH) && (in_sDetal[0].x - 1 > 0) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x - 1, in_sDetal[0].y, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 2    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 2:
			if ((in_sDetal[0].y + 1 <= FH) && (in_sDetal[0].x - 1 > 0) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x - 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 3:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x - 1 > 0))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 2    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x - 1, in_sDetal[0].y + 1, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		}
		break;
	case Q:
		in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
		in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
		in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
		break;
	case L:
		switch (in_shNowPos)
		{
		case 0:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 2, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
			if ((in_sDetal[0].x + 2 <= CW) && (in_sDetal[0].y + 1 <= FH))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 2][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 2, in_sDetal[0].y + 1, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 2:
			if ((in_sDetal[0].x - 1 > 0) && (in_sDetal[0].y + 2 <= FH))
				if (!in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x - 1, in_sDetal[0].y + 2, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 2    , {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 3:
			if ((in_sDetal[0].x + 1 <= CW) && (in_sDetal[0].y + 1 <= FH) && (in_sDetal[0].x - 1 > 0))
				if (!in_sField[in_sDetal[0].x - 1][in_sDetal[0].y].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x - 1, in_sDetal[0].y    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		}
		break;
	case J:
		switch (in_shNowPos)
		{
		case 0:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x + 1, in_sDetal[0].y + 2, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
			if ((in_sDetal[0].x + 2 <= CW) && (in_sDetal[0].y + 1 <= FH))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot && !in_sField[in_sDetal[0].x + 2][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 2, in_sDetal[0].y, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 2:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 2].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 2    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 2, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 3:
			if ((in_sDetal[0].x - 2 > 0) && (in_sDetal[0].y + 1 <= FH))
				if (!in_sField[in_sDetal[0].x - 2][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x - 2, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x - 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		}
		break;
	case Z:
		switch (in_shNowPos)
		{
		case 0:
		case 2:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x + 1 <= CW))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 2].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y + 2, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
		case 3:
			if ((in_sDetal[0].x + 1 <= CW) && (in_sDetal[0].y + 1 <= FH) && (in_sDetal[0].x - 1 > 0))
				if (!in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x + 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x - 1, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x + 1, in_sDetal[0].y    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };;
				}
			break;
		}
		break;
	case S:
		switch (in_shNowPos)
		{
		case 0:
		case 2:
			if ((in_sDetal[0].y + 2 <= FH) && (in_sDetal[0].x - 1 > 0))
				if (!in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y + 2].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x - 1, in_sDetal[0].y + 1, {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x - 1, in_sDetal[0].y + 2, {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		case 1:
		case 3:
			if ((in_sDetal[0].x + 1 <= CW) && (in_sDetal[0].y + 1 <= FH) && (in_sDetal[0].x - 1 > 0))
				if (!in_sField[in_sDetal[0].x + 1][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x][in_sDetal[0].y + 1].dot && !in_sField[in_sDetal[0].x - 1][in_sDetal[0].y].dot)
				{
					in_sDetal[1] = { in_sDetal[0].x + 1, in_sDetal[0].y + 1, {in_sDetal[1].color[0], in_sDetal[1].color[1], in_sDetal[1].color[2]} };
					in_sDetal[2] = { in_sDetal[0].x, in_sDetal[0].y + 1    , {in_sDetal[2].color[0], in_sDetal[2].color[1], in_sDetal[2].color[2]} };
					in_sDetal[3] = { in_sDetal[0].x - 1, in_sDetal[0].y    , {in_sDetal[3].color[0], in_sDetal[3].color[1], in_sDetal[3].color[2]} };
				}
			break;
		}
		break;
	}
}