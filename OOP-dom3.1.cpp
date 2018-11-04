#include <iostream>
using namespace std;
class myclass {
	string name;
	string date;
	int visits;
public:
	myclass(string x = " ", string y = " ", int z = 0) {
		name = x;
		date = y;
		visits = z;
	}
	int get() {
		return visits;
	}
	friend ostream& operator <<(ostream& out, myclass& ob);
};
ostream& operator <<(ostream& out, myclass& ob) {
	return out << "Name: " + ob.name + " Date: " + ob.date;
}
int main() {
	int sum;
	int x = 3;
	myclass ob[x];
	ob[0] = myclass("Ivan", "12/06/1995", 7);
	ob[1] = myclass("Nikolai", "07/11/1999", 16);
	ob[2] = myclass("Georgi", "05/10/2000", 10);
	for (int i = 0; i < x; i++) {
		cout << ob[i] << " Visits: " << ob[i].get() << endl;
		sum += ob[i].get();
	}
	cout << endl << "Average of all visits " << (sum / x) << endl;
	for (int i = 0; i < x; i++) {
		if (ob[i].get() > 15) {
			cout << endl << ob[i] << ", has too many visits" << endl;
		}
	}
}
