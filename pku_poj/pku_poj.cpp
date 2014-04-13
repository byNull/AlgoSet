// pku_poj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "a_plus_b.h"
#include "Exponentiation.h"
#include "487-3279.h"
#include "hangover.h"
#include "Houseboat.h"
#include "Biorhythms.h"
#include "DNASort.h"

void sig_handler(int signu){
	printf("%d: \n",signu);
}

class Base {
	int j;
public:
	virtual void f(){std::cout << "Base::f()" << std::endl;}
};

class Derive : public Base{
public:
	virtual void f(){ std::cout << "Derive::f()" << std::endl; }

};
int _tmain(int argc, _TCHAR* argv[])
{

	Base b;
	b.f();
	b.~Base();

	Derive *d = new(&b)Derive;
	b.f(); //Base::f()

	//delete d;

	std::cout << sizeof("hello") << std::endl;

	//////////////////////////////////////////////////////////////////////////
	// a + b problem
	/*char a = 2, b = 3;
	cin >> a >> b;

	cout << (int)A_Plus_B(a-'0', b-'0').plus() << endl;*/
	

	//////////////////////////////////////////////////////////////////////////
	// R^n
	//////////////////////////////////////////////////////////////////////////
	//int n;
	//char str[MAXLEN];
	//char line[MAXLEN];
	//char rt[MAXLEN];
	////char s1[MAXLEN] = "0.4321";
	//while(true){
	//	//scanf("%s%n", str, &n);
	//	cin.getline(line, MAXLEN);
	//	sscanf(line, "%s%d", str, &n);
	//	//cin >> str >> n;
	//	str[strlen(str)] = '\0';
	//	Exponentiation e(str, n);
	//	e.compute();
	//	cout << e.getResult() << endl;
	//	//cout << Exponentiation(str, n).indexOfDot(str) << endl;
	//}

	////////////////////////////////////////////////////////////////////////////
	// Problem : 487-3279
	//////////////////////////////////////////////////////////////////////////
	//string line;

	//while(!getline(cin, line).eof()){
	//	string str = str2Hyphens(line);
	//	if(!str.empty()){
	//		cout << str << endl;
	//		cout << str2StandardForm(str) << endl;
	//	}
	//}

	////////////////////////////////////////////////////////////////////////////
	// Problem : hangover
	//////////////////////////////////////////////////////////////////////////
	/*string line;
	vector<string> vstr;
	while(!getline(cin, line).eof()){
	if(line == "0.00")
	break;
	if(judgeLegal(line))
	vstr.push_back(line);
	}

	for (vector<string>::size_type i = 0; i < vstr.size(); i++){
	cout << getCards(vstr[i]) << " card(s)" <<endl;

	}
	*/

	////////////////////////////////////////////////////////////////////////////
	// Problem : hangover
	//////////////////////////////////////////////////////////////////////////
	/*vector<double> dvec;
	double d;
	while (!cin.eof() && cin >> d) {
	dvec.push_back(d);
	}
	double sum = accumulate(dvec.begin(), dvec.end(), 0.0);
	cout << sum/dvec.size() << endl;
	*/

	////////////////////////////////////////////////////////////////////////////
	// Problem : houseboat
	//////////////////////////////////////////////////////////////////////////
	//int i = 0, n;
	//cin >> n;

	//MypointF *ppt = new MypointF[n];
	//while (!cin.eof() && i < n){
	//	cin >> ppt[i].x >> ppt[i].y;
	//	i++;
	//}

	//for (i = 0; i < n; i++){
	//	double a = myarea(mydistance(ppt[i], MypointF(0.0, 0.0)))/2;
	//	printf("Property %d: This property will begin eroding in year %d.\n", i, getYears(a));
	//}
	//printf("END OF OUTPUT.\n");


	////////////////////////////////////////////////////////////////////////////
	// Problem : Biorhythms
	//////////////////////////////////////////////////////////////////////////
	/*vector<BiorhythmsNode> bnVec;
	
	while(!cin.eof()){
		BiorhythmsNode bn;
		cin >> bn.p >> bn.e >> bn.i >> bn.d;
		if(!judgeBiorhythms(&bn))
			break;
		
		bnVec.push_back(bn);
	}

	for(vector<BiorhythmsNode>::size_type i = 0; i < bnVec.size(); i++){

		printf("Case %d: the next triple peak occurs in %d days.\n", i, BiorhythmsCnts(&bnVec[i]));
	}*/


	/*int len, lineCnt;
	DNANode line;
	vector<DNANode> svec;

	cin >> len >> lineCnt;

	while(!cin.eof() && lineCnt > 0){
		cin >> line.dna;
		if(line.dna.length() == len){
			line.numOfInversions = numOfInversions(line.dna);
			svec.push_back(line);
			lineCnt--;
		}
	}
	printf("\n\n Output Begin:\n\n");
	sort(svec.begin(), svec.end(), DANCompare);
	std::ostream_iterator<string> out_it (std::cout,"\n");
	copy(svec.begin(), svec.end(), out_it);
*/




	/*typedef unsigned short int fexcept_tt;

	cout << sizeof(unsigned int) << endl;
*/
	//union {
	//	float f;
	//	double d;
	//}u;

	//std::cout << sizeof(u) << endl;
	//std::cout << sizeof(float) << endl;
	//u.f = 10.0;
	////cout << u.f << endl;
	//printf("%f\n", u.f);


	//u.d = 10.0;
	//printf("%lf\n", u.d);

	//int i = 1;
	////i = ++i+++1;
	//i &= 0x3;
	//std::cout << i << endl;

	//time_t rawtime;
	//struct tm * timeinfo;
	//char buffer [80];

	//struct lconv * lc;

	//time ( &rawtime );
	//timeinfo = localtime ( &rawtime );

	//int twice=0;

	//do {
	//	printf ("Locale is: %s\n", setlocale(LC_ALL,NULL) );

	//	strftime (buffer,80,"%c",timeinfo);
	//	printf ("Date is: %s\n",buffer);

	//	lc = localeconv ();
	//	printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);

	//	setlocale (LC_ALL,"");
	//} while (!twice++);


#define myoffsetof(type, mem) f_offsetof(type, mem);
struct foo{
	char a;
	char b[10];
	char c;
};

	std::cout << (int)offsetof(struct foo, c) << endl;
	signal(SIGINT, sig_handler);

	raise(SIGINT);

	char *pc = new char;
	*pc = 'c';

	int n = reinterpret_cast<int>(pc);
	printf("%d, %c, 0x%x\n", n, *pc, pc);

	return 0;
}


