#include <iostream>
#include <math.h>
using namespace std;

class MyVector {
private :
	double* p;
	int dimension;
	double len;
public :
	MyVector(int dimesion) {
		double* temp = new double[dimension];
		p = temp;
		this->dimension = dimension;
	}
	MyVector(int dimension) {
		double* temp = new double[dimension];
		int index = 0;
		int num;
		while (cin >> num && index < dimension) {
			temp[index++] = num;
		}
		p = temp;
		this->dimension = dimension;
	}
	void unify() {
		double sum = 0;
		for (int i = 0; i < dimension; i++) {
			sum += p[i] * p[i];
		}
		len = sqrt(sum);
		for (int i = 0; i < dimension; i++) {
			p[i] = p[i] / len;
		}
	}
	void setP(double* _p) {
		p = _p;
	}
	double operator* (MyVector);
	MyVector& operator* (double k);
	friend bool operator== (MyVector v1, double* v2);
	MyVector operator+ (MyVector);
	MyVector operator- (MyVector);
};
MyVector& MyVector::operator* (double k) {
	for (int i = 0; this->dimension; i++) {
		this->p[i] = k * this->p[i];
	}
	return *this;
}
bool operator == (MyVector v1, double* v2) {
	for (int i = 0; i < v1.dimension; i++) {
		if (v1.p[i] != v2[i])
			return false;
	}
	return true;
}
double MyVector ::operator* (MyVector v2) {
	double result;
	for (int i = 0; i < dimension; i++) {
		result+= this->p[i] * v2.p[i];
	}
	return result;
}

MyVector MyVector ::operator+ (MyVector v2) {
	MyVector returnVec(this->dimension);

	for (int i = 0; i < this->dimension; i++) {
		returnVec.p[i] = this->p[i] + v2.p[i];
	}
	return returnVec;
}
MyVector MyVector ::operator- (MyVector v2) {
	MyVector returnVec(this->dimension);

	for (int i = 0; i < this->dimension; i++) {
		returnVec.p[i] = this->p[i] - v2.p[i];
	}
	return returnVec;
}
double* makeBasis(MyVector orthomatrix[], MyVector vec, int len) {
	double* temp;
	for (int i = 0; i < len; i++) {
		+= orthomatrix[i] * (orthomatrix[i] * vec);
	}
}

int main(void) {
	int dimension;
	cout << "dimension : ";
	cin >> dimension;

	MyVector matrix = (new MyVector(dimension))[dimension]; //ø÷¿œ±Ó?
	MyVector orthoMatrix = (new MyVector(dimension))[dimension];


}