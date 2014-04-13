#ifndef _Biorhythms_H__
#define _Biorhythms_H__

#pragma once

#include "stdafx.h"

struct BiorhythmsNode{
	int p, e, i, d;
};


bool judgeBiorhythms(BiorhythmsNode *pbn)
{
	if(pbn->p == -1 && pbn->e == -1 &&
		pbn->i == -1 && pbn->d == -1){
			return false;
	}
	return true;
}

bool isPeak(int day, int circle, int begin)
{
	return (day >= begin) ? (day%circle == begin%circle) : (false);
}

int BiorhythmsCnts(BiorhythmsNode *pbn)
{
	int day = pbn->d;

	while(true){
		day++;
		if(isPeak(day, 23, pbn->p) &&
			isPeak(day, 28, pbn->e) &&
			isPeak(day, 33, pbn->i)){
			break;
		}
	}

	return (day - pbn->d);
}




#endif