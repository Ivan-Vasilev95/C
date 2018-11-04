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
	friend int speed(car ob, truck ob1);
};
class truck {
	int a;
	int b;
public:
	truck(int x, int y) {
		a = x;
		b = y;
	}
	friend int speed(car ob, truck ob1);
};
int speed(car ob, truck ob1) {
	if (ob.b > ob1.b)
		return 1;
	else
		return 0;
}
int main() {
	car ob1(2, 30), ob2(3, 40);
	truck ob3(500, 50), ob4(400, 20);
	if (speed(ob1, ob3))
		cout << endl << " kolata e po burza ";
	else
		cout << endl << "Kamiona e po burz ";
	if (speed(ob2, ob4))
		cout << endl << " kolata e po burza ";
	else
		cout << endl << "Kamiona e po burz ";
}
