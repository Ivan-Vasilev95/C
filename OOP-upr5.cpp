#include <iostream>
using namespace std;
class base{
	int i;
public:
	void set_i(int x){
		i=x;
	}
	int get_i(){
		return i;
	}
};
class dervated:public base{
	int j;
public:
	void set_j(int x){
		j=x;
	}
	int mul(){
		return get_i()*j;
	}
};
int main(){
	dervated ob1,ob2;
	ob1.set_i(10);
	ob1.set_j(20);
	cout<<ob1.mul();
	ob2.set_i(50);
	ob2.set_j(20);
	cout<<endl<<ob2.mul();
}
