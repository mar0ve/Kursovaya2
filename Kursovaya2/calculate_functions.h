#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define pointsCount 1000

using namespace std;

//������� ���������� ������������ ��������� ������ ������� ����� � ������
double time_max_duration(double voltage[], int pCount, double timeArr[]);

//������� ������������ ������� �������
void set_time_array(int pCount, double* timeArr, double& stepTime);

//������� ������������ ������� U �����
void get_voltage_in(double* vol_in, double timeArr[], int pCount);

//������� ������������ ������� U �����
void get_voltage_out(double* vol_out, double vol_in[], int pCount);

//������� ����������� ����������� ����������
void show_results(double timeArr[], double Uvx[], double Uvux[], int pCount);

//������� ��������� ������ �� ����� general_information.txt
void load_file_information();

//������� ���������� ������ � 3 �����
void save_file_information(const char* filename, double solutData[], int pCount);