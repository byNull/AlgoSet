// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <complex>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <time.h>
#include <locale.h>
#include <signal.h>
//#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>




using namespace std;


//////////////////////////////////////////////////////////////////////////
// type definition
typedef char int8;
typedef unsigned char uint8;

//struct char2{
//	char c1;
//	char c2;
//};
//typedef char2 int16;
//typedef unsigned char2 uint16;
typedef short int16;
typedef unsigned short uint16;

typedef int int32;
typedef unsigned int uint32;

#define MAXLEN 1024



#pragma warning(disable:4996)




// TODO: reference additional headers your program requires here

int exp(int a, int b);
int base10(int i);