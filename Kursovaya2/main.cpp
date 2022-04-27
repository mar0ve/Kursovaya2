#include "calculate_functions.h"

int main(int argc, char* argv[]) {

	double timeArr[pointsCount], Uvx[pointsCount], Uvux[pointsCount];
	int pCount = 0;
	double stepTime = 0;

	load_file_information();

	int choose;
	while (true) {
		cout << "1 - tab 2 - parametr 3 - write file 4 - exit" << endl;
		cin >> choose;
		switch (choose) {

		case 1:
			cout << "Enter points count for calculating : ";
			cin >> pCount;

			set_time_array(pCount, timeArr, stepTime);
			get_voltage_in(Uvx, timeArr, pCount);
			get_voltage_out(Uvux, Uvx, pCount);
			show_results(timeArr, Uvx, Uvux, pCount);
			break;
		case 2: 
			cout << "Enter points count for calculating : ";
			cin >> pCount;

			set_time_array(pCount, timeArr, stepTime);
			get_voltage_in(Uvx, timeArr, pCount);
			get_voltage_out(Uvux, Uvx, pCount);

			cout << "max duration Uvx : " << time_max_duration(Uvx, pCount, timeArr) << endl;
			cout << "max duration Uvux : " << time_max_duration(Uvux, pCount, timeArr) << endl;
			break;
		case 3:
			cout << "Enter points count for calculating : ";
			cin >> pCount;

			set_time_array(pCount, timeArr, stepTime);
			get_voltage_in(Uvx, timeArr, pCount);
			get_voltage_out(Uvux, Uvx, pCount);

			save_file_information("timeArr.txt", timeArr, pCount);
			save_file_information("voltageIn.txt", Uvx, pCount);
			save_file_information("voltageOut.txt", Uvux, pCount);
			break;
		case 4:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}