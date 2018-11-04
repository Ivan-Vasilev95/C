//Template function example
#include <iostream>
using namespace std;
template<class T>
class myclass {
	T a, b;
public:
	myclass(T x, T y) {
		a = x;
		b = y;
	}
	T getmax() {
	return ((a>b)? a:b);
}
};
int main() {
	myclass<int> ob1(50, 100);
	myclass<double> ob2(100.5, 48.7);
	cout << endl << ob1.getmax();
	cout << endl << ob2.getmax();
}
