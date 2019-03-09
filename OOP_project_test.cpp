#include<iostream>
#include <chrono>
#include<vector>
using namespace std;
int random_generator(int x) {
	int random_number;
	srand(time(0));
	random_number = (rand() % x) + 1;
	return random_number;
}
class flight {
	int flight_number;
	int arrival_time;
	int weight;
	int x;
	int y;
public:
	int fuel;
	int departure_time;
	int landing_time;
	static int f;
	static int time_unit;
	flight() {
		x = 0;
		y = 0;
		weight = random_generator(10);
		flight_number = ++f;
		fuel = random_generator(25);
		arrival_time = landing_time = departure_time = time_unit;
	}
	flight(const flight &ob) {
		x = ob.x;
		y = ob.y;
		weight = ob.weight;
		flight_number = ob.flight_number;
		fuel = ob.fuel;
		arrival_time = ob.arrival_time;
		landing_time = ob.landing_time;
		departure_time = ob.departure_time;
	}
	void set_x(int coordinates){
		x=coordinates;
	}
	int get_x(){
		return x;
	}
	void set_y(int coordinates){
		 y=coordinates;
	}
	int get_y(){
		return y;
	}
	void set_flight_number(int x) {
		flight_number = x;
	}
	int get_flight_number() {
		return flight_number;
	}
	void set_weight(int x) {
		weight = x;
	}
	int get_weight() {
		return weight;
	}
	void set_fuel(int x) {
		fuel = x;
	}
	int get_fuel() {
		return fuel;
	}
	void set_arrival_time(int x) {
		arrival_time = x;
	}
	int get_arrival_time() {
		return arrival_time;
	}
	void set_landing_time(int x) {
		landing_time = x;
	}
	int get_landing_time() {
		return landing_time;
	}
	void set_departure_time(int x) {
		departure_time = x;
	}
	int get_departure_time() {
		return departure_time;
	}
	void get_fno() {
		cout << "Flight number: " << flight_number << " ";
	}
	void coordinates_mil() {
		x = random_generator(20);
		y = random_generator(12);
		cout << "\nAirport coordinates: " << "X: " << x << " " << "Y: " << y
				<< endl;
	}
	void coordinates_civ() {
		x = random_generator(13);
		y = random_generator(9);
		cout << "\nAirport coordinates: " << "X: " << x << " " << "Y: " << y
				<< endl;
	}

};
int flight::time_unit = 1;
int flight::f = 0;
class airport: public flight {
	vector<flight> landing_queue, departure_queue;
	int crash;
	int land;
	int take_off;
	double time_between_arrival_landing;
	double time_between_landing_departure;
	bool runway;
public:
	int count = 0;
	airport() {
		landing_queue.reserve(1000), departure_queue.reserve(1000);
		crash = 0;
		land = 0;
		take_off = 0;
		time_between_arrival_landing = 0;
		time_between_landing_departure = 0;
		runway = 0;
		int d = random_generator(10);
		for (int i = 0; i < d; ++i)
			departure_queue.emplace_back();
	}
	airport(const airport &ob) {
		crash = ob.crash;
		land = ob.land;
		take_off = ob.take_off;
		time_between_arrival_landing = ob.time_between_arrival_landing;
		time_between_landing_departure = ob.time_between_landing_departure;
		runway = ob.runway;
	}
	void set_crash(int x) {
		crash = x;
	}
	int get_crash() {
		return crash;
	}
	void set_land(int x) {
		land = x;
	}
	int get_land() {
		return land;
	}
	void set_take_off(int x) {
		take_off = x;
	}
	int get_take_off() {
		return take_off;
	}
	void set_tbal(double x) {
		time_between_arrival_landing = x;
	}
	double get_tbal() {
		return time_between_arrival_landing;
	}
	void set_tbld(double x) {
		time_between_landing_departure = x;
	}
	double get_tbld() {
		return time_between_landing_departure;
	}
	void set_runway(bool x) {
		runway = x;
	}
	bool get_runway() {
		return runway;
	}
	void generate_queue() {
		int l = random_generator(10);
		for (int i = 0; i < l; ++i)
			landing_queue.emplace_back();
	}
	void check_free_space() {
		cout << "Taken spots: " << count;
	}
	void check_low_fuel() {
		int c = 0;
		auto i = landing_queue.begin();
		for (int j = 0; j < landing_queue.size(); j++) {
			i = landing_queue.begin() + j;
			if (i->get_fuel() == 0) {
				++c;
				i->get_fno();
				cout << "has crashed\n";
				landing_queue.erase(i);
			} else if (i->get_fuel() == 1) {
				landing_queue.emplace(landing_queue.begin(), *i);
				landing_queue.erase(i);
			}
		}
		crash += c;
		cout << "No of crashes = " << c << "\n";
	}
	void landing_or_departure() {
		if (count < 4) {
			for (int i = 0; i < landing_queue.size() && i < 1; i++) {
				landing_queue.front().get_fno();
				landing_queue.front().landing_time = time_unit;
				time_between_arrival_landing +=
						landing_queue.front().get_landing_time()
								- landing_queue.front().get_arrival_time();
				cout << "has landed\n";
				departure_queue.emplace_back(landing_queue.front());
				landing_queue.erase(landing_queue.begin());
				++land;
				count++;
			}
		} else {
			for (int i = 0; i < landing_queue.size() && i < 1; i++) {
				departure_queue.front().get_fno();
				departure_queue.front().departure_time = time_unit;
				time_between_landing_departure +=
						departure_queue.front().get_departure_time()
								- departure_queue.front().get_landing_time();
				cout << "has taken off\n";
				departure_queue.erase(departure_queue.begin());
				++take_off;
				count--;
			}
		}
	}
	void fuel_reduction_mil() {
		for (int i = 0; i < landing_queue.size(); i++)
			--landing_queue.at(i).fuel;
	}
	void fuel_reduction_civ() {
		for (int i = 0; i < get_weight(); i++) {
			for (int i = 0; i < landing_queue.size(); i++)
				--landing_queue.at(i).fuel;
		}
	}
	void end_of_simulation() {
		landing_queue.shrink_to_fit(), departure_queue.shrink_to_fit();
		double avg1 = time_between_arrival_landing / land, avg2 =
				time_between_landing_departure / take_off;
		int choice;
		string ch;
		cout << "\n\nDo you wish to check for reference (Y/N)";
		cin >> ch;
		if (ch == "Y" || ch == "y") {

			do {
				cout << "\n\nFor average time between arrival & landing pres:1"
						<< endl;
				cout << "For average time between landing & take off pres:2 "
						<< endl;
				cout << "For successful landings pres:3 " << endl;
				cout << "For succesful departures pres:4" << endl;
				cout << "For total crashes pres:5" << endl;
				cout << "To close the the program pres:6";
				cout << '\n';
				do {
					cin >> choice;
				} while ((choice < 1) || (choice > 6));
				switch (choice) {
				case 1:
					cout << "\n\nAverage time between arrival & landing is = "
							<< avg1;
					break;
				case 2:
					cout << "\n\nAverage time between landing & take_off is = "
							<< avg2;
					break;
				case 3:
					cout << "\n\nTotal successful landings = " << land;
					break;
				case 4:
					cout << "\n\nTotal succesful departures = " << take_off;
					break;
				case 5:
					cout << "\n\nTotal crashes = " << crash;
					break;
				case 6:
					exit(0);
				}
			} while (choice != 6);

		} else
			cout << "End of program!";
	}
};
class output: public airport {
	airport r;
public:
	void print() {
		cout << "\t\tAIRPORT SIMULATION\n\n";
		for (flight::time_unit = 1; flight::time_unit <= 10;
				flight::time_unit++) {
			cout << "\n\nTime Unit: " << flight::time_unit << "\n\n";
			cout << "\nMilitary airport\n";
			r.coordinates_mil();
			r.generate_queue();
			r.check_low_fuel();
			r.landing_or_departure();
			r.fuel_reduction_mil();
			r.check_free_space();
			cout << '\n';
			cout << "\nCivil airport\n";
			r.coordinates_civ();
			r.generate_queue();
			r.check_low_fuel();
			r.landing_or_departure();
			r.fuel_reduction_civ();
			r.check_free_space();

		}
		r.end_of_simulation();
	}
};
int main() {
	output obj;
	obj.print();
}
