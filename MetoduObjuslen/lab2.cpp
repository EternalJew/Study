const int N = 3;
double a[N][N] = { {5.7, 3.3, 1.3},
	   {3.5, 4.7, 2.1},
	   {4.1, 5.8, -11.7} };

double b[N] = { 2.1, 1.7, 0.8 };
double l[N][N], u[N][N];
double y[N], x[N];
double Finish[N][N];
int s, i, j, n = N;
double sum;

// виконуємо заміну(прирівнюємо до 0 щоб вивести матриці)
for (i = 0; i < N; i++)
{
	for (j = 0; j < N; j++)
	{
		l[i][j] = 0;
		u[i][j] = 0;
	}
	y[i] = 0;
	x[i] = 0;
	u[i][i] = 1;
}

// обрахунок L і U 
for (i = 0; i < n; i++)
{
	for (j = 0; j < n; j++)
	{
		sum = 0;
		if (i >= j)
		{
			for (s = 0; s <= j - 1; s++)// нижній
				sum += (l[i][s]) * (u[s][j]);
			l[i][j] = a[i][j] - sum;
		}
		else
		{
			for (s = 0; s <= i - 1; s++)
				sum += l[i][s] * u[s][j];//верхній
			u[i][j] = (a[i][j] - sum) / l[i][i];
		}
	}
}
// обрахунок фінальної відповіді

y[0] = b[0] / l[0][0];
for (i = 1; i < n; i++)
{
	sum = 0;
	for (j = 0; j < i; j++)
		sum += l[i][j] * y[j];
	y[i] = (b[i] - sum) / l[i][i];
}


x[n - 1] = y[n - 1];


for (i = n - 2; i >= 0; i--)
{
	sum = 0;
	for (j = n - 1; j >= i + 1; j--)
		sum += x[j] * u[i][j];
	x[i] = y[i] - sum;
}


cout << "\n\n";
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		cout << "  " << l[i][j] << "   ";
	cout << "\n\n";
}

cout << "\n\n";

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		cout << "  " << u[i][j] << "   ";
	cout << "\n\n";
}

for (i = 0; i < n; i++)
	cout << x[i] << " " << endl;

//================================================//
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++) {
		Finish[i][j] = 0;
		for(int k = 0; k <n;k++)
		Finish[i][j] += l[i][k] * u[k][j];
	}
}
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		cout << "  " << Finish[i][j] << "   ";
	cout << "\n\n";
}

return 0;
}
