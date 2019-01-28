import java.util.Scanner;

public class Main {
	
	static char[][] map;
	static boolean[][] visited;
	static boolean[] alpha;
	static int dx[] = {0, 0, -1, 1};
	static int dy[] = {-1, 1, 0, 0};
	static int r;
	static int c;
	static int count = 0;
	static int max;
	
	public static void dfs(int x, int y) {
		
		visited[x][y] = true;
		alpha[map[x][y] - 'A'] = true;
		count++;
		
		int ax, ay;
		
		for (int i = 0; i < 4; i++) {
			
			ax = x + dx[i];
			ay = y + dy[i];
			
			if(ax >= 0 && ay >= 0 && ax < r && ay < c && !visited[ax][ay]) {
				if (!(alpha[map[ax][ay] - 'A'])) {
					//System.out.println(ax + "," + ay);
					dfs(ax, ay);
					count++;
					visited[ax][ay] = false;
					alpha[map[ax][ay] - 'A'] = false;
				}
			}
		}
		//System.out.println(max + ", " + count);
		max = Math.max(max, count);
		count=0;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		r = sc.nextInt();
		c = sc.nextInt();
		
		map = new char[r+1][c+1];
		visited = new boolean[r+1][c+1];
		alpha = new boolean[27];
		
		String[] str = new String[r];
		
		for (int i = 0; i < r; i++) {
			str[i] = sc.next();
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				map[i][j] = str[i].charAt(j);
			}
		}
		
		/*
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		*/

		dfs(0, 0);
		
		System.out.println(max);
	}

}
