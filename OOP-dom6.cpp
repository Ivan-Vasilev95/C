#include <iostream>
using namespace std;
int const raz = 5;
class cstudent {
	string name, pol, fnum;
	double ag;
public:
	void set_name(string x) {
		name = x;
	}
	void set_pol(string y) {
		pol = y;
	}
	void set_fnum(string z) {
		fnum = z;
	}
	void set_ag(double q) {
		ag = q;
	}
	string get_name() {
		return name;
	}
	string get_pol() {
		return pol;
	}
	string get_fnum() {
		return fnum;
	}
	double get_ag() {
		return ag;
	}
	void show() {
		cout << "\nime: " << get_name() << "\nPol: " << get_pol()
				<< "\nFakulteten nomer: " << get_fnum() << "\nSredna ucenka: "
				<< get_ag()<<'\n';

	}
	bool operator <(cstudent ob) {
		return name < ob.name;
	}
	friend ostream& operator <<(ostream& out, cstudent& ob);
	friend istream& operator >>(istream& in, cstudent& ob);
};
ostream& operator <<(ostream& out, cstudent& ob) {
	return out << endl << "\nIme:" << ob.name << "\nPol: " << ob.pol
			<< "\nFakulteten nomer: " << ob.fnum << "\nSredna ucenka: " << ob.ag
			<< '\n';
}
istream& operator >>(istream& in, cstudent& ob) {
	cout << endl << "\nIme:" << ob.name << "\nPol: " << ob.pol
			<< "\nFakulteten nomer: " << ob.fnum << "\nSredna ucenka: " << ob.ag
			<< '\n';
	return in;
}
class studentinfo: public cstudent {
public:
	void info(cstudent ob[raz]) {
		string temp1;
		double temp2;
		for (int i = 0; i < raz; i++) {
			cout << "\nVuvedete ime na studnet " << i + 1;
			cin >> temp1;
			ob[i].set_name(temp1);
			cout << "\nVuvedete pol na student " << i + 1;
			cin >> temp1;
			ob[i].set_pol(temp1);
			cout << "\nVuvedete fakulteten nomer na student " << i + 1;
			cin >> temp1;
			ob[i].set_fnum(temp1);
			cout << "\nVuvedete sredna ucenka na studenta " << i + 1;
			cin >> temp2;
			ob[i].set_ag(temp2);
		}
		for (int i = 0; i < raz; i++) {
			cout << ob[i];
		}
	}
	void sort(cstudent ob[raz]) {
		for (int i = 0; i < raz; i++) {
			for (int j = i; j < raz; j++) {
				if (ob[j] < ob[i]) {
					cstudent temp;
					temp = ob[i];
					ob[i] = ob[j];
					ob[j] = temp;
				}
			}
		}
		cout << "\nSled sortirane po ime\n";
		for (int i = 0; i < raz; i++) {
			cout << ob[i];
		}
	}
	void max(cstudent ob[raz]) {
		double temp = 0;
		for (int i = 0; i < raz; i++) {
			if (temp < ob[i].get_ag())
				temp = ob[i].get_ag();
		}
		cout << "\nNai golqmata sredna ucenka e :" << temp;
		for (int i = 0; i < raz; i++) {
			cout << ob[i];
		}
	}
};
int main() {
	cstudent ob[raz];
	studentinfo ob1;
	ob1.info(ob);
	ob1.max(ob);
	ob1.sort(ob);
}
