#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
class Lab4 {
private:
	int n;
	double **matrix;
public:
	Lab4(int count) {
		n = count;
		matrix = new double*[n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new double[n];
			for (int j = 0; j < n; j++) {
				matrix[i][j] = rand() % 10;
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Solution(){
		
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
	
	friend ostream& operator<<(ostream &out, const Lab4 &lab4);
};
ostream& operator<<(ostream &out, const Lab4 &lab4) {
	out << "transponovana matrix: " << endl;
	for (int i = 0; i < lab4.n; i++)
	{
		for (int j = 0; j < lab4.n; j++)
		{
			out << lab4.matrix[j][i] << " ";

		}
		out << endl;
	}
	return out;
}
int main()
{
	int n;
	cout << "Enter dimension of array: " << endl;
	cin >> n;
	srand(time(NULL));
	Lab4 lab(n);
	cout << lab;

}
