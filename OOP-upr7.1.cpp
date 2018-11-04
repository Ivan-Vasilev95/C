#include <iostream>
using namespace std;
const int raz = 5;
template<class T>
void show(T mas[]) {
	for (int i = 0; i < raz; i++) {
		cout << mas[i] << "//";
	}
}
template<class T>
void sortirane(T mas[]) {
	for (int i = 0; i < raz; i++) {
			for (int j = i; j < raz; j++) {
				if (mas[i] > mas[j]) {
					T element;
					element = mas[i];
					mas[i] = mas[j];
					mas[j] = element;
				}
			}
		}
}
int main() {
	int ob[5] = { 6, 8, 1,12,4};
	double ob2[5] = { 10.2, 10.8, 10.1,9.2,5.6};
	char ob3[5]={'a','d','c','b','e'};
	sortirane(ob);
	show(ob);
	cout << endl;
	sortirane(ob2);
	show(ob2);
	cout<<endl;
	sortirane(ob3);
	show(ob3);

}
