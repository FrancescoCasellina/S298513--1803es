#pragma once

using namespace std;

template<typename T> requires floating_point<T> //forces use of floating point
class complex {
	T real, imma;

	public:
        	complex() { // default number with no input
            		real = 0;
            		imma = 0;
        	}
        	complex(T a, T b) { // user input
            		real = a;
            		imma = b;
        	}
        	explicit complex(T a) { // complex number converted to real number
            		real = a;
            		imma = 0;
        	}
        	T re() const { // display real part
            		return real;
        	}
        	T im() const { // display immaginary part
            		return imma;
        	}
        	complex conj() const { // display conjugate
            		return complex(real, -imma);
        	}
        	complex &operator += (const complex &other) { // sum += complex | complex
            		T a = real       , b = imma       ;
            		T c = other.real , d = other.imma ;
            		real = a + c;
            		imma = b + d;
            		return *this;
        	}
        	complex operator + (const complex &other) const { // sum + complex | complex
            		complex sum = *this;
            		sum += other;
            		return sum;
        	}
        	complex &operator += (const T &other) { // sum += complex | real
            		real += other;
            		return *this;
        	}
        	complex operator + (const T &other) const { // sum + complex | real
            		complex sum = *this;
            		sum += other;
            		return sum;
        	}
        	complex &operator -= (const complex &other) { // difference -= complex | complex
            		T a = real       , b = imma       ;
            		T c = other.real , d = other.imma ;
            		real = a - c;
            		imma = b - d;
            		return *this;
        	}
        	complex operator - (const complex &other) const { // difference - complex | complex
            		complex diff = *this;
            		diff -= other;
            		return diff;
        	}
        	complex &operator -= (const T &other) { // difference -= complex | real
            		real -= other;
            		return *this;
        	}
        	complex operator - (const T &other) const { // difference - complex | real
          		complex diff = *this;
           		diff -= other;
            		return diff;
        	}
        	complex &operator *= (const complex &other) { // product *= complex | complex
            		T a = real       , b = imma       ;
        		T c = other.real , d = other.imma ;
	        	real = a*c - b*d;
            		imma = a*d + c*b;
            		return *this;
        	}
        	complex operator * (const complex &other) const { // product * complex | complex
            		complex prod = *this;
            		prod *= other;
            		return prod;
        	}
        	complex &operator *= (const T &other) { // product *= complex | real
            		real *= other;
            		imma *= other;
            		return *this;
        	}
        	complex operator * (const T &other) const { // product * complex | real
            		complex prod = *this;
            		prod *= other;
            		return prod;
        	}
        	complex operator /= (const complex &other) { // division /= complex | complex
            		T a = real       , b = imma       ;
            		T c = other.real , d = other.imma ;
        		if (c == 0 && d == 0) {
            			throw std::invalid_argument("Warning: attempting to divide by zero!\n\nExiting...\n");
            		}
                	real = (a*c + b*d) / (c*c + d*d);
                	imma = (b*c - a*d) / (c*c + d*d);
                	return *this;
        	}
        	complex operator / (const complex &other) const { // division / complex | complex
        		complex div = *this;
        		div /= other;
        		return div;
		}
		complex operator /= (const T &other) { // division /= complex | real
			if (other == 0) {
				throw std::invalid_argument("Warning: attempting to divide by zero!\n\nExiting...\n");
			}
			real /= other;
			imma /= other;
			return *this;
		}
		complex operator / (const T &other) const { // division / complex | real
			complex div = *this;
			div /= other;
			return div;
		}
};


template<typename T>
ostream &operator << (ostream &out, const complex<T> &z) {
	T real=z.re(), imma=z.im();
	bool check_real=(real!=0);
	bool check_imma=(imma!=0);
	if (!check_real && !check_imma) {
		return out<<0;
	}
	else if (check_real && !check_imma) {
		return out<<real;
	}
	else {
		out << real;
		if (imma > 0) {
			return out << "+" << imma << "i";
		}
		else {
			return out << imma << "i";
		}
	}
}


template<typename T>
complex<T>
operator + (const T &t, const complex<T> &z)
{
	return z + t;
}


template<typename T>
complex<T>
operator * (const T &t, const complex<T> &z)
{
	return z*t;
}
