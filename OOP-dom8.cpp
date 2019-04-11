#include<iostream>
#include<vector>
//using namespace std;
class student {
	std::vector<int> grade;
	std::string fnum, name;
	double sr;
public:
	student() {
		fnum = "";
		name = "";
		sr = 0.0;
	}
	student(std::vector<int> gr, std::string fn, std::string nm, double sr2) {
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
		std::cout << "Name: " << name << std::endl;
		std::cout << "F.Number: " << fnum << std::endl;
		std::cout << "Average: " << sr << std::endl;
	}
};
int main() {
	std::vector<int> ucenki;
	std::vector<student> ob;
	ob.push_back(student(ucenki, "17621308", "Ivan", 0.0));
	ob.push_back(student(ucenki, "17621309", "Nikolai", 0.0));
	ob.push_back(student(ucenki, "17621310", "Georgi", 0.0));
	ob.push_back(student(ucenki, "17621311", "Victor", 0.0));
	ob[0].ucenka(6);
	ob[0].ucenka(6);
	ob[0].ucenka(6);
	ob[0].ucenka(6);
	ob[1].ucenka(6);
	ob[1].ucenka(5);
	ob[1].ucenka(6);
	ob[1].ucenka(5);
	ob[2].ucenka(4);
	ob[2].ucenka(3);
	ob[2].ucenka(4);
	ob[2].ucenka(5);
	ob[3].ucenka(5);
	ob[3].ucenka(3);
	ob[3].ucenka(4);
	ob[3].ucenka(6);
	for (int i = 0; i < ob.size(); i++)
		ob[i].sredno();
	for (int i = 0; i < ob.size(); i++)
		ob[i].print();

}
