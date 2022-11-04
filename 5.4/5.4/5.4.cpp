#include <iostream>
#include <cmath>
// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int i = K; i <= N; i++)
		s += (1 / i + sqrt(1 + pow(sin(K), 2)));
	return s;
}
double S1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return (1 / i + sqrt(1 + pow(sin(K), 2))) + S1(K, N, i + 1);
}
double S2(const int K, const int N, const int i)
{
	if (i < K)
		return 0;
	else
		return (1 / i + sqrt(1 + pow(sin(K), 2))) + S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t + (1 / i + sqrt(1 + pow(sin(K), 2)));
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + (1 / i + sqrt(1 + pow(sin(K), 2)));
	if (i <= K)
		return t;
	else
		return S4(K, N, i - 1, t);
}

int main()
{
	int i, N;
	i = 1;

	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(i, N) << endl;
	cout << "(rec up ++) S1 = " << S1(i, N, i) << endl;
	cout << "(rec up --) S2 = " << S2(i, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(i, N, i, 0) << endl;
	cout << "(rec down --) S4 = " << S4(i, N, N, 0) << endl;
	return 0;
}


//(1 / i + sqrt(1 + pow(sin(K), 2)))