/*
영수는 민혁이가 말한 수가 몇 스트라이크 몇 볼인지를 답해준다. 민혁이가 영수의 세 자리 수를 정확하게 맞추어 3 스트라이크가 되면 게임이 끝난다. 아니라면 민혁이는 새로운 수를 생각해 다시 영수에게 묻는다. 현재 민혁이와 영수는 게임을 하고 있는 도중에 있다. 민혁이가 영수에게 어떤 수들을 물어보았는지, 그리고 각각의 물음에 영수가 어떤 대답을 했는지가 입력으로 주어진다. 이 입력을 바탕으로 여러분은 영수가 생각하고 있을 가능성이 있는 수가 총 몇 개인지를 알아맞혀야 한다.

아래와 같은 경우를 생각해보자.

* 민혁: 123
* 영수: 1 스트라이크 1 볼.
* 민혁: 356
* 영수: 1 스트라이크 0 볼.
* 민혁: 327
* 영수: 2 스트라이크 0 볼.
* 민혁: 489
* 영수: 0 스트라이크 1 볼.
이 때 가능한 답은 324와 328, 이렇게 두 가지이다.

영수는 동아리의 규율을 잘 따르는 착한 아이라 민혁이의 물음에 곧이곧대로 정직하게 답한다. 그러므로 영수의 답들에는 모순이 없다.

민혁이의 물음들과 각각의 물음에 대한 영수의 답이 입력으로 주어질 때 영수가 생각하고 있을 가능성이 있는 답의 총 개수를 출력하는 프로그램을 작성하시오.



입력
첫째 줄에는 민혁이가 영수에게 몇 번이나 질문을 했는지를 나타내는 1 이상 100 이하의 자연수 N이 주어진다. 이어지는 N개의 줄에는 각 줄마다 민혁이가 질문한 세 자리 수와 영수가 답한 스트라이크 개수를 나타내는 정수와 볼의 개수를 나타내는 정수, 이렇게 총 세 개의 정수가 빈칸을 사이에 두고 주어진다.



출력
첫 줄에 영수가 생각하고 있을 가능성이 있는 답의 총 개수를 출력한다.



예제 입력
4
123 1 1
356 1 0
327 2 0
489 0 1
예제 출력
2*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {

	int N;
	cin >> N;
	int promising[1001] = { 0, };
	for (int a = 0; a<N; a++) {
		string s;
		cin >> s;
		int st, b;
		cin >> st >> b;

		if (st == 3 && b == 0) {
			cout << "1";
			return 0;
		}
		else if (st == 2 && b == 0) {
			for (int j = 0; j<3; j++) {
				string num = s;
				for (int k = 1; k <= 9; k++) {
					if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
						num[j] = k + '0';
						promising[stoi(num)]++;
					}
				}
			}
		}
		else if (st == 1 && b == 2) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					string num = s;
					char tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
					promising[stoi(num)]++;
				}
			}
		}
		else if (st == 1 && b == 1) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					string num = s;
					char tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
					string num2 = num;
					for (int k = 1; k <= 9; k++) {
						if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
							num[j] = k + '0';
							num2[i] = k + '0';
							promising[stoi(num)]++;
							promising[stoi(num2)]++;

						}
					}

				}
			}
		}
		else if (st == 1 && b == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 1; j <= 9; j++) {
					string num = s;
					int idx = (i + 1) % 3;
					if (j != s[0] - '0' && j != s[1] - '0' && j != s[2] - '0') {
						num[idx] = j + '0';
						int jdx = (idx + 1) % 3;
						for (int k = 1; k <= 9; k++) {
							if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0' && k != num[idx] - '0') {
								num[jdx] = k + '0';
								promising[stoi(num)]++;
							}
						}
					}
				}
			}
		}
		else if (st == 0 && b == 3) {
			for (int j = 0; j < 2; j++) {
				char tmp = s[0];
				for (int i = 0; i < 3; i++) {
					s[i] = s[i + 1];
				}
				s[2] = tmp;
				promising[stoi(s)]++;
			}

		}
		else if (st == 0 && b == 2) {
			for (int i = 0; i < 3; i++) {
				int j = (i + 1) % 3;
				int k = (i + 2) % 3;
				for (int x = 1; x <= 9; x++) {
					if (x != s[0] - '0' && x != s[1] - '0' && x != s[2] - '0') {
						string num = s;
						char temp = num[j];
						num[j] = num[k];
						num[k] = temp;
						num[i] = x + '0';
						promising[stoi(num)]++;

					}
				}
			}

			string num = s;
			for (int j = 0; j < 2; j++) {

				char tmp = num[0];
				for (int i = 0; i < 3; i++) {
					num[i] = num[i + 1];
				}
				num[2] = tmp;

				string num1 = num;
				string num2 = num;
				string num3 = num;

				for (int k = 1; k <= 9; k++) {
					if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
						num1[1 - j] = k + '0';
						num2[(3 - j) % 3] = k + '0';
						num3[2 - j] = k + '0';

						promising[stoi(num1)]++;
						promising[stoi(num2)]++;
						promising[stoi(num3)]++;
						//cout << num1 << " " << num2 << " " << num3 << endl;

					}
				}
			}

		}
		else if (st == 0 && b == 1) {
			for (int i = 0; i < 3; i++) {
				int jdx = (i + 1) % 3;
				int kdx = (i + 2) % 3;
				string num = s;
				char temp = num[i];
				num[i] = num[jdx];
				num[jdx] = temp;

				for (int j = 1; j <= 9; j++) {
					string num1 = num;
					string num2 = num;
					if (j != s[0] - '0' && j != s[1] - '0' && j != s[2] - '0') {
						num1[jdx] = j + '0';
						num2[i] = j + '0';
						for (int k = 1; k <= 9; k++) {
							if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0' && k != j) {
								num1[kdx] = k + '0';
								num2[kdx] = k + '0';
								promising[stoi(num1)]++;
								promising[stoi(num2)]++;
							}
						}
					}
				}
			}
		}
		else if (st == 0 && b == 0) {
			for (int i = 100; i < 1000; i++) {
				string num = to_string(i);
				bool flag = false;
				if (num[0] != num[1] && num[1] != num[2] && num[0] != num[2] && i % 10 != 0 && num[1] != '0') {
					for (int j = 0; j < 3; j++) {
						if (num[j] == s[0] || num[j] == s[1] || num[j] == s[2]) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						promising[i]++;
					}
				}

			}
		}
		/*for (int q = 100; q < 1000; q++) {
		if (a + 1 == promising[q]) {
		cout << q << endl;
		}
		}
		cout << endl;*/
	}

	int cnt = 0;
	for (int i = 100; i < 1000; i++) {
		if (N == promising[i]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}