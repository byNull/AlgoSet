#ifndef _Houseboat_H__
#define _Houseboat_H__

#pragma once

#include "stdafx.h"

class MypointF{
public:
	float x;
	float y;
public:
	MypointF(float xx = 0.0, float yy = 0.0) : x(xx), y(yy){

	}

	bool equals(MypointF pt){
		return ((pt.x == x) && (pt.y == y));
	}
};


bool judgeCoord(MypointF pt)
{
	if(pt.equals(MypointF(0.0, 0.0))){
		return false;
	}
	return true;
}

double mydistance(MypointF pt1, MypointF pt2)
{
	return sqrt(((pt1.x - pt2.x) * (pt1.x - pt2.x)) + ((pt1.y - pt2.y) * (pt1.y - pt2.y)));
}

double myarea(double r){
	return (3.1415926 * r * r);
}

int getYears(double siz){
	int n = 1;

	while(siz > 0){
		siz -= 50;
		if(siz <= 0)
			break;
		n++;
	}

	return (n);
}

#endif