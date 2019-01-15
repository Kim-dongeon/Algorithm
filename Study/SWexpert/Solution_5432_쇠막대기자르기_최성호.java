package com.ssafy.algo;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Solution_5432_쇠막대기자르기_최성호 {
	
	static int sum = 0;

	public static void main(String[] args) {
		
		Stack<Character> stack = new Stack<>();
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		//sc.nextLine();
		for (int tc = 1; tc <= T; tc++) {
			sum = 0;
			String arr = sc.next();
			char[] arr2 = new char[arr.length()];
			
			for(int i = 0; i < arr.length(); i ++) {
				arr2[i] = arr.charAt(i);
			}
			for(int i = 0; i < arr.length(); i ++) {
				if(arr2[i] == '(') {
					stack.push(arr2[i]);
				}
				if(arr2[i] == ')' && arr2[i-1] == '(') { // 레이저일때
					stack.pop();
					sum +=  stack.size();
				}
				if(arr2[i] == ')' && arr2[i-1] == ')') { // 쇠막대가 끝
					stack.pop();
					sum += 1;
				}
			}
			System.out.println("#" + tc + " " + sum);
			
		} // end of tc
		
	} // end of main

}
