package com.prac;

import java.util.Scanner;

public class SW�����ذ�_View_�Լ� {

	static int[][] arr = new int[1000][255]; // �迭 ����
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		for (int i = 1; i <= 10; i++) { // test case
			
			int cnt = 0; // ������ �� 
			int build = sc.nextInt(); // �ǹ� �� �Է�
			
			arr = new int[build][255]; // �ǹ� ����ŭ �迭 ������
			
			for (int j = 0; j < arr.length; j++) {
				int h = sc.nextInt(); // �� ���� �Է�
				for (int z = 0; z < h; z++) {
					arr[j][z] = 1; // �ش� �� value 1�� ����
				}
			}
			
			for (int j = 2; j < arr.length-2; j++) {
				for (int z = 0; z < arr[j].length; z++) {
					if(arr[j][z] == 1) { //������ ĭ
						if(arr[j-2][z] == 0 && arr[j-1][z] == 0 && arr[j+1][z] == 0 && arr[j+2][z] == 0) {
							cnt++;
						}
					}
				}
			}
			
			System.out.println("#" + i + " " + cnt);
		}
	}

}
