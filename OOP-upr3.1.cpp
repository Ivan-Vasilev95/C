#include<iostream>
using namespace std;
class myclass{
	int a,b;
public:
	myclass(){
		a=0;
		b=0;
	}
	myclass(int x,int y){
		a=x;
		b=y;
	}
	myclass operator +(myclass ob){
		myclass temp;
		temp.a=a+ob.a;
		temp.b=b+ob.b;
		return temp;
	}
	myclass operator -(myclass ob){
		myclass temp;
		temp.a=a-ob.a;
		temp.b=b-ob.b;
		return temp;
	}
	myclass operator =(myclass ob){
		a=ob.a;
		b=ob.b;
		return *this;
	}
	void show(){
		cout<<endl<<a<<"-"<<b;
	}
};
int main(){
	myclass ob1(40,30),ob2(20,10),ob3;
	ob3=ob1+ob2;
	ob3.show();
	ob3=ob1-ob2;
	ob3.show();
}
