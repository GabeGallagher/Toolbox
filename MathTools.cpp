/*Author Gabriel B. Gallagher December 25, 2017

Custom helper script which extends the C++ math library and will contain several mathematical functions
that I find useful. Similar libraries to this almost certainly exist, but this one is mine, and it should
help me solidify some fundamental 3D calculus concepts and also be useful later since all of these
functions are used constantly in 3D game programming.*/

#include "MathTools.h"

//VECTOR STUFF

/*Converts from radians to degrees*/
double ConvertToDegrees(double x)
{
	return (x * 180) / M_PI;
}

/*Converts from radians to degrees*/
double ConvertToRadians(double x)
{
	return (x * M_PI) / 180;
}

/*Returns true if the vectors are both 2D or both 3D*/
bool GetSize(vector<double> a, vector<double> b)
{
	if (a.size() == 2 && b.size() == 2) { return false; }
	else if (a.size() == 3 && b.size() == 3) { return true; }
	throw runtime_error("One or more vectors outside of designated range\n");
}

/*Computes the Dot product between 2D or 3D. May expand to include 4D in the event
that it becomes imperitive for standard game programming and graphics usage.*/
double Dot(vector<double> a, vector<double> b)
{
	bool isThreeD = GetSize(a, b);
	
	if (isThreeD) //vector length three
	{
		double x = a.at(0) * b.at(0);
		double y = a.at(1) * b.at(1);
		double z = a.at(2) * b.at(2);
		return x + y + z;
	}
	else
	{
		double x = a.at(0) * b.at(0);
		double y = a.at(1) * b.at(1);
		return x + y;
	}
}

/*Computes the cross product between 3D vectors*/
vector<double> Cross(vector<double> a, vector<double> b)
{
	bool isThreeD = GetSize(a, b);

	if (isThreeD)
	{
		return { (a.at(1) * b.at(2)) - (a.at(2) * b.at(1)),
				(a.at(0) * b.at(2)) - (a.at(2) * b.at(0)),
				(a.at(0) * b.at(1)) - (a.at(1) * b.at(0)) };
	}
	else //If not three dimensional, throw error
	{
		throw runtime_error("Cannot compute cross product of non 3D vectors\n");
	}
}

/*Output for vectors of any size*/
ostream& operator<<(ostream& os, vector<double> vec)
{
	cout << "(";

	for (int i = 0; i < vec.size(); ++i)
	{
		if(i == vec.size() - 1)
		{
			cout << vec.at(i);
			cout << ")";
		}
		else
		{
			cout << vec.at(i);
			cout << ", ";
		}
	}
	return os;
}

/*Add two vectors*/
vector<double> operator+ (vector<double> a, vector<double> b)
{
	if (a.size() != b.size())
	{
		throw runtime_error("Cannot add vectors of differing sizes\n");
	}
	else
	{
		vector<double> c;
		for (int i = 0; i < a.size(); ++i)
		{
			c.push_back(a.at(i) + b.at(i));
		}
		return c;
	}
}

/*Multiply two vectors*/
vector<double> operator* (vector<double> a, vector<double> b)
{
	if (a.size() != b.size())
	{
		throw runtime_error("Cannot multiply vectors of differing sizes\n");
	}
	else
	{
		vector<double> c;
		for (int i = 0; i < a.size(); ++i)
		{
			c.push_back(a.at(i) * b.at(i));
		}
		return c;
	}
}

/*Return length of passed vector*/
double Magnitude(vector<double> vec)
{
	return sqrt(pow(vec.at(0), 2) + pow(vec.at(1), 2) + pow(vec.at(2), 2));
}

/*Return normal of passed vector*/
vector<double> GetNormalize(vector<double> vec)
{
	vector<double> normalVec;

	for (int i = 0; i < vec.size(); ++i)
	{
		normalVec.push_back(pow(Magnitude(vec), -1) * vec.at(i));
	}
	return normalVec;
}

/*Normalize passed vector. WARNING: This changes passed vector*/
void Normalize(vector<double>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		vec.at(i) *= pow(Magnitude(vec), -1);
	}
}

/*Project projector onto projectee*/
vector<double> Proj(vector<double> projectee, vector<double> projector)
{
	vector<double> proj = projectee;

	double modifier = Dot(projectee, projector) / pow(Magnitude(projectee), 2);

	for (int i = 0; i < proj.size(); ++i)
	{
		proj.at(i) *= modifier;
	}
	return proj;
}

/*Get the angle between two vectors. User can input whether to return the value in radians or degrees*/
double GetAngle(vector<double> a, vector<double> b, bool isRadians)
{
	double cosTheta = Dot(a, b) / (Magnitude(a) * Magnitude(b));

	if (isRadians) //returns angle in radians
	{
		return acos(cosTheta);
	}
	else //returns angle in degrees
	{
		return ConvertToDegrees(acos(cosTheta));
	}
}

/*Rotate vector a about X axis. Not available for 2D vectors*/
void RotateX(vector<double>& a, double theta, bool isRadians)
{
	if (a.size() != 3) { throw runtime_error("Vector must be of size 3"); }

	if (!isRadians) { ConvertToRadians(theta); }

	double y = a.at(1), z = a.at(2);

	a.at(1) = y * cos(theta) - z * sin(theta);
	a.at(2) = y * sin(theta) + z * cos(theta);
}

/*Rotate vector a about Y axis. Not available for 2D vectors*/
void RotateY(vector<double>& a, double theta, bool isRadians)
{
	if (a.size() != 3) { throw runtime_error("Vector must be of size 3"); }

	if (!isRadians) { ConvertToRadians(theta); }

	double x = a.at(0), z = a.at(2);

	a.at(0) = x * cos(theta) + z * sin(theta);
	a.at(2) = -1 * x * sin(theta) + z * cos(theta);
}

/*Rotate vector a about Y axis. Serves as basic rotation for 2D vectors*/
void RotateZ(vector<double>& a, double theta, bool isRadians)
{
	if (!isRadians) { theta = ConvertToRadians(theta); }

	double x = a.at(0), y = a.at(1);

	a.at(0) = x * cos(theta) - y * sin(theta);
	a.at(1) = x * sin(theta) + y * cos(theta);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//MATRIX STUFF////MATRIX STUFF////MATRIX STUFF////MATRIX STUFF////MATRIX STUFF////MATRIX STUFF////
//////////////////////////////////////////////////////////////////////////////////////////////////
Matrix::Matrix(int rows, int columns)
	:rows{ rows }, columns{ columns }
{
	//initialize with base values of 0
	for (int i = 0; i < rows * columns; ++i)
	{
		matrix.push_back(0);
	}
}

/*Insert values into the matrix*/
void Matrix::Insert(int row, int column, double val)
{
	matrix.at(row + column * columns) = val;
}

/*Allows user to pass an array to fill the matrix rather than pass values one-by-one.
If array is larger than matrix, the function will still work, but the extra numbers
won't get passed. If the array is smaller, the matrix will fill the difference in cells
with 0's. It is recommended that you pass the proper number of numbers, even though the
method will function regardless*/
void Matrix::Fill(vector<double> vec)
{
	if (vec.size() > matrix.size())
	{
		cout << "Passed array is larger than matrix. Matrix will exlude some digits"
			 << " from array\n";
	}
	for (int i = 0; i < rows * columns; ++i)
	{
		matrix.at(i) = vec.at(i);
	}
}

double Matrix::GetValue(int row, int column)
{
	if (row < rows && column < columns)
	{
		return matrix.at(row * columns + column);
	}
	throw runtime_error("cannot acces value outside bounds of matrix\n");
}

/*Private method that returns cofactor of matrix*/
Matrix Matrix::GetCofactor()
{
	for (int i = 1; i < rows; ++i)
	{
		for (int j = 1; j < columns; ++j)
		{
			cofactor.push_back(matrix.at(i * columns + j));
		}
	}
	Matrix cf{ (rows - 1), (columns - 1) };
	cf.Fill(cofactor);
	return cf;
}

double Matrix::GetDerminant()
{
	double determinant;


	return 0.0;
}

void PrintMatrix(Matrix a)
{
	for (int i = 0; i < a.GetNumRows(); ++i)
	{
		for (int j = 0; j < a.GetNumColumns(); ++j)
		{
			cout << a.GetValue(i, j) << "\t";

			if ((j + 1) % a.GetNumRows() == 0) { cout << "\n"; }
		}
	}
}
