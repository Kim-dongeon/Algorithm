/*문제
두 문자열 A, B 가 주어질 때, 두 문자열 사이의 거리를 구하려 한다.여기서 거리는 다음과 같이 정의된다.문자열 A가 주어질 때, 여기서 하나의 연산은 하나의 알파벳을 삽입 또는 삭제하는 것을 의미한다.문자열 A와 B 사이의 거리란, A에서 시작하여 B를 만들기 위한 최소 연산의 횟수로 정의된다.예를 들어, 문자열 A가 “abcabcd”이고, 문자열 B가 “abccabc” 라면, 문자열 A와 B 사이의 거리는 2가 된다.왜냐하면 문자열 A의 세 번째에 ‘c’를 삽입하고, 가장 마지막에 있는 ‘d’를 삭제하면 문자열 B를 얻기 때문이다.두 문자열이 주어질 때, 두 문자열 사이의 거리를 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄과 두 번째 줄에 문자열이 주어지며, 이 문자열의 길이는 1000을 넘지 않는다.주어진 문자열은 대소문자가 섞여있다.

출력
두 문자열 사이의 거리를 출력한다. (대문자 'A'와 소문자 'a'는 다른 문자로 취급한다.)



예제 입력
abcabcd
abccabc
예제 출력
2*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1001][1001];

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;

	int str1_len = str1.size();
	int str2_len = str2.size();

	for (int i = 1; i <= str1_len; i++) {
		for (int j = 1; j <= str2_len; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int lcs = dp[str1_len][str2_len];
	cout << abs(str1_len - lcs) + abs(str2_len - lcs);
	return 0;
}