#include <iostream>
using namespace std;


int    getMin( int**    matrix, int n );
double getMin( double** matrix, int n );
float  getMin( float**  matrix, int n );

int main()
{
	int n = 0;
	do
	{
		cout << "N = ";
		cin >> n;
	}
	while (n <= 0);
	// new
	int** matrix = new int*[n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n];
	
	// cin
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		cin >> matrix[i][j];

	cout << "Min: " << getMin( matrix, n ) << endl;

	// delete
	for (int i = 0; i < n; ++i)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}


int getMin( int** matrix, int n )
{
	int min = matrix[0][0];

	for (int i = 0; i < n - 1; ++i)
	for (int j = i; j < n - 1; ++j)
	if (matrix[i][j] < min)
		min = matrix[i][j];
	return min;
}

double getMin( double** matrix, int n )
{
	double min = matrix[0][0];

	for (int i = 0; i < n - 1; ++i)
	for (int j = i; j < n - 1; ++j)
	if (matrix[i][j] < min)
		min = matrix[i][j];
	return min;
}

float getMin( float** matrix, int n )
{
	float min = matrix[0][0];

	for (int i = 0; i < n - 1; ++i)
	for (int j = i; j < n - 1; ++j)
	if (matrix[i][j] < min)
		min = matrix[i][j];
	return min;
}
