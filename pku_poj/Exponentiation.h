//////////////////////////////////////////////////////////////////////////
// compute Rn
// where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
//////////////////////////////////////////////////////////////////////////

struct MaxDouble{
	int dotloc;
	long int num;
};

void mul(char *str1, char *str2, char *rt);
void str_mul_int(char *str, int n, char *rt);
void str_add_str(char *str1, char *str2, char *rt);

void mul(char *str1, char *str2, char *rt)
{
	/*
	// str1 * str2[i]
	*/
	
	int len2 = strlen(str2);
	char tmp1[MAXLEN];
	char tmp2[MAXLEN];

	for (int i = len2-1; i >= 0; i--){
		str_mul_int(str1, str2[i]-'0', tmp1);

		int j = strlen(tmp1);
		int k = j + (len2 - i - 1);
		for( ; j < k; j++){
			tmp1[j] = '0';
		}
		tmp1[j] = '\0';

		memcpy(tmp2, rt, sizeof(tmp2));
		str_add_str(tmp1, tmp2, rt);
	}
}

void str_mul_int(char *str, int num, char *rt)
{
	int len = strlen(str);
	int i, k = 0;
	int carry = 0;

	for (i = len-1; i >= 0; i--){
		int n = (str[i]-'0') * num + carry;
		rt[k++] = n % 10 + '0';
		carry = n / 10;
	}
	if(carry != 0)
		rt[k++] = carry + '0';
	rt[k] = '\0';

	std::reverse(rt, rt+strlen(rt));
}

void str_add_str(char *str1, char *str2, char *rt)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int carry = 0;
	int i, j, k = 0;

	for(i = len1-1, j = len2-1; i >= 0 && j >= 0; ){
		int n = (str1[i--]-'0') + (str2[j--]-'0') + carry;
		carry = n / 10;
		rt[k++] = n % 10  + '0';
	}

	while(j >= 0){
		int n = (str2[j--]-'0') + carry;
		carry = n / 10;
		rt[k++] = n % 10 + '0';
	}

	while(i >= 0){
		int n = (str1[i--]-'0') + carry;
		carry = n / 10;
		rt[k++] = n % 10 + '0';
	}
	if(carry != 0)
		rt[k++] = carry + '0';

	rt[k] = '\0';

	std::reverse(rt, rt + strlen(rt));
	

}


class Exponentiation{
private:
	int _n;
	double _r;
	char *_str;
	char *_result;

public:
	Exponentiation() : _n(0), _result(NULL){
		_str = NULL;
	}
	Exponentiation(char *str, int n) : _str(str), _n(n), _result(NULL){

	}
	~Exponentiation(){
		if(_result != NULL)
			delete[] _result;
	}

	void setN(int n){
		_n = n;
	}
	void setR(double r){
		_r = r;
	}
	int    getN(void)const   {return (_n);}
	double getR(void)const   {return (_r);}
	char *getResult()const   {	return (_result); }

public:
	void compute(){
		/*	if(_n == 0) {
		_result = new char[2];
		_result[0] = '1';
		_result[1] = '\0';
		return;
		}
		else if(_n == 1) {
		_result = new char[strlen(_str) + 1];
		memcpy(_result, _str, sizeof(_str));
		_result[strlen(_str)] = '\0';
		return;
		}*/
		char tmp[MAXLEN];
		char ret[MAXLEN];
		memset(tmp, 0, MAXLEN);
		memset(ret, 0, MAXLEN);

		double r   = atof(_str);
		int    idx = indexOfDot(_str);

		memcpy(tmp, _str, strlen(_str));
		memset(_str, 0, strlen(_str));
		sprintf(_str, "%d", (int)(r * exp(10, idx)));

		int    dotloc = dotLoc(idx, _n);

		memset(tmp, 0, MAXLEN);
		memset(ret, 0, MAXLEN);
		memcpy(ret, _str, strlen(_str));
		ret[strlen(_str)] = '\0';
	
		for(int i = 1; i < _n; i++){
			memcpy(tmp, ret, sizeof(tmp));
			memset(ret, 0, sizeof(ret));
			mul(tmp, _str, ret);
			cout << ret << endl;
		}

		int len_ret = strlen(ret);
		int l1 = len_ret - dotloc;
		int aloLen = 0;

		aloLen = (dotloc > 0) ? (len_ret + 2) : (len_ret + 1);
		aloLen = max(aloLen, dotloc + 2);
		_result = new char[aloLen];

		memset(_result, 0, aloLen);
		if(len_ret < dotloc){
			int i = 1, j = dotloc - len_ret;
			memcpy(_result, ".", 1);
			memset(_result+1, '0', j);
			memcpy(_result+j+1, ret, strlen(ret));

		}else{
			if(dotloc > 0){
				memcpy(_result, ret, l1);
				memcpy(_result+l1, ".", 1);
				memcpy(_result + l1 + 1, ret + l1, len_ret - l1);
			}else{
				memcpy(_result, ret, strlen(ret));
			}
		}
		
		_result[strlen(_result)] = '\0';

	}

	int dotLoc(int num, int cnt)
	{
		if(num < 0)
			return -1;
		return num * _n;
	}

	int indexOfDot(char *str) const{
		int   idx = 0;
		char *ptr = str;

		for (idx = 0; *ptr != '\0'; idx++, ptr++){
			if(*ptr == '.')
				break;
		}
		idx = ((idx != 0) ? (strlen(str) - idx) : (idx));

		return (idx - 1);
	}

	int indexOfDot(double r)const{
		char *str = new char[MAXLEN];
		sprintf_s(str, MAXLEN, "%lf", r);
		int ret = indexOfDot(str);
		return (delete[]str, ret);
	}
};