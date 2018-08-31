#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i <=N; i++)
	{
		printf("%.f ", pow(2, i));
	}
}