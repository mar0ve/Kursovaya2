#include "calculate_functions.h"

int main(int argc, char* argv[]) {

	double timeArr[pointsCount], Uvx[pointsCount], Uvux[pointsCount];
	int pCount = 0;
	double stepTime = 0;
	cout << "Enter points count for calculating : ";
	cin >> pCount;

	set_time_array(pCount, timeArr, stepTime);
	get_voltage_in(Uvx, timeArr, pCount);
	get_voltage_out(Uvux, Uvx, timeArr, pCount);
	show_results(timeArr, Uvx, Uvux, pCount);

	double max, min;

	get_max_min_value(Uvx, max, min, pCount);
	double duration = get_impulse_duration(Uvx, max, min, pCount, stepTime);
	double durationTime = get_front_duration(Uvx, max, min, duration, pCount, stepTime);
	cout << duration << endl;
	cout << durationTime << endl;

	get_max_min_value(Uvux, max, min, pCount);
	double durationu = get_impulse_duration(Uvux, max, min, pCount, stepTime);
	double durationTimeu = get_front_duration(Uvux, max, min, durationu, pCount, stepTime);
	cout << durationu << endl;
	cout << durationTimeu << endl;

	save_file_information("timeArr.txt", timeArr, pCount);
	save_file_information("voltageIn.txt", Uvx, pCount);
	save_file_information("voltageOut.txt", Uvux, pCount);

	return 0;
}