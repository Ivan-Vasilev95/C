#include <iostream>
using namespace std;
int n, p;
bool binary(int num, bool arr[]) {
	int temp = num;
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = num % 2;
		num = num / 2;
	}
	if (temp < 0)
		arr[0] = 1;
	else
		arr[0] = 0;
	return arr[n];
}
bool corection(bool arr[]) {
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == 0) {
			k++;
		} else
			break;
	}
	for (int j = 0; j < k; j++) {
		for (int i = 1; i < n; i++) {
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = 0;
	}
	return arr[n];
}
bool negative(bool arr[]) {
	for (int i = 1; i < n; i++) {
		if (arr[i] == 0)
			arr[i] = 1;
		else
			arr[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			arr[i] = 1;
			break;
		} else
			arr[i] = 0;
	}
	return arr[n];
}
int N(bool arr[]) {
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == 0) {
			k++;
		} else
			break;
	}
	return k;
}
void delene(int x, int y, bool a[], bool b[], bool c[]) {
	bool z[n];
	if (x < 0 || y < 0) {
		for (int i = 0; i < n - p; i++)
			z[i] = 1;
	} else if (x > 0 && y > 0) {
		for (int i = 0; i < p; i++)
			z[i] = 0;
	}
	bool temp[n];
	bool znak1 = a[0];
	for (int i = n - 5; i < n; i++) {
		cout << endl << endl;
		int temp1 = 0;
		if (znak1 != b[0]) {
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] == 0 && b[i] == 0 && temp1 == 0)
					temp[i] = 0;
				else if (a[i] == 0 && b[i] == 0 && temp1 == 1) {
					temp[i] = 1;
					temp1 = 0;
				} else if (a[i] == 0 && b[i] == 1 && temp1 == 0)
					temp[i] = 1;
				else if (a[i] == 0 && b[i] == 1 && temp1 == 1) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && b[i] == 0 && temp1 == 0)
					temp[i] = 1;
				else if (a[i] == 1 && b[i] == 0 && temp1 == 1) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && b[i] == 1 && temp1 == 0) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && b[i] == 1 && temp1 == 1) {
					temp[i] = 1;
					temp1 = 1;
				}
			}
			for (int i = 0; i < n; i++)
				cout << a[i];
			cout << endl;
			for (int i = 0; i < n; i++)
				cout << b[i];
			cout << endl << endl;
			for (int i = 0; i < n; i++)
				cout << temp[i];
			temp1 = 0;
			if (temp[0] != b[0])
				z[i] = 0;
			else
				z[i] = 1;
		} else {
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] == 0 && c[i] == 0 && temp1 == 0)
					temp[i] = 0;
				else if (a[i] == 0 && c[i] == 0 && temp1 == 1) {
					temp[i] = 1;
					temp1 = 0;
				} else if (a[i] == 0 && c[i] == 1 && temp1 == 0)
					temp[i] = 1;
				else if (a[i] == 0 && c[i] == 1 && temp1 == 1) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && c[i] == 0 && temp1 == 0)
					temp[i] = 1;
				else if (a[i] == 1 && c[i] == 0 && temp1 == 1) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && c[i] == 1 && temp1 == 0) {
					temp[i] = 0;
					temp1 = 1;
				} else if (a[i] == 1 && c[i] == 1 && temp1 == 1) {
					temp[i] = 1;
					temp1 = 1;
				}
			}
			for (int i = 0; i < n; i++)
				cout << a[i];
			cout << endl;
			for (int i = 0; i < n; i++)
				cout << c[i];
			cout << endl << endl;
			for (int i = 0; i < n; i++)
				cout << temp[i];
			temp1 = 0;
			if (temp[0] != b[0])
				z[i] = 0;
			else
				z[i] = 1;
		}
		znak1 = temp[0];
		for (int i = 0; i < n; i++)
			temp[i] = temp[i + 1];
		temp[n - 1] = 0;
		i++;
		if (i < n) {
			if (znak1 != b[0]) {
				for (int i = n - 1; i >= 0; i--) {
					if (temp[i] == 0 && b[i] == 0 && temp1 == 0)
						a[i] = 0;
					else if (temp[i] == 0 && b[i] == 0 && temp1 == 1) {
						a[i] = 1;
						temp1 = 0;
					} else if (temp[i] == 0 && b[i] == 1 && temp1 == 0)
						a[i] = 1;
					else if (temp[i] == 0 && b[i] == 1 && temp1 == 1) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && b[i] == 0 && temp1 == 0)
						a[i] = 1;
					else if (temp[i] == 1 && b[i] == 0 && temp1 == 1) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && b[i] == 1 && temp1 == 0) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && b[i] == 1 && temp1 == 1) {
						a[i] = 1;
						temp1 = 1;
					}
				}
				cout << endl << endl;
				for (int i = 0; i < n; i++)
					cout << temp[i];
				cout << endl;
				for (int i = 0; i < n; i++)
					cout << b[i];
				cout << endl << endl;
				for (int i = 0; i < n; i++)
					cout << a[i];
				temp1 = 0;
				if (a[0] != b[0])
					z[i] = 0;
				else
					z[i] = 1;
			} else {
				for (int i = n - 1; i >= 0; i--) {
					if (temp[i] == 0 && c[i] == 0 && temp1 == 0)
						a[i] = 0;
					else if (temp[i] == 0 && c[i] == 0 && temp1 == 1) {
						a[i] = 1;
						temp1 = 0;
					} else if (temp[i] == 0 && c[i] == 1 && temp1 == 0)
						a[i] = 1;
					else if (temp[i] == 0 && c[i] == 1 && temp1 == 1) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && c[i] == 0 && temp1 == 0)
						a[i] = 1;
					else if (temp[i] == 1 && c[i] == 0 && temp1 == 1) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && c[i] == 1 && temp1 == 0) {
						a[i] = 0;
						temp1 = 1;
					} else if (temp[i] == 1 && c[i] == 1 && temp1 == 1) {
						a[i] = 1;
						temp1 = 1;
					}
				}
				cout << endl << endl;
				for (int i = 0; i < n; i++)
					cout << temp[i];
				cout << endl;
				for (int i = 0; i < n; i++)
					cout << c[i];
				cout << endl << endl;
				for (int i = 0; i < n; i++)
					cout << a[i];
				temp1 = 0;
				if (a[0] != b[0])
					z[i] = 0;
				else
					z[i] = 1;
			}
			znak1 = a[0];
			for (int i = 0; i < n; i++)
				a[i] = a[i + 1];
			a[n - 1] = 0;
		}
	}
	cout << endl << "________________" << endl;
	cout<<"Z=";
	if (x > 0 && y > 0) {
		z[0]=0;
		for (int i = 0; i < n; i++)
			cout << z[i];
	} else if (x > 0 && y < 0) {
		int temp = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (z[i] == 0 && temp == 0) {
				z[i] = 1;
				break;
			} else if (z[i] == 0 && temp == 1) {
				z[i] = 1;
				temp = 0;
				break;
			} else if (z[i] == 1 && temp == 0) {
				z[i] = 0;
				temp = 1;
			} else if (z[i] == 1 && temp == 1) {
				z[i] = 0;
				temp = 1;
			}
		}
		negative(z);
		z[0]=1;
		for (int i = 0; i < n; i++)
			cout << z[i];
	} else if (x < 0 && y > 0) {
		if (znak1 == 1) {
			int temp = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (z[i] == 0 && temp == 0) {
					z[i] = 1;
					break;
				} else if (z[i] == 0 && temp == 1) {
					z[i] = 1;
					temp = 0;
					break;
				} else if (z[i] == 1 && temp == 0) {
					z[i] = 0;
					temp = 1;
				} else if (z[i] == 1 && temp == 1) {
					z[i] = 0;
					temp = 1;
				}
			}
			negative(z);
			z[0]=1;
			for (int i = 0; i < n; i++)
				cout << z[i];
		} else {
			negative(z);
			z[0]=1;
			for (int i = 0; i < n; i++)
				cout << z[i];
		}
	} else if (x < 0 && y < 0) {
		if (znak1 == 0) {
			int temp = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (z[i] == 0 && temp == 0) {
					z[i] = 1;
					break;
				} else if (z[i] == 0 && temp == 1) {
					z[i] = 1;
					temp = 0;
					break;
				} else if (z[i] == 1 && temp == 0) {
					z[i] = 0;
					temp = 1;
				} else if (z[i] == 1 && temp == 1) {
					z[i] = 0;
					temp = 1;
				}
			}
			negative(z);
			z[0]=0;
			for (int i = 0; i < n; i++)
				cout << z[i];
		} else {
			negative(z);
			z[0]=0;
			for (int i = 0; i < n; i++)
				cout << z[i];
		}
	}
}
int main() {
	int choice;
	do {
		cout << "\n1:Делене на числа с дясно позиционирана запетая.";
		cout << "\n2:Делене на числа с ляво позиционирана запетая.";
		cout << "\n3:Делене на числа с плаваща запетая.";
		cout << "\n4:Изход.";
		do {
			cin >> choice;
		} while ((choice < 1) || (choice > 4));
		switch (choice) {
		case 1: {
			int a, b, k, l;
			cout << "\nРазрядна мрежа:";
			cin >> n;
			bool arr1[n], arr2[n], arr2neg[n];
			cout << "\nЧисло 1:";
			cin >> a;
			cout << "\nЧисло 2:";
			cin >> b;
			cout << endl << a << " -> ";
			binary(a, arr1);
			for (int i = 0; i < n; i++)
				cout << arr1[i];
			l = N(arr1);
			cout << " -> ";
			corection(arr1);
			for (int i = 0; i < n; i++)
				cout << arr1[i];
			if (a < 0) {
				negative(arr1);
				cout << " -> ";
				for (int i = 0; i < n; i++)
					cout << arr1[i];
			}
			cout << endl << b << " -> ";
			binary(b, arr2);
			for (int i = 0; i < n; i++)
				cout << arr2[i];
			k = N(arr2);
			cout << " -> ";
			corection(arr2);
			for (int i = 0; i < n; i++)
				cout << arr2[i];
			if (b < 0) {
				negative(arr2);
				cout << " -> ";
				for (int i = 0; i < n; i++)
					cout << arr2[i];
			}
			for (int i = 0; i < n; i++)
				arr2neg[i] = arr2[i];
			negative(arr2neg);
			if (b < 0)
				arr2neg[0] = 0;
			else
				arr2neg[0] = 1;
			cout << "\nN=k-l+1  ";
			cout << "  k->" << k;
			cout << "  l->" << l;
			p = k - l + 1;
			cout << "  N=" << p << endl;
			delene(a, b, arr1, arr2, arr2neg);
			break;
		}
		case 2:
			cout << "\nIn Development!";
			break;
		case 3:
			cout << "\nIn Development!";
			break;
		case 4:
			exit(0);
		}
	} while (choice != 4);
}
