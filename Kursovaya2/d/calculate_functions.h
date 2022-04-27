#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define pointsCount 1000

using namespace std;

//функция расчета максимальных и минимальных значений входа и выхода
void get_max_min_value(double voltage[], double& max, double& min, int pCount);

//функция нахождения длительности импульса сигнала входа и выхода
double get_impulse_duration(double voltage[], double max, double min, int pCount, double stepTime);

//функция нахождения длительности переднего фронта сигнала входа и выхода
double get_front_duration(double voltage[], double max, double min, double duration, int pCount, double stepTime);

//функция формирования массива времени
void set_time_array(int pCount, double* timeArr, double& stepTime);

//функция формирования массива U входа
void get_voltage_in(double* vol_in, double timeArr[], int pCount);

//функция формирования массива U входа
void get_voltage_out(double* vol_out, double vol_in[], double timeArr[], int pCount);

//функция отображения результатов вычислений
void show_results(double timeArr[], double Uvx[], double Uvux[], int pCount);

//функция получения данных из файла general_information.txt
void load_file_information();

//функция сохранения данных в 3 файла
void save_file_information(const char* filename, double solutData[], int pCount);