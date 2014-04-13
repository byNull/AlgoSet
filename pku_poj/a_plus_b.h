class A_Plus_B{
private:
	int8 _a;
	int8 _b;

public:
	A_Plus_B(int8 a, int8 b) : _a(a), _b(b){

	} 

	void setA(int8 a){
		_a = a;
	}
	void setB(int8 b){
		_b = b;
	}

	int8 getA()const{
		return _a;
	}
	int8 getB()const {
		return _b;
	}

	int8 plus(void)const{
		return (_a + _b);
	}
};