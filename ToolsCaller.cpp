#include "MathTools.h"

using namespace std;

int main()
{
	vector<double> a = { 0, 1, 0 };
	vector<double> b = { -1, 0, 0 };

	cout << "a dot b = " << Dot(a, b) << "\n";

	/*cout << "Generating Matrix.." << "\n";
	Matrix matrix{ 3, 3 };

	PrintMatrix(matrix);

	cout << "Value at 3, 3: " << matrix.GetValue(2, 2) << "\n";

	matrix.Fill({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });

	PrintMatrix(matrix);

	cout << "\n";
		
	PrintMatrix(matrix.GetCofactor());*/

	system("pause");
	return 0;
}