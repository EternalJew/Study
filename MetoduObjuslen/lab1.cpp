#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	float a[11][11], b[11], x[11], t;
	int n;
	n = 3;

	a[1][1] = 5.7; a[1][2] = 3.3; a[1][3] = 1.3; b[1] = 2.1;
	a[2][1] = 3.5; a[2][2] = 4.7; a[2][3] = 2.1; b[2] = 1.7;
	a[3][1] = 4.1; a[3][2] = 5.8; a[3][3] = -11.7; b[3] = 0.8;

	cout << "\n\n";

	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << "  ";
		cout << b[i] << "\n";
	}
	cout << endl;

	double eps = .000001;
	double max;
	int max_i;
	double lead, a_div_lead;

	for (int k = 1; k <= n; k++)
	{
		max = 0;
		max_i = -1;

		for (int i = k; i <= n; i++)
		{
			if (fabs(a[i][k]) > max)
			{
				max = fabs(a[i][k]);
				max_i = i;
			}
		}

		if (max_i == -1 || fabs(a[max_i][k]) < eps)
		{
			cout << "\n\n" << "Error: det=0" << "\n\n";
			break;
		}

		lead = a[k][k];

		for (int j = k; j <= n; j++)
			a[k][j] /= lead;

		b[k] /= lead;

		for (int i = 1; i <= n; i++)
		{
			a_div_lead = a[i][k] / a[k][k];
			if (i != k)
			{
				for (int j = k; j <= n; j++)
					a[i][j] -= a[k][j] * a_div_lead;
				b[i] -= b[k] * a_div_lead;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
						cout << a[i][j] << "  ";
					cout << b[i] << "\n";
				}
				cout << endl;
			}

		}
	}

	a[1][1] = 5.7; a[1][2] = 3.3; a[1][3] = 1.3;
	a[2][1] = 3.5; a[2][2] = 4.7; a[2][3] = 2.1;
	a[3][1] = 4.1; a[3][2] = 5.8; a[3][3] = -11.7;

	for (int i = 1; i <= n; i++) {
		float sum = 0;

		for (int j = 1; j <= n; j++)
			sum += a[i][j] * b[j];

		cout << sum << endl;
		cout << "--------------" << endl;
	*/





	int d, s;
	cout << "Direct course" << endl;
	for (int k = 1; k <= n; k++) // прямий хід
	{
		for (int j = k + 1; j <= n; j++)
		{
			d = a[j][k] / a[k][k]; // формула (1)
			for (int i = k; i <= n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
				//cout << "x[" << j << "]=" << b[j] << " " << endl;
			}
			b[j] = b[j] - d * b[k]; // формула (3)
			cout << "x[" << j << "]=" << b[j] << " " << endl;

		}

	}
	cout << "REverse" << endl;

	for (int k = n; k >= 1; k--) //обернений хід
	{
		d = 0;
		for (int j = k + 1; j <= n; j++)
		{
			s = a[k][j] * x[j]; // формула (4)
			d = d + s; // формула (4
		}
		x[k] = (b[k] - d) / a[k][k]; // формула (4)
		cout << "x[" << k << "]=" << x[k] << " " << endl;

	}

	cout << "System roots: " << endl;
	for (int i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << x[i] << " " << endl;
	_getch();
}
