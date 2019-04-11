#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int main() {
	map<string, string> m;
	m.insert(pair<string, string>("089953256", "Ivan"));
	m.insert(pair<string, string>("089325640", "Niki"));
	m.insert(pair<string, string>("893002145", "Mica"));
	m.insert(pair<string, string>("089177421", "Stefan"));
	map<string, string>::iterator p = m.begin();
	cout<<endl<<"Nomer:";
	string nomer;
	getline(cin, nomer);
	p = m.find(nomer);
	if (p != m.end())
		cout << endl << (*p).second;
	else
		cout << endl << nomer << " ne se sudurja";

}
