#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;
		int A = P*W;
		int B = 0;
		if (R >= W)
		{
			B = Q;
		}
		else {
			B = Q + (W - R)*S;
		}
		cout << "#" << t + 1 << ' ' << min(A, B) << endl;
	}
}