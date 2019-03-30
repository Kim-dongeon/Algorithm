#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int num;
	int t;
};
int N;
int M;
int receptionD[12];	//����â���� �ɸ��� �ð� ���
int repairD[12];
node people[1002];
int chk[1002][2];//����â��, ����â�� �����
int K;
int A, B;	//����, ���� 1�����ͽ���
int ans;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &receptionD[i]);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", &repairD[i]);
		}

		for (int i = 1; i <= K; i++) {
			int a;
			scanf("%d", &a);
			people[i] = { i,a };
		}

		//�մ� �� ������� ����
		sort(people, people + (K + 1), [](node a, node b) {
			if (a.t != b.t) {
				return a.t < b.t;
			}
			else {
				return a.num < b.num;
			}
			
		});

	
		int waiting_num = K;
		priority_queue<int, vector<int>, cmp> reception_waiting;
		queue<int> repair_waiting;
		node reception_ing[12] = { 0, };
		node repair_ing[12] = { 0, };

		for (int time = 0;waiting_num >0; time++) {
			
			for (int i = 1; i <= K; i++) {
				if (people[i].t == time) {
					//�մ� ����
					reception_waiting.push(people[i].num);
				}
				else if (people[i].t > time) {
					break;
				}
			}

			
			
			for (int i = 1; i <= N; i++) {				
				if (reception_ing[i].num == 0) {
					if (!reception_waiting.empty()) {
						//â���� �������
						int people_idx = reception_waiting.top();
						reception_waiting.pop();
						reception_ing[i] = { people_idx,time };
						
						chk[people_idx][0] = i;
					}						
				}
				else {
					if (reception_ing[i].t + receptionD[i] == time) {
						//������������ ���� ��⿭�� �̵�
						repair_waiting.push(reception_ing[i].num);
						reception_ing[i] = { 0,0 };
						i--;
					}
				}										
			}
			
			for (int i = 1; i <= M; i++) {
				if (repair_ing[i].num == 0) {
					if (!repair_waiting.empty()) {
						//â���� �������
						int people_idx = repair_waiting.front();
						repair_waiting.pop();
						repair_ing[i] = { people_idx,time };
						chk[people_idx][1] = i;
					}
				}
				else {
					if (repair_ing[i].t + repairD[i] == time) {
						//��γ�������
						waiting_num--;
						repair_ing[i] = { 0,0 };
						i--;
					}
				}
			}		
		}

		bool flag = false;
		for (int i = 1; i <= K; i++) {
			for (int j = 0; j < 2; j++) {				
				if (j == 0) {
					if (chk[i][j] != A) {
						flag = true;
						break;
					}
				}
				else {
					if (chk[i][j] != B) {
						flag = true;
					}
				}
			}			
			if (!flag) {
				ans += i;
				
			}
			flag = false;
		}
		if (ans == 0) { ans = -1; }
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
		for (int i = 0; i < 1002; i++) {
			for (int j = 0; j < 2; j++) {
				chk[i][j] = 0;
			}
		}
	}
}