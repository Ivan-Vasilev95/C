#include <iostream>
using namespace std;
class myclass {
	int a;
	int b;
public:
	myclass(int x, int y) {
		a = x;
		b = y;
	}
	friend int delimost(myclass ob);
};
int delimost(myclass ob) {
	if (ob.a % ob.b == 0)
		return 1;
	else
		return 0;
}
int main() {
	myclass ob1(10, 6), ob2(12, 4);
	if (delimost(ob1))
		cout << endl << " delqt se !";
	else
		cout << endl << " ne se delqt!";
	if (delimost(ob2))
		cout << endl << " delqt se!";
	else
		cout << endl << " ne se delqt!";
}
