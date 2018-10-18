#include <iostream>

using namespace std;

int func(int N, int M)
{
	if (M == 0)
	{
		return 1;
	}
	return N* func(N, M - 1);
}
int main()
{
	for (int t = 0; t < 10; t++)
	{
		int temp;
		cin >> temp;

		int N, M;
		cin >> N>> M;

		cout<<"#"<<t+1<<' ' <<func(N, M)<<endl;
	}
}