// demooperatorloading.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class VECTOR
{
private:
	int A[2];
public:
	//--- constructor ----
	VECTOR() { A[0] = A[1] = 0; }
	VECTOR(int x, int y) { A[0] = x;A[1] = y; }
	//--- operator ------
	int& operator[](unsigned int i) { return A[i - 1]; }
	VECTOR operator+(const VECTOR& v2) 
	{
		VECTOR v;
		v.A[0] = A[0] + v2.A[0];
		v.A[1] = A[1] + v2.A[1];
		return v;
	}
	VECTOR& operator=(const VECTOR& v2)
	{
		if (this == &v2) return*this;
		A[0] = v2.A[0];
		A[1] = v2.A[1];
		return *this;
	}
	VECTOR operator*(const int& s)
	{
		VECTOR v;
		v.A[0] = A[0] *s;
		v.A[1] = A[1] *s;
		return v;
	}
	//---------------------
	friend VECTOR operator*(const int& s,const VECTOR& v2)
	{
		VECTOR v;
		v.A[0] = v2.A[0] * s;
		v.A[1] = v2.A[1] * s;
		return v;
	}
	friend ostream& operator<<(ostream & os, const VECTOR& v)
	{
		os << "(" << v.A[0] << "," << v.A[1] << ")";
		return os;
	}
};
int main()
{
	VECTOR v1, v4;
	v1[1] = 2;
	v1[2] = 3;
	VECTOR v2(3, 5);
	VECTOR v3;
	v3 = v1 + v2;
	cout << v3 << endl;
	v4 = v3 * 2;
	v4 = 3 * v4;
	cout << v4 << endl;
    return 0;
}

