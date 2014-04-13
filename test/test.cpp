// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "suffixArray.h"
#include "BiTree.h"

#define BASE 10

int num_0(int n);
int nth_num_1(int n);
void radixsort(int *a, int n);
void print(int *a, int n);

const int N = 10;

int _tmain(/*int argc, _TCHAR* argv[]*/)
{
	/*int sa[N], rank[N];

	char *ptr = "etewtwetwa";

	suffix_array(ptr, N, sa, rank);

	for ( int i = 0; i < N ; i++)
	{
		printf("%d\t", sa[i]);
	}
	*/

	/*int a[] = {1, 4, 8, 3};
	Tree<int> t;

	t.create(a, 4);
	DLinkList<int> *droot = t.getDLinkList();

	for (DLinkList<int> *tmp = droot; tmp != NULL; tmp = tmp->next)	{
		printf("%d\t", tmp->value);
	}

	putchar('\n');
*/

	/*for (int i = 0; i < 10; i++)
	{
	std::cout << nth_num_1(i) << endl;
	}*/

	int a[] = {12, 13, 22, 33, 56, 757, 98, 10};

	radixsort(a, 8);
	print(a, 8);
	
	//std::cout << num_0(10) << endl;
 	return 0;
}

//////////////////////////////////////////////////////////////////////////
// 求n!中末尾0的个数
//////////////////////////////////////////////////////////////////////////
int num_0(int n)
{
	int cnt = 0;

	for (int i = 5; i <= n; i+=5){
		int tmp = i;
		while((tmp%5) == 0){
			cnt++;
			tmp = tmp / 5;
		}
	}

	return (cnt);
}

//////////////////////////////////////////////////////////////////////////
// 求n!中末尾0的个数
//////////////////////////////////////////////////////////////////////////
int nth_num_1(int n)
{
	//int cnt = 0, sum = 1;

	//for (int i = 2; i <= n; i+=1){
	//	sum *= i;
	//}
	//
	//while(sum%2 == 0){
	//	sum >>= 1;
	//	cnt++;
	//}

	//return (cnt+1);

	int ret = 0;     //统计n!中含有质因数2的个数  
	while(n)   
	{   
		n >>= 1;   
		ret += n;   
	}   
	return (ret+1); 
}



void radixsort(int *a, int n) {
	int i, *b , max = a[0], exp = 1;
	b = new int[n];

	// find maximum data in array a
	for (i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	while (max / exp > 0) {
		memset(b, 0, sizeof(int) * n);

		int bucket[BASE] = { 0 };
		// 分配
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % BASE]++;
		}

		for (i = 1; i < BASE; i++) {
			bucket[i] += bucket[i - 1];
		}
		// 回收
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		}

		memcpy(a, b, sizeof(int) * n);
		//for (i = 0; i < n; i++) {
		//	a[i] = b[i];
		//}

		exp *= BASE;

	}

	delete[] b;
	b = NULL;
}

void print(int *a, int n)
{
	for(int i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}
	putchar('\n');
}

