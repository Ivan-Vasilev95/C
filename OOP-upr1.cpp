#include <iostream>
using namespace std;
class myclass {
//public:
	int a;
public:
	void set_a(int x);
	int get_a();
};
void myclass::set_a(int x) {
	a = x;
}
int myclass::get_a() {
	return a;
}
int main() {
	myclass ab1, ab2;
	ab1.set_a(10);//ab1.a=10;
	ab2.set_a(20);
	cout << endl << ab1.get_a();//ab1.a;
	cout << endl << ab2.get_a();
}
