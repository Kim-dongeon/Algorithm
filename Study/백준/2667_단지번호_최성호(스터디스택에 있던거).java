package backjoon;

import java.util.Arrays;
import java.util.Scanner;

public class b2667_������ȣ {

	static int n; // �迭 ũ��
	static int total, house; // �� ������ , �����ȿ� ����
	static int[] house2 = new int[650]; // �Ѱ��� ������ ���� �� �ִ� ���� �ִ�
	static int[][] map = new int[26][26]; // �迭 ����
	static int[][] visited = new int[26][26]; // bfs visited
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void dfs(int x, int y) {

		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue; // �������

			if (map[nx][ny] == 1 && visited[nx][ny] == 0) { // ������ ���� ���̰� visited �������� ��� ã��
				house++; // ���� ����
				dfs(nx, ny);
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// �Է�
		n = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = sc.next();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = s[i].charAt(j) - 48; // char���� int������ ���� 0->48 , 1->49�� ��
			}
		}

		// visited �ʱ�ȭ ��� ���� ���� �ʿ� ������
		/*
		 * for(int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { visited[i][j] = 0;
		 * } }
		 */

		// dfs��~
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					house++; // �ϴ� �� �Ѱ� ����
					dfs(i, j);
					total++; // dfs�������� ������ �Ѱ� �����Ѵ�
					house2[total] = house; // dfs������ �� ������ �� ���� ����
					house = 0; // dfs������ ���� �� ���� �ʱ�ȭ
				}
			}
		}
		System.out.println(total);
		Arrays.sort(house2);
		for (int i = 0; i < house2.length; i++) {
			if (house2[i] != 0)
				System.out.println(house2[i]);
		}

	} // end of main
}
