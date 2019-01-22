#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>

using namespace std;

stack<int> stk;
int arr[100002];
int main() {
	
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	//char *ans = new char[N*2+1];
	vector<char> ans;
	int ans_idx = 0;
	int num = 1;
	int chk_idx = 0;
	for (int i = 0; i < N;i++ ) {		
		while (num <= arr[i])
		{
			stk.push(num++);
			//ans[ans_idx++] = '+';
			ans.push_back('+');
			//printf("+\n");
		}	
		if(stk.top() == arr[i]) {		
			//ans[ans_idx++] = '-';
			ans.push_back('-');
			stk.pop();			
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
/*	for (int i = 0; i < ans_idx; i++) {
		printf("%c\n", ans[i]);
	}*/
	int ans_size = ans.size();
	for (int i = 0; i < ans_size; i++) {
		printf("%c\n", ans[i]);
	}
	return 0;
}