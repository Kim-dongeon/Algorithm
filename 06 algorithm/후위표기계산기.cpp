#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
using namespace std;
int isp[4] = { -1,2,1,0 };
int icp[4] = { -1,2,1,3 };

int getToken(char ch) {
	if (ch == ')') {
		return 0;
	}
	else if (ch == '*' || ch == '/') {
		return 1;
	}
	else if (ch == '+' || ch == '-') {
		return 2;
	}
	else {
		return 3;
	}
}
int main() {


	for (int t = 0; t < 10; t++) {
		int N;
		scanf("%d", &N);
		string str;
		string postStr = "";
		cin >> str;
		stack<int> stk;
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (ch >= '0' && ch <= '9') {//���ڸ� �������� push
				postStr += ch;
			}
			else {
				if (stk.empty()) {
					stk.push(ch);	//���� ����ִ� ��� push
				}
				else {
					if (isp[getToken(stk.top())] < icp[getToken(ch)]) {
						stk.push(ch);	//���ÿ� �ִ� �ͺ��� �����¾� �켱������ ������ push
					}
					else {
						if (ch == ')') {	//'('���� ������ pop
							while (stk.top() != '(') {
								postStr += stk.top();
								stk.pop();
							}
							stk.pop();
						}
						else {
							while (isp[getToken(stk.top())] >= icp[getToken(ch)]) {
								postStr += stk.top();
								stk.pop();
							}
							stk.push(ch);
						}
					}
				}
			}
		}
		while (!stk.empty()) {
			postStr += stk.top();
			stk.pop();
		}

		stack<int> calStk;
		for (int i = 0; i < postStr.size(); i++) {
			char ch = postStr[i];

			if (ch >= '0' && ch <= '9') {
				calStk.push(ch - '0');
			}
			else {
				int num1 = calStk.top();
				calStk.pop();
				int num2 = calStk.top();
				calStk.pop();
				if (ch == '-') {
					calStk.push(num1 - num2);
				}
				else if (ch == '+') {
					calStk.push(num1 + num2);
				}
				else if (ch == '/') {
					calStk.push(num1 / num2);
				}
				else if (ch == '*') {
					calStk.push(num1 * num2);
				}
			}
		}

		cout << "#" << t + 1 << " " << calStk.top() << endl;
	}


}