#include "calculate_functions.h"

double time_max_duration(double voltage[], int pCount, double timeArr[]) {

	double max = voltage[0];
	double min = 0;
	
	for (int i = 0; i < pCount; i++) {
		if (voltage[i] > max)
			max = voltage[i];
		else
			min = voltage[i];
	}

	double duration = 0;
	
	double startTime = 10, finishTime = 100;
	double stepTime = (finishTime - startTime) / (pCount - 1);
	double U1 = min + 0.9 * (max - min);
	double U2 = min + 0.1 * (max - min);
	
	for (int i = 0; i < pCount; i++)
		if (voltage[i] < U1 && voltage[i] > U2 && voltage[i + 1] > voltage[i])
			duration += stepTime;
	
	return duration;
}

void set_time_array(int pCount, double* timeArr, double& stepTime)
{
	double startTime = 10, finishTime = 100;
	stepTime = (finishTime - startTime) / (pCount - 1);
	for (int i = 0; i < pCount; i++) {
		timeArr[i] = startTime + i * stepTime;
	}

}

void get_voltage_in(double* vol_in, double timeArr[], int pCount) {

	double startTime = 10;
	double finishTime = 100;
	double midTime = 80;
	double a = 1.42857, b = -14.2857, c = -5, d = 500;

	for (int i = 0; i < pCount; i++) {
		if (timeArr[i] < midTime) {
			if (i == 0) vol_in[i] = 0;
			else
				vol_in[i] = a * timeArr[i] + b;
		}
		else
			vol_in[i] = c * timeArr[i] + d;
	}
}


void get_voltage_out(double* vol_out, double vol_in[], int pCount) {

	double U1 = 5, U2 = 20, U3 = 100;
	for (int i = 0; i < pCount; i++) {
		if (vol_in[i] <= U1) {
			vol_out[i] = 0;
		}
		else if (vol_in[i] > U1 && vol_in[i] < U2) {
			vol_out[i] = (U3 * pow((vol_in[i] - U1), 2)) / (pow(U2 - U1, 2));
		}
		else if (vol_in[i] >= U2) {
			vol_out[i] = U3;
		}
	}
}

void show_results(double timeArr[], double Uvx[], double Uvux[], int pCount) {

	cout << "#" << '\t' << "Time" << '\t' << "Uvx" << '\t' << "Uvux" << endl;

	cout.precision(4);
	for (int i = 0; i < pCount; i++) {
		cout << i + 1 << '\t' << timeArr[i] << '\t' << Uvx[i] << '\t' << Uvux[i] << endl;
	}
	cout << endl;
}

void load_file_information() {

	ifstream iFile("general_information.txt");
	if (!iFile) {
		cout << "cannot open file." << endl;
	}

	string buffer;

	while (getline(iFile, buffer)) {
		cout << buffer << endl;
	}

	iFile.close();
}

void save_file_information(const char* filename, double solutData[], int pCount) {

	ofstream oFile(filename);
	if (!oFile) {
		cout << "cannot open file." << endl;
	}

	for (int i = 0; i < pCount; i++) {
		oFile << solutData[i] << endl;
	}

	oFile.close();
}