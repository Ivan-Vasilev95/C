#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
bool oddd(int x) {
	return (x % 2 != 0);
}
int kvadrat(int x) {
	return x * x;
}

int main() {
	vector<int> v1;
	vector<float> v2;
	v1.push_back(12);
	v1.push_back(5);
	v1.push_back(6);
	v2.push_back(3.2);
	v2.push_back(6.2);
	v2.push_back(13.2);
	cout << accumulate(v1.begin(), v1.end(), 0);
	cout << endl << accumulate(v2.begin(), v2.end(), 1.0f, multiplies<float>());
	vector<string> arr;
	arr.push_back("This");
	arr.push_back(" is");
	arr.push_back(" a");
	arr.push_back(" dog");
	cout << endl << accumulate(arr.begin(), arr.end(), string(""));
	cout << endl << inner_product(v1.begin(), v1.end(), v2.begin(), 0);
	remove_copy(v1.begin(), v1.end(), v2.begin(), 12);
	vector<float>::iterator p = v2.begin();
	cout << endl;
	for (p = v2.begin(); p != v2.end(); p++)
		cout << *p << " ";
	int br = count_if(v1.begin(), v1.end(), oddd);
	cout << endl << br << endl;
	transform(v1.begin(), v1.end(), v2.begin(), kvadrat);
	for (p = v2.begin(); p != v2.end(); p++)
		cout << *p << " ";
}
