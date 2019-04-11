#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class c_person {
	string name;
	string egn;
public:
	c_person() {
		name = "";
		egn = "";
	}
	c_person(string ime, string egene) {
		name = ime;
		egn = egene;
	}
	void set_name(string x) {
		name = x;
	}
	void set_egn(string y) {
		egn = y;
	}
	string get_name() {
		return name;
	}
	string get_egn() {
		return egn;
	}
	bool operator <(c_person ob) {
		return egn < ob.egn;
	}
	bool operator ==(c_person ob) {
		return egn == ob.egn;
	}
	friend ostream& operator <<(ostream& out, c_person& ob);
	friend istream& operator >>(istream& in, c_person& ob);
};
ostream& operator <<(ostream& out, c_person& ob) {
	return out << endl << "Name: " << ob.name << "\nEGN: " << ob.egn << endl;
}
istream& operator >>(istream& in, c_person& ob) {
	string temp;
	cout << "Ime: ";
	cin >> temp;
	ob.set_name(temp);
	cout << "\nEGN: ";
	cin >> temp;
	ob.set_egn(temp);
	return in;
}
class c_city: public c_person {
	vector<c_person> ob;
public:
	c_city() {
		ifstream fp("data.txt");
		string temp1;
		string temp2;
		while (fp >> temp1 >> temp2) {
			ob.push_back(c_person(temp1, temp2));
		}
		for (int i = 0; i < ob.size(); i++) {
			cout << ob[i];
		}
	}
	c_city(string n, string e) :
			c_person(n, e) {
	}
	void remove_dublicate() {
		ob.erase(unique(ob.begin(), ob.end()));
		cout << "\nPopravka\n";
		for (int i = 0; i < ob.size(); i++)
			cout << ob[i];
	}
	void remove_vector() {
		string temp;
		vector<c_person> ob1;
		cin >> temp;
		ob1.push_back(c_city(temp, temp));
		for (int i = 0; i < ob.size(); i++) {
			if (ob[i] == ob1[0]) {
				ob.erase(ob.begin() + i);
			}
		}
		cout << "\nPremahnat\n";
		for (int i = 0; i < ob.size(); i++)
			cout << ob[i];
	}
	void get_dublicate() {
		for (int i = 0; i < ob.size(); i++) {
			for (int j = i; j < (ob.size()); j++) {
					if (i!=j && ob[i] == ob[j])
						cout << endl <<"Povtarqsht se vector"<<ob[i];
			}
		}
	}
};
int main() {
	c_city ob;
	ob.get_dublicate();
	ob.remove_dublicate();
	ob.remove_vector();
}
