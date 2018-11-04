#include <iostream>
using namespace std;
class area {
	double dim1, dim2;
public:
	void set_dim1(double x) {
		dim1 = x;
	}
	void set_dim2(double y) {
		dim2 = y;
	}
	double get_dim1() {
		return dim1;
	}
	double get_dim2() {
		return dim2;
	}
	virtual double lice() { //=0
		return 0.0;
	}
};
class rectangle: public area {
public:
	double lice() {
		double d1, d2;
		d1 = get_dim1();
		d2 = get_dim2();
		return d1 * d2;
	}
};
class triangle: public rectangle {
public:
	double lice() {
		return (get_dim1() * get_dim2() )/2;
	}
};
int main() {
	area *p; // definirame ukazatel kum bazoviq class pri virtualni funk
	rectangle r;
	triangle t;
	r.set_dim1(15);
	r.set_dim2(10);
	t.set_dim1(10);
	t.set_dim2(6);
	p = &r;
	cout << endl << p->lice(); //(*p).lice();
	p = &t;
	cout << endl << (*p).lice();
}
