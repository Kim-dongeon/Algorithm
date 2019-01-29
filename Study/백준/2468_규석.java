package com.ssafy.incheon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2468 {

	static int[][] map; // 2���� �迭 ����
	static boolean[][] visited; // �湮�� ���� Ȯ���� 2���� boolean �迭 ����
	static int n; // �迭 ������ ���� ���� ����
	static int[] dx = {0, 0, -1, 1}; // �����¿� �� Ȯ���� �迭 ����
	static int[] dy = {-1, 1, 0, 0};
	
	public static void dfs(int x, int y, int c){ // dfs
		visited[x][y] = true; // �ش� ��ġ �湮 �Ϸ�
		
		for (int i = 0; i < 4; i++) { // �����¿� Ȯ��
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < n){ // �迭�� ����� �ʰ� ���ǹ� ����
				if(visited[nx][ny] == false && map[nx][ny] > c){ // ���� �湮���� ���� ���̰ų�, ������ ���̸�
					dfs(nx, ny, c);
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		map = new int[n][n];
		
		int max = 0;
		
		for (int i = 0; i < n; i++) {
			String[] str = br.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(str[j]);
				if(max < map[i][j]){ // �ִ� ���� ����
					max = map[i][j];
				}
			}
		}
		
		int maxCount = 1;
		int cnt = 0;
		
		for (int c = 1; c <= max; c++) { // �ִ� ���̸�ŭ for������ ���� ���� �ִ� ���� ã��
			visited = new boolean[n][n];
			cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(map[i][j] > c && visited[i][j] == false){ // ������ ���̰ų� �ѹ��� �湮���� �ʾ����� 
						cnt++;
						dfs(i,j,c);
					}
				}
			}
			if (maxCount < cnt) maxCount = cnt;
		}
		
		System.out.println(maxCount);
	}

}
