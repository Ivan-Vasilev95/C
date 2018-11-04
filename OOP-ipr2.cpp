#include <iostream>
using namespace std;
class myclass{
	int a;
public:
	int get_a();
	myclass();//default constructor
	myclass(int x);// ekspliciten
	myclass(const myclass &ob);//coppy constructor
	void show();
};
void myclass::show(){
	cout<<endl<<a;
}
myclass::myclass(){
	a=0;
}
myclass::myclass(int x){
	a=x;
}
myclass::myclass(const myclass &ob){
	a=ob.a;
}
int main(){
	myclass ob1,ob2(50),ob3(ob2);
	ob1.show();
	ob2.show();
	ob3.show();
}
