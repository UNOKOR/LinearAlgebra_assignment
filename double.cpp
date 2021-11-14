#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
	double a = 3;
	double b = sqrt(a);
	double c = 1;
	double d = 0;
	for (int i = 0; i < 3; i++) {
		d += c * c;
	}
	
	cout << 1 / b * sqrt(d) << endl;
	return 0;
}