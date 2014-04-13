#ifndef _HANGOVER_H__
#define _HANGOVER_H__

#pragma once

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//
// Hangover:
// The input consists of one or more test cases, followed by a line containing the number 0.00 that signals the end of the input. Each test case is a single line containing a positive floating-point number c whose value is at least 0.01 and at most 5.20; c will contain exactly three digits
//
//////////////////////////////////////////////////////////////////////////
bool judgeLegal(string str)
{
	if(str.length() != 4)
		return false;
	double f = atof(str.data());
	if(f < 0.01 || f > 5.20)
		return false;

	return true;
}


int getCards(string str)
{
	int n = 1;
	double f = atof(str.data());
	double sum = 0.0;
	//sscanf(str.data(), "%f", &f);
	while(sum < f){
		sum += 1.0/(n+1);
		if(sum >= f)
			break;
		n++;
	}

	return (n);
}

#endif