package com.ssafy.incheon;

import java.util.Scanner;

public class Problem10819 {
	
	static int[] t = new int[27483084]; // static���� �迭 ����
	static int cnt = 0; // static���� int�� ���� ����
	
	public static void swap(int[] arr, int a, int b){ // swap �޼ҵ�
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	
	public static void perm(int[] set, int size, int n, int k){ // ���� �޼ҵ�
		
		int sum = 0;
		
		if(size == k){
			for (int i = 0; i < size-1; i++) {
				sum += Math.abs(set[i]-set[i+1]); // ���밪 �� ����
			}
			t[cnt] = sum;
			cnt++;
			return;
		}
		
		for (int i = size; i < n; i++) {
			swap(set, i, size);
			perm(set, size+1, n, k);
			swap(set, i, size);
			
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int count = sc.nextInt();
		int[] arr = new int[count+1];
		int[] set = new int[100];
		
		for (int i = 0; i < count; i++) {
			arr[i] = sc.nextInt();
		}
		
		for (int i = 0; i < count; i++) {
			set[i] = arr[i];
		}
		
		perm(set, 0, count, count);
		
		int max = 0; // �ִ밪 ����
		
		for (int i = 0; i < cnt; i++) {
			if(max <= t[i]) max = t[i];
		}
		
		System.out.println(max);
		
	}

}
