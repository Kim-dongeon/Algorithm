package com.prac;

import java.util.Scanner;

public class SW�����ذ�_��ȣ������_�Լ� {

	static int[] arr = new int[10];
	
	public static void cycle(int[] a) { // cycle �Լ�
		
		boolean c = true;
		
		for (int i = 1; i <= 5; i++) {
			
			if(a[0] >= 0) { // ù��° �迭�� 0���� Ŭ ���� ����
				a[0] -= i;
				if(a[0] < 0) a[0] = 0;
				a[8] = a[0];
				
				for (int j = 0; j < 8; j++) { // �迭 ���� ��ĭ shift
					a[j] = a[j+1];
				}
				
				if(a[7] == 0) { // ��ȣ���� ������  break
					c = false;
					break;
				}
				
			}
		}
		if(c) // �ȳ����� cycle �ݺ�
			cycle(a);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for (int i = 1; i <= 10; i++) {
			
			int ts = sc.nextInt();
			
			for (int j = 0; j < 8; j++) {
				arr[j] = sc.nextInt();
			}
			
			cycle(arr);
			
			System.out.print("#" + i + " ");
			for (int j = 0; j < 8; j++) {
				System.out.print(arr[j] + " ");
			}
			System.out.println();
		}
	}

}
