#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> l1, l2;
	for (int i = 0; i < 10; i++)
		l1.push_back(rand() % 89 + 10);
	for (int i = 0; i < 10; i++)
		l2.push_back(rand() % 89 + 10);
	list<int>::iterator p = l1.begin();
	for (p = l1.begin(); p != l1.end(); p++)
		cout << *p<<" ";
	p = l2.begin();
	cout << endl;
	for (p = l2.begin(); p != l2.end(); p++)
		cout << *p<<" ";
	l1.sort();
	l2.sort();
	l1.merge(l2);
	p = l1.begin();
	cout << endl;
	for (p = l1.begin(); p != l1.end(); p++)
		cout << *p<<" ";
	cout << endl;
	p = l1.begin();
	advance(p,5);
	l1.insert(p, 3, 20);
	p = l1.end();
	l1.insert(p, 3, 99);
	p = l1.begin();
	for (p = l1.begin(); p != l1.end(); p++)
		cout << *p<<" ";
	l1.reverse();
	cout << endl;
	for (p = l1.begin(); p != l1.end(); p++)
		cout << *p<<" ";
	p = l1.begin();
	cout<<endl;
	l1.pop_front();
	l1.pop_front();
	l1.pop_front();
	for (p = l1.begin(); p != l1.end(); p++)
		cout << *p<<" ";
}
