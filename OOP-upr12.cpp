#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;
int main() {
	map<string, string> m;
	m.insert(pair<string, string>("Good", "Bad"));
	m.insert(pair<string, string>("Happy", "Sad"));
	m.insert(pair<string, string>("White", "Black"));
	map<string, string>::iterator p = m.begin();
	cout << endl << "Na koq duma tursite antonim: ";
	string duma;
	getline(cin, duma);
	p = m.find(duma);
	if (p != m.end())
		cout << endl << (*p).second;
	else
		cout << endl << duma << " ne se sudurja";
}
