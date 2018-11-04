#include <iostream>
#include <cstring>
using namespace std;
class banckaccount {
	char name[23];
	char num[15];
	double sum;
public:
	banckaccount() {
		 name[23]={ };
		 num[15]={ };
		 sum=0;
	}
	friend ostream& operator <<(ostream& out, banckaccount& ob);
	friend istream& operator >>(istream& in, banckaccount& ob);
	void depozit(double funds) {
		sum += funds;
		cout << "Banlansa vi e: " << sum << endl;
	}
	void teglene(double funds) {
		if (funds < sum) {
			sum -= funds;
			cout << "Balansa vi e :" << sum << endl;
		} else
			cout << "Nqmate dostatu4no pari" << endl;
	}
};
ostream& operator <<(ostream& out, banckaccount& ob) {
	return out << "Ime: " << ob.name << '\n' << "Nomer na smetka: " << ob.num
			<< '\n' << "Balans: " << ob.sum << endl;
}
istream& operator >>(istream& in, banckaccount& ob) {
	if (strlen(ob.name) <= 23 && strlen(ob.num) <= 15) {
		cout << "\n Vuvedete ime i nomer na smetka" << endl;
		in >> ob.name >> ob.num;
	} else
		cout
				<< "\n Prekaleno mnogo sinvoli imeto trqbva da e do 23 i nomera do 15 sinvola";
	cout << "\n Vuvedete sumata koqto 6te e vuv va6ata smetka\n";
	in >> ob.sum;
	return in;
}
int main() {
	int izbor;
	banckaccount ob1;
	while (izbor != 5) {
		cout << "Vashiqt izbor" << endl;
		cout
				<< " 1:Suzdaite smetka\n 2:Account info\n 3:Vnoska\n 4:Teglene\n 5:Exit"
				<< endl;
		cin >> izbor;
		switch (izbor) {
		case 1:
			cin >> ob1;
			break;
		case 2:
			cout << ob1;
			break;
		case 3:
			cout << "Kolko pari jelaete da vnesete (natisnete 0 za izhod)";
			cin >> izbor;
			if (izbor == 0)
				break;
			ob1.depozit(izbor);
			break;
		case 4:
			cout << "Kolko pari jelaete da izteglite (natisnete 0 za izhod)";
			cin >> izbor;
			if (izbor == 0)
				break;
			ob1.teglene(izbor);
			break;
		case 5:
			break;
		}
	}
}
