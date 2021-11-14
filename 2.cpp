#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class MyVector {
private :
	double* p;
	int dimension;
public :
	MyVector(const MyVector& s) {
		//p = this->p;
		dimension = s.dimension;
		p = new double[dimension];
		for (int i = 0; i < dimension; i++) {
			p[i] = s.p[i];
		}
	}
	MyVector() {};
	MyVector(int _dimension, double* _p) {
		dimension = _dimension;
		p = _p;
	}
	MyVector(int _dimension) {
		dimension = _dimension;
		double* temp = new double[_dimension];
		int index = 0;
		int num;
		cout << "input " << dimension << "double num" << endl;

		while (index < _dimension && cin >> num) {
			temp[index] = num;
			index++;
		}
		p = temp;
	}
	int getDimension() {
		return dimension;
	}
	void zero() {
		for (int i = 0; i < dimension; i++) {
			p[i] = 0;
		}
	}
	void unify() {
		double sum = 0, len;
		for (int i = 0; i < dimension; i++) {
			sum += p[i] * p[i];
		}
		len = sqrt(sum);

		for (int i = 0; i < dimension; i++) {
			p[i] = p[i] / len;
		}

		double temp = 1 / len;
		double temp2 = 3 * temp;
	}
	void setP(double* _p) {
		p = _p;
	}
	void show() {
		for (int i = 0; i < dimension; i++) {
			cout  << setw(15) << p[i] << ' ';
		}cout << endl;
	}
	double operator* (MyVector);
	MyVector operator* (double k);
	friend bool operator== (MyVector v1, double* v2);
	MyVector operator+ (MyVector);
	MyVector operator- ();
};
double MyVector::operator* (MyVector v) {
	double result = 0;
	for (int i = 0; i < this->dimension; i++) {
		result += p[i] * v.p[i];
	}
	return result;
}
MyVector MyVector::operator* (double k) {
	MyVector newV = *this;
	for (int i = 0; i < dimension; i++) {
		newV.p[i] = k * p[i]; ////////////////////////////////////////////////
	}
	return  newV;
}
bool operator== (MyVector v, double* v2) {
	for (int i = 0; i < v.dimension; i++) {
		if (v.p[i] != v2[i])
			return false;
	}
	return true;
}
MyVector MyVector::operator+ (MyVector v) {
	MyVector newV = *this;
	for (int i = 0; i < dimension; i++) {
		newV.p[i] = p[i] + v.p[i];
	}
	return newV;
}
MyVector MyVector::operator- () {
	MyVector newV = *this;
	for (int i = 0; i < dimension; i++) {
		newV.p[i] = -p[i];
	}
	return newV;
}

MyVector makeBasis(MyVector* orthomatrix, MyVector vec, int len) {
	double* zeroV = new double[vec.getDimension()];
	for (int i = 0; i < vec.getDimension(); i++) {
		zeroV[i] = 0;
	}
	MyVector zero(vec.getDimension(), zeroV);

	for (int i = 0; i < len; i++) {
		zero = zero + orthomatrix[i] * (orthomatrix[i] * vec); ////////////////////////////////////////
	}
	return zero;
}
void zero(double* v, int dimension) {
	for (int i = 0; i < dimension; i++) {
		v[i] = 0;
	}
}

int main(void) {
	int dimension, orthoSize = 0;
	cout << "dimension : ";
	cin >> dimension;
	double* zeroV = new double[dimension];
	zero(zeroV, dimension);
	MyVector* orthoMatrix = new MyVector[dimension];
	while (orthoSize < dimension) {
		if (orthoSize == 0) {
			MyVector v(dimension);
			v.unify();
			orthoMatrix[orthoSize] = v;
			orthoSize++;
		}
		else {
			MyVector v(dimension);
			MyVector temp;
			temp = makeBasis(orthoMatrix, v, orthoSize);
			v = v +(-temp);

			if (v == zeroV) {
				cout << "input Vector is in orthoMatrix" << endl;
			}
			
			else {
				v.unify();
				orthoMatrix[orthoSize] = v;
				orthoSize++;
			}
		}
	}
	cout << endl;
	cout << "Fianlly orthoMatrix is made!!" << endl;
	cout << endl;
	for (int i = 0; i < orthoSize; i++) {
		cout << "[" << i + 1 << "] : ";
		orthoMatrix[i].show();
	}
	//ortho 확인하기
	for (int i = 0; i < dimension -1; i++) {
		for (int u = i + 1; u < dimension; u++) {
			cout << "(" << i << ", " << u << ") : ";
			cout << orthoMatrix[i] * orthoMatrix[u] << endl;
		}
	}
	cout << endl;
	cout << "Now write a vector(same dimension)" << endl;
	cout << "I'll show you a linear combination of basis" << endl;
	cout << endl;

	MyVector inputV(dimension);
	double* linearcoefficient = new double[dimension];
	
	for (int i = 0; i < dimension; i++) {
		linearcoefficient[i] = orthoMatrix[i] * inputV;
	}

	MyVector coefficient(dimension, linearcoefficient);
	coefficient.show();

	
}