// stdafx.cpp : source file that includes just the standard includes
// pku_poj.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

int exp(int a, int b){
	if(b <= 0)
		return 1;
	else 
		return (a * exp(a, --b));
}

int base10(int i)
{
	if (i == 0 || i == 1)
		return (1);

	int ret = 1;
	for(int j = 1; j < i; j++){
		ret *= 10;
	}
	return (ret);
}