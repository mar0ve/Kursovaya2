#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define pointsCount 1000

using namespace std;

//������� ������� ������������ � ����������� �������� ����� � ������
void get_max_min_value(double voltage[], double& max, double& min, int pCount);

//������� ���������� ������������ �������� ������� ����� � ������
double get_impulse_duration(double voltage[], double max, double min, int pCount, double stepTime);

//������� ���������� ������������ ��������� ������ ������� ����� � ������
double get_front_duration(double voltage[], double max, double min, double duration, int pCount, double stepTime);

//������� ������������ ������� �������
void set_time_array(int pCount, double* timeArr, double& stepTime);

//������� ������������ ������� U �����
void get_voltage_in(double* vol_in, double timeArr[], int pCount);

//������� ������������ ������� U �����
void get_voltage_out(double* vol_out, double vol_in[], double timeArr[], int pCount);

//������� ����������� ����������� ����������
void show_results(double timeArr[], double Uvx[], double Uvux[], int pCount);

//������� ��������� ������ �� ����� general_information.txt
void load_file_information();

//������� ���������� ������ � 3 �����
void save_file_information(const char* filename, double solutData[], int pCount);