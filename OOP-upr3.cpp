#include <iostream>
using namespace std;
class date{
	int day,month,year;
public:
	date(int a ,int b, int c){
		day=a;
		month=b;
		year=c;
	}
	date(string x){
		day=stoi(x.substr(0,2));
		month=stoi(x.substr(3,4));
		year=stoi(x.substr(6,9));
	}
	void show(){
		cout<<endl<<day<<'.'<<month<<'.'<<year;
	}

};
int main(){
	date ob1(02,10,2018),ob2("02.10.2018");
	ob1.show();
	ob2.show();
}
