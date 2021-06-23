#pragma once

typedef struct _Point {
	int x;
	int y;
}Point;

void SetPointPos(Point * ppos, int xpos, int ypos);

void ShowPointPos(Point * ppos);

int PointComp(Point * pos1, Point * pos2);