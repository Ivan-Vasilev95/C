#include <iostream>
using namespace std;
class myclass {
	double a, b, c;
public:
	myclass(double x) {
		a = x;
		b = x;
		c = x;
	}
	double obem(double x) {
		//x=a*b*c;
		return x;
	}
	void show() {
		double x;
		x = a * b * c;
		cout << endl << obem(x);
	}

};
int main() {
	myclass ob1(2.2), ob2(3.5);
	ob1.show();
	ob2.show();
}
