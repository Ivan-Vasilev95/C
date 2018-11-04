#include <iostream>
using namespace std;
class myclass{
	int a;
public:
	myclass(int x){
		a=x;
	}
	bool operator >(myclass ob){
		return a>ob.a;
	}
	bool operator <(myclass ob){
		return a<ob.a;
	}
	bool operator ==(myclass ob){
		return a==ob.a;
	}
	bool operator &&(myclass ob){
		if(a==1 && ob.a==1)
			return 1;
		else
			return 0;
	}
	void show(){
		cout<<a<<endl;
	}
};
int main(){
	myclass ob1(20),ob2(10);
	cout<<"ob1=";
	ob1.show();
	cout<<"ob2=";
	ob2.show();
	if((ob1>ob2) && (ob2<ob1))
		cout<<endl<<"operatori >< i && rabotqt";
	if(ob1==ob2)
		cout<<" operator == raboti ";
	else
		cout<<endl<<"ne sa ravni no == raboti";

}
