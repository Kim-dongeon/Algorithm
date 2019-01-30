package com.prac;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem10026 {

	static int[][] map;
	static boolean[][] visited;
	static int n;
	static int[] dx = {0, 0, -1, 1};
	static int[] dy = {-1, 1, 0, 0};
	static int count = 0; // ����
	static int count2 = 0; // ���ϻ���
	
	public static void dfs(int x, int y) {
		visited[x][y] = true;
		
		int chk = map[x][y]; // ���� �� ����
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == false){
				if(chk == map[nx][ny]){ // ������ dfs
					dfs(nx,ny);
				}
			}
		}
		
	}
	
	public static void dfs2(int x, int y){
		visited[x][y] = true;
		
		int chk = map[x][y]; // ���� �� ����
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == false){
				if(chk == map[nx][ny]){ // ������ dfs
					dfs(nx,ny);
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		map = new int[n][n];
		
		for (int i = 0; i < n; i++) {
			String[] str = br.readLine().split("");
			for (int j = 0; j < n; j++) {
				map[i][j] = str[j].charAt(0) - 'A';
			}
		}
		//���� : 17 / ��� : 1 / �׸� : 6
		
		visited = new boolean[n][n];
		// ������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(visited[i][j] == false){
					count++;
					dfs(i,j);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(map[i][j] == 6){ // �׸��� ����� ����
					map[i][j] = 17;
				}
			}
		}
		
		visited = new boolean[n][n]; // �ٽ� �ʱ�ȭ
		
		// ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(visited[i][j] == false){
					count2++;
					dfs2(i,j);
				}
			}
		}
		
		
		System.out.println(count + " " + count2);
	}

}