#include <iostream>
#include <vector>
using namespace std;
class rectangle {
	int x1, y1, x2, y2;
public:
	rectangle() {
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}
	rectangle(int x, int y, int z, int w) {
		x1 = x;
		y1 = y;
		x2 = z;
		y2 = w;
	}
	rectangle(const rectangle& ob) {
		x1 = ob.x1;
		y1 = ob.y1;
		x2 = ob.x2;
		y2 = ob.y2;
	}
	void set_x1(int x) {
		x1 = x;
	}
	int get_x1() {
		return x1;
	}
	void set_y1(int x) {
		y1 = x;
	}
	int get_y1() {
		return y1;
	}
	void set_x2(int x) {
		x2 = x;
	}
	int get_x2() {
		return x2;
	}
	void set_y2(int x) {
		y2 = x;
	}
	int get_y2() {
		return y2;
	}
	void Rectangle() {
		int posX = 1, posY = 3;
		char symbol, empty;
		symbol = '.';
		empty = ' ';
		//purvi pravougulnik
		string firstandlastrow(y1, symbol);
		string posYstring(posY, empty);
		for (int row = 0; row < posX; row++)
			cout << endl;
		cout << posYstring;
		cout << firstandlastrow << endl;
		for (int row = 1; row < x1 - 1; row++) {
			string betweenrow(y1, empty);
			betweenrow[0] = symbol;
			betweenrow[y1 - 1] = symbol;
			cout << posYstring;
			cout << betweenrow << endl;
		}
		cout << posYstring;
		cout << firstandlastrow << endl;
		//vtori pravougulnik
		string firstandlastrow1(y2, symbol);
		string posYstring1(y1 + posY - 1, empty);
		cout << posYstring1;
		cout << firstandlastrow1 << endl;
		for (int row = 1; row < x2 - 1; row++) {
			string betweenrow(y2, empty);
			betweenrow[0] = symbol;
			betweenrow[y2 - 1] = symbol;
			cout << posYstring1;
			cout << betweenrow << endl;
		}
		cout << posYstring1;
		cout << firstandlastrow1 << endl << endl;
		//dvata pravougulnika obedineni
		cout << "Obedinenie" << endl;
		string firstandlastrow2(y1 + y2 - 1, symbol);
		string posYstring2(posY, empty);
		cout << posYstring2;
		cout << firstandlastrow2 << endl;
		for (int row = 1; row < x1 + x2 - 1; row++) {
			string betweenrow(y1 + y2, empty);
			betweenrow[0] = symbol;
			betweenrow[y1 + y2 - 2] = symbol;
			cout << posYstring;
			cout << betweenrow << endl;
		}
		cout << posYstring;
		cout << firstandlastrow2 << endl;

	}
	friend ostream& operator <<(ostream& out, rectangle& ob);
	friend istream& operator >>(istream& in, rectangle& ob);
};
ostream& operator <<(ostream& out, rectangle& ob) {
	return out << "\nParametri na pravougulnik 1\n" << "Viso4ina: " << ob.x1
			<< "\nShirina: " << ob.y1 << "\nParametri na pravougulnik 2\n"
			<< "Viso4ina: " << ob.x2 << "\nShirina: " << ob.y2;
}
istream& operator >>(istream& in, rectangle& ob) {
	int temp1, temp2, temp3, temp4;
	cout << "\nVuvedete viso4ina na pravougulnik 1: ";
	cin >> temp1;
	ob.set_x1(temp1);
	cout << "\nVuvedete Shirina na pravougulnik 1: ";
	cin >> temp2;
	ob.set_y1(temp2);
	cout << "\nVuvedete viso4ina na pravougulnik 2: ";
	cin >> temp3;
	ob.set_x2(temp3);
	cout << "\nVuvedete Shirina na pravougulnik 2: ";
	cin >> temp4;
	ob.set_y2(temp4);
	return in;
}
int main() {
	vector<rectangle> ob;
	ob.push_back(rectangle(5, 15, 4, 12));
	ob[0].Rectangle();
	cout<<ob[0];
}
