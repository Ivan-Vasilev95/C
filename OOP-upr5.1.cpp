#include <iostream>
using namespace std;
class laptop;
class comp {
	float speed;
	int ram;
	int hdd;
public:
	comp() {
		speed = 0;
		ram = 0;
		hdd = 0;
	}
	comp(float x, int y, int z) {
		speed = x;
		ram = y;
		hdd = z;
	}
	comp(const comp &ob) {
		speed = ob.speed;
		ram = ob.ram;
		hdd = ob.ram;
	}
	void set_c(float x, int y, int z) {
		speed = x;
		ram = y;
		hdd = z;
	}
	int get_s() {
		return speed;
	}
	int get_r() {
		return ram;
	}
	int get_h() {
		return hdd;
	}
	void display() {
		cout << "Skorost: " << get_s() << '\n' << "ram: " << get_r() << '\n'
				<< "HDD: " << get_h() << '\n';
	}
	friend bool compare(comp ob, laptop ob1);
};
class laptop: public comp {
	int battery;
	float teglo;
public:
	laptop(float sp, int rr, int disk, int bt, float t) :
			comp(sp, rr, disk) {
		battery = bt;
		teglo = t;
	}
	void set_l(int x, float y) {
		battery = x;
		teglo = y;
	}
	int get_b() {
		return battery;
	}
	int get_t() {
		return teglo;
	}
	void show() {
		display();
		cout << "Battery: " << battery << '\n'
				<< "Teglo: " << teglo;
	}
	friend bool compare(comp ob, laptop ob1);
};
bool compare(comp ob, laptop ob1) {
	if (ob.speed > ob1.speed)
		return 1;
	else
		return 0;
}
int main() {
	comp ob(21.5, 8, 512);
	laptop ob1(20.9, 6, 1000, 10, 30.5);
	if (compare(ob, ob1))
		cout << "Komp e po burz" << endl;
	else
		cout << "laptop e po burz" << endl;
	cout << endl << "Harakteristiki za comp" << endl;
	ob.display();
	cout << endl << "Harakteristiki za laptop" << endl;
	ob1.show();
}
