#include<iostream>
#include<list>
#include <iterator>
using namespace std;
class project {
	string name;
	int days;
public:
	project() {
		name = "";
		days = 0;
	}
	project(string ime, int dni) {
		name = ime;
		days = dni;
	}
	bool operator <(project ob) {
		return days < ob.days;
	}
	friend ostream& operator <<(ostream& out, project& ob);
};
ostream& operator <<(ostream& out, project& ob) {
	return out << "Ime:" << ob.name << "  Dni:" << ob.days << endl;
}
int main() {
	list<project> l1,l2;
		list<project>::iterator p = l1.begin();
		l1.push_back(project("A", 4));
		l1.push_back(project("B", 6));
		l1.push_back(project("C", 5));

		l2.push_back(project("D", 2));
		l2.push_back(project("E", 3));
		l2.push_back(project("F", 1));

		l1.sort();
		for (p = l1.begin(); p != l1.end(); p++)
			cout << *p << " ";
		l2.sort();
		cout << endl;
		for (p = l2.begin(); p != l2.end(); p++)
			cout << *p << " ";
		cout<<endl;
		l1.merge(l2);
		for (p = l1.begin(); p != l1.end(); p++) {
			cout << *p<<" ";
		}
		cout<<endl;
		p--;
		cout<<"Proekta s nai mnogo dni\n";
		cout<<*p;
}
