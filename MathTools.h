#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

double ConvertToDegrees(double x);

double ConvertToRadians(double x);

//MATRIX STUFF
bool GetSize(vector<double> a, vector<double> b);

double Dot(vector<double> a, vector<double> b);

vector<double> Cross(vector<double> a, vector<double> b);

ostream& operator<< (ostream& os, vector<double> vec);

vector<double> operator+ (vector<double> a, vector<double> b);

vector<double> operator* (vector<double> a, vector<double> b);

double Magnitude(vector<double> vec);

vector<double> GetNormalize(vector<double> vec);

void Normalize(vector<double>& vec);

vector<double> Proj(vector<double> projectee, vector<double> projector);

double GetAngle(vector<double> a, vector<double> b, bool isRadians);

void RotateX(vector<double>& a, double theta, bool isRadians);

void RotateY(vector<double>& a, double theta, bool isRadians);

void RotateZ(vector<double>& a, double theta, bool isRadians);

//MATRIX STUFF
class Matrix
{
public:
	/*Constructs 2D matrix*/
	Matrix(int rows, int columns);
	void Insert(int row, int column, double val);
	void Fill(vector<double> vec);
	int GetNumRows() { return rows; }
	int GetNumColumns() { return columns; }
	double GetValue(int row, int column);
	vector<double> GetMatrix() { return matrix; }
	Matrix GetCofactor();
	double GetDerminant();

private:
	int rows, columns;
	vector<double> matrix;
	vector<double> cofactor;

};

void PrintMatrix(Matrix a);