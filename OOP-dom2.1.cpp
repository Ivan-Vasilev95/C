#include <iostream>
#include <cstring>
using namespace std;
class myclass {
	char a[5];
public:
	myclass(char x[]) {
		strcpy(a, x);
	}
	void show() {
		cout << a << endl;
	}
	myclass operator =(myclass ob) {
		strcpy(a, ob.a);
		return *this;
	}
	myclass operator +(myclass ob) {
		strcat(a, ob.a);
		return *this;
	}
	bool operator <(myclass ob) {
		if (strcmp(a, ob.a) < 0)
			return 1;
		else
			return 0;
	}
	bool operator >(myclass ob) {
		if (strcmp(a, ob.a) > 0)
			return 1;
		else
			return 0;
	}
	bool operator ==(myclass ob) {
		if (strcmp(a, ob.a) == 0)
			return 1;
		else
			return 0;
	}
};
int main() {
	myclass ob1("niz1"), ob2("niz1");
	cout << "Obekt 1 - ";
	ob1.show();
	cout << "Obekt 2 - ";
	ob2.show();
	if (ob1 > ob2)
		cout << "Obekt 1 e po golqm ot Obekt 2" << endl;
	else if (ob1 < ob2)
		cout << "Obekt 2 e po golqm ot Obekt 2" << endl;
	else
		cout << "Obekt 1 e raven na Obekt 2" << endl;
	ob1 = ob2;
	cout << "Prisvoqvame Obekt 2 na Obekt 1" << endl;
	ob1 + ob2;
	cout << "Subirame obekt 1 s obekt 2 - ";
	ob1.show();
}

