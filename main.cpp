#include <iostream>
#include "complex.hpp"

using namespace std;

int main() {
	using cn = complex<double>;

	cn z1(1,1);
	cn z2(-1,1);
	cn z3(5);
	cn z4;
	cn temp;


	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cout << "z3 = " << z3 << endl;
	cout << "z4 = " << z4 << endl;

	cout << "re(z1)   = " << z1.re()   << endl;
	cout << "im(z1)   = " << z1.im()   << endl;
	cout << "conj(z1) = " << z1.conj() << endl;

	cout << "z1\t+\tz2\t=\t" << z1  +  z2  << endl;
	cout << "z2\t+\tz1\t=\t" << z2  +  z1  << endl;
	cout << "z1\t+\t5\t=\t"  << z1  +  5.0 << endl;
	cout << " 5\t+\tz1\t=\t" << 5.0 +  z1  << endl;
	temp = z1;
	temp += z2;
	cout << "z1\t+=\tz2\t=\t" << temp       << endl;
	temp = z1;
	temp += 5.0;
	cout << "z1\t+=\t5\t=\t"  << temp       << endl;

	cout << "z1\t-\tz2\t=\t" << z1  -  z2  << endl;
	cout << "z2\t-\tz1\t=\t" << z2  -  z1  << endl;
	cout << "z1\t-\t5\t=\t"  << z1  -  5.0 << endl;
//	cout << " 5\t-\tz1\t=\t" << 5.0 -  z1  << endl; unable to make this work
        temp = z1;
        temp -= z2;
	cout << "z1\t-=\tz2\t=\t" << temp       << endl;
        temp = z1;
        temp -= 5.0;
	cout << "z1\t-=\t5\t=\t"  << temp       << endl;

	cout << "z1\t*\tz2\t=\t" << z1  *  z2  << endl;
	cout << "z2\t*\tz1\t=\t" << z2  *  z1  << endl;
	cout << "z1\t*\t5\t=\t"  << z1  *  5.0 << endl;
	cout << " 5\t*\tz1\t=\t" << 5.0 *  z1  << endl;
	temp = z1;
        temp *= z2;
        cout << "z1\t*=\tz2\t=\t" << temp       << endl;
        temp = z1;
        temp *= 5.0;
        cout << "z1\t*=\t5\t=\t"  << temp       << endl;

	cout << "z1\t/\tz2\t=\t" << z1  /  z2  << endl;
	cout << "z2\t/\tz1\t=\t" << z2  /  z1  << endl;
	cout << "z1\t/\t5\t=\t"  << z1  /  5.0 << endl;
//	cout << " 5\t/\tz1\t=\t" << 5.0 /  z1  << endl; unable to make this work
        temp = z1;
        temp /= z2;
        cout << "z1\t/=\tz2\t=\t" << temp       << endl;
        temp = z1;
        temp /= 5.0;
        cout << "z1\t/=\t5\t=\t"  << temp       << endl;


	return 0;
}
