// progPearl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "chapter_1.h"



int _tmain(int argc, _TCHAR* argv[])
{
	char *str = new char[11];
	memcpy(str, "abcdefghijk", 11);
	//reverse_2(str, 11, 4);
	reverse_3(str, 11, 4, 0);

	cout << str << endl;
	return 0;
}

