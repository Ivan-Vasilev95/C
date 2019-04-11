#include <iostream>
#include <vector>
using namespace std;
class reader {
	string name, fnumber;
public:
	reader() {
		name = "";
		fnumber = "";
	}
	reader(string x, string y) {
		name = x;
		fnumber = y;
	}
	reader(const reader& ob) {
		name = ob.name;
		fnumber = ob.fnumber;
	}
	void set_name(string x) {
		name = x;
	}
	void set_fnumber(string y) {
		fnumber = y;
	}
	string get_name() {
		return name;
	}
	string get_fnumber() {
		return fnumber;
	}
	void toString() {
		cout << endl << name + fnumber;
	}
	bool compare(const reader& ob) {
		return fnumber < ob.fnumber;
	}
	bool equal(const reader& ob) {
		return fnumber == ob.fnumber;
	}
	friend ostream& operator <<(ostream & out, reader& ob);
	friend istream& operator >>(istream& in, reader& ob);
};
ostream& operator <<(ostream & out, reader& ob) {
	return out << endl << "Name: " << ob.name << "\nFnumber: " << ob.fnumber;
}
istream& operator >>(istream& in, reader& ob) {
	string temp;
	cout << "Enter name: ";
	cin >> temp;
	ob.set_name(temp);
	cout << "Enter Fnumber: ";
	cin >> temp;
	ob.set_fnumber(temp);
	return in;
}
class LibraryBook: public reader {
	string bookname;
	bool status;
public:
	LibraryBook() {
		bookname = "";
		status = 0;
	}
	LibraryBook(string b, bool s) {
		bookname = b;
		status = s;
	}
	LibraryBook(const LibraryBook& ob) {
		bookname = ob.bookname;
		status = ob.status;
	}
	void set_bookname(string x) {
		bookname = x;
	}
	void set_status(bool y) {
		status = y;
	}
	string get_bookname() {
		return bookname;
	}
	bool get_status() {
		return status;
	}
	bool rentabook() {
		return status = 0;
	}
	bool returnabook() {
		return status = 1;
	}
	void check() {
		if (status == 0)
			cout << endl << "The book is not available!";
		else
			cout << endl << "The book is available!";
	}
	void checkname(string temp) {
		if (temp == bookname) {
			cout << endl << "The book is present!";
		} else
			cout << endl << "The book is not present!";
	}
	void preobrazuvane() {
		string str = to_string(status);
		cout << endl << bookname + str;
	}
	string changename(string temp){
		bookname=temp;
		return bookname;
	}
	friend ostream& operator <<(ostream& out, LibraryBook& ob);
	friend istream& operator >>(istream& in, LibraryBook& ob);
};
ostream& operator<<(ostream& out, LibraryBook& ob) {
	return out << endl << "Name of the book: " << ob.bookname << "\nStatus: "
			<< ob.status;
}
istream& operator>>(istream in, LibraryBook& ob) {
	string temp;
	bool temp1;
	cout << "Enter book name:";
	cin >> temp;
	ob.set_bookname(temp);
	cout << "Enter status: ";
	cin >> temp1;
	ob.set_status(temp1);
	return in;
}
int main() {
	string temp;
	vector<reader> ob;
	vector<LibraryBook> ob1;
	ob1.push_back(LibraryBook("HarryPotter", 1));
	ob.push_back(reader("Ivan", "17621308"));
	cout << ob[0];
	cout << ob1[0];
	cout << endl << "Testvane na funkcii\n";
	ob[0].toString();
	ob1[0].rentabook();
	cout << ob1[0];
	ob1[0].returnabook();
	cout << ob1[0];
	ob1[0].check();
	cout<<endl<<"Check for book: ";
	cin>>temp;
	ob1[0].checkname(temp);
	ob1[0].preobrazuvane();
	cout<<endl<<"Change name: ";
	cin>>temp;
	ob1[0].changename(temp);
	cout<<ob1[0];
}
