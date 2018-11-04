#include <iostream>
using namespace std;
class person {
	string name, familiq, status;
public:
	int date;
	person() {
		name = "";
		familiq = "";
		status = "";
		date = 0;
	}
	person(string x, string y, string z, int q) {
		name = x;
		familiq = y;
		status = z;
		date = q;
	}
	virtual int vuzrast() {
		return 2018 - date;
	}
	void show() {
		cout
				<< "\n\nIme: " + name + '\n' + "Familiq: " + familiq + '\n'
						+ "Status: " + status + '\n' + "Godina na rajdane: "
				<< date << endl;
	}
};
class student: public person {
	int fakn;
public:
	student(string n, string f, string s, int d, int x) :
			person(n, f, s, d) {
		fakn = x;
	}
	int vuzrast(){
		if(date>1990)
			return 1;
		else
			return 0;
	}
	void display() {
		show();
		cout << "Fak.nom: " << fakn;
	}
};
int main() {
	person *p,ob("Ivan ", " Ivanov", " student", 1995);
	student ob1("Nikolaj", "Nikolov", "studnet", 1998, 176214);
	ob.show();
	p=&ob;
	cout<<"Vuzrast: "<<(*p).vuzrast();
	ob1.display();
	p=&ob1;
	if((*p).vuzrast())
		cout<<"\nMladej";
	else
		cout<<"\nVuzrasten";
}
