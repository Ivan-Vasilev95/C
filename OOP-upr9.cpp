#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
	vector<int> v(5, 1);
	vector<int>::iterator p;
	ostream_iterator<int> out(cout," ");
	copy(v.begin(), v.end(), out);
	cout<<endl;
	p=v.begin();
	p = p + 3;
	v.insert(p, 10, 9);
	copy(v.begin(), v.end(), out);
	cout<<endl;
	p=v.begin();
	v.erase(p+3, p + 13);
	copy(v.begin(), v.end(), out);
}
