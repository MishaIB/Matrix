#pragma once
using namespace std;
class Exteption {
public:
	virtual void print() = 0;
	virtual ~Exteption()=0;
};


class EInvalidSize :public Exteption {
public:
	void print();
};


class EInvalidIndex :public Exteption {
public:
	void print();
};


class EInvalidMull :public Exteption {
public:
	void print();
};


class EInvalidQuadrate :public Exteption {
public:
	void print();
};


class EdivisionZero :public Exteption {
public:
	void print();
};

