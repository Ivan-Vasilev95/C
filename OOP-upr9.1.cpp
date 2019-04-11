#include<iostream>
#include<vector>
using namespace std;
class student {
	vector<int> grade;
	string fnum, name;
	double sr;
public:
	student() {
		fnum = "";
		name = "";
		sr = 0.0;
	}
	student(vector<int> gr, string fn, string nm, double sr2) {
		grade = gr;
		fnum = fn;
		name = nm;
		sr = sr2;
	}
	void ucenka(int x) {
		grade.push_back(x);
	}
	void sredno() {
		int temp = 0;
		for (int i = 0; i < grade.size(); i++) {
			temp += grade[i];
		}
		sr = temp / grade.size();
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "F.Number: " << fnum << endl;
		cout << "Average: " << sr << endl;
	}
};
int main() {
	vector<int> ocenka;
	student ob(ocenka, "17621308", "Ivan", 0.0);
	ob.ucenka(6);
	ob.ucenka(4);
	ob.ucenka(6);
	ob.sredno();
	ob.print();
}
