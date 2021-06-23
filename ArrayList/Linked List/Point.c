#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos)
{
	ppos->x = xpos;
	ppos->y = ypos;
}

void ShowPointPos(Point * ppos)
{
	printf("[%d, %d]\n", ppos->x, ppos->y);
}

int PointComp(Point * pos1, Point * pos2)
{
	if (pos1->x == pos2->x && pos1->y == pos2->y)
		return 0;
	else if (pos1->x == pos2->x)
		return 1;
	else if (pos1->y == pos2->y)
		return 2;
	else
		return -1;
}