package com.ssafy.algo;

import java.util.Scanner;

public class Solution_1210_SW문제해결기본2일차_Ladder1_최성호 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		for(int tc = 1; tc <= 10; tc++) {
			
			int t = sc.nextInt();
			int[][] arr = new int[100][100];
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr.length; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			int index = 0;
			int start = 0;
			
			for (int j = 0; j < arr.length; j++) {
				if(arr[99][j] == 2)
					start = j;
			} // start = 57
			for(int i = 98; i > 0; i--) {
				
				if(start-1 >= 0) {
					if(arr[i][start-1] == 1) {
						
						while(true) {
							if(start >= 0 && arr[i][start] == 1) {
								start--;
							}
							else {
								index = start+1;
								break;
							}
						}
						start = index;
						continue;
					}
				}
				
				if(start+1 <= 99) {
					if(arr[i][start+1] == 1) {
						while(true) {
							if(start <= 99 && arr[i][start] == 1) {
								start++;
							}
							else {
								index = start-1;
								break;
							}
						}
						start = index;
						continue;
					}
				}
			} // for
			
			System.out.println();
			System.out.println("#" + tc + " " + start);
			
		} // end of tc
		
	} // end of main

}
