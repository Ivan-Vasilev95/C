#include <iostream>
using namespace std;
class dist{
public:
	double a;
	dist(double x){
		a=x;
	}
	virtual double trav_time(){
		return a/80;
	}
};
class metric:public dist{
public:
	metric(double x):dist(x){}
	double trav_time(){
		return a/100;
	}
};
int main(){
	dist *p,ob(100.2);
	metric ob1(200.2/1.6);
	p=&ob;
	cout<<endl<<p->trav_time();
	p=&ob1;
	cout<<endl<<(*p).trav_time();
}
