#include "stdafx.h"
#include "chapter_1.h"

void reverse_1(char *str, int n, int i)
{
	if (n <= 1 || i == 0)
		return ;

	char tmp = str[0];
	int count = 0, j = 0, orgPos = 0;
	for (j = i; count < n; j += i) {
			count++;
			/*str[(j-i+n)%n] = str[(j+n)%n];*/
			if (count < n && (j+n)%n == orgPos){
				str[(j-i+n)%n] = tmp;
				j = (j+1)%n;
				tmp = str[(j+n)%n];
				orgPos = j;
			} else if (count == n) {
				break;
			} else{
				str[(j-i+n)%n] = str[(j+n)%n];
			}
	
	}
	str[(j-i+n)%n] = tmp;
}


void reverse_2(char *str, int n, int i)
{
	flip(str, 0, i-1);
	flip(str, i, n-1);
	flip(str, 0, n-1);
}

void flip(char *str, int beg, int end)
{
	int i = beg, len = end-beg+1;
	for (; i < beg + len/2; i++) {
		std::swap(str[i], str[end-i + beg]);
	}
}

/*
ab ---> a[lb, rb] -->[rb, lb]b
subproblem: 
[rb, lb] -->
*/
void reverse_3(char *str, int n, int i, int beg)
{
	int lLen = i; //lLen
	int rLen = n - i;
	int j = n - i; // rLen

	if (lLen <= rLen) {
		for (int k = 0; k < lLen; k++, j++){
			std::swap(str[k], str[j]);
		}
		if (lLen == rLen)
			return;
		reverse_3(str, n-lLen, i, beg);
	} else {
		//lLen > rLen
		for (int k = 0; k < rLen; k++) {
			std::swap(str[beg+k], str[beg+j]);
		}
		reverse_3(str, n-rLen, lLen-rLen, beg+rLen);
	}
}