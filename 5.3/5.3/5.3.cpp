#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double gp, gk, z;
	int n;
	cout << "gp = "; cin >> gp;
	cout << "gk = "; cin >> gk;
	cout << "n = "; cin >> n;
	double dg = (gk - gp) / n;
	cout << dg<<endl;
	double q = gp;
	while (q <= gk)
	{
		z = h(q+1)+h((q*q)+1)+pow(h(q*q),2);
		cout << q << " " << z << endl;
		q += dg;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1)
		return ((cos(x)+1)/((cos(x)*cos(x))+1));
	else
	{
		double S = 0;
		int i = 0, fac =1,n=1;
		double a = 1/cos(x);
		S = 0;

		do
		{
			for (n = 1; n <= (2*i);n++) {
				fac *= n;
			}
			i++;
			 S += (pow(x,2*i)/fac);
		} while (i < 6);
		return S;

	
	}
}