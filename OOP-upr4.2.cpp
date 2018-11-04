#include <iostream>
using namespace std;
class truck;
class car {
	int a;
	int b;
public:
	car(int x, int y) {
		a = x;
		b = y;
	}
	bool speed(truck&);
};
class truck {
	int a;
	int b;
public:
	truck(int x, int y) {
		a = x;
		b = y;
	}
	friend bool car::speed(truck&);
};
bool car::speed(truck &ob) {
	if (b > ob.b)
		return 1;
	else
		return 0;
}
int main() {
	car ob1(2, 60), ob2(3, 10);
	truck ob3(500, 50), ob4(400, 20);
	if (ob1.speed(ob3))
		cout << endl << " Kolata e po burza ";
	else
		cout << endl << " Kamiona e po burz ";
	if (ob2.speed(ob4))
		cout << endl << " Kolata e po burza ";
	else
		cout << endl << " Kamiona e po burz ";
}
