#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v(6, 0);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	vector<int>::iterator p;
	p = v.begin();
	cout << endl;
	v[2]=3;
	v[4]=5;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
