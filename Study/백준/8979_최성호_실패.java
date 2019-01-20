package backjoon;

import java.util.Scanner;

public class b8979 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // ���� ����
		int k = sc.nextInt(); // ����� �ñ��� ����
		int[][] arr = new int[n][4]; // n�� ���� �����ȣ , �� , �� , �� ������ ����
		for (int i = 0; i < n; i++) { // ���� ��ȣ�� �޴� ���� �Է�
			for (int j = 0; j < 4; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		int gold = arr[k-1][1]; // ����� �ñ��� ������ �ݸ޴� ����
		int silver = arr[k-1][2]; // ����� �ñ��� ������ ���޴� ����
		int bronze = arr[k-1][3]; // ����� �ñ��� ������ ���޴� ����
		int cnt_g = 0; // �ݸ޴��� �ڽź��� �� ���� ���� ī��Ʈ
		int cnt_s = 0; // ���޴��� �ڽź��� �� ���� ���� ī��Ʈ
		int cnt_b = 0; // ���޴��� �ڽź��� �� ���� ���� ī��Ʈ
		int[] same_gold = new int[1000]; // �ݸ޴� ������ ������ ���޴� ���� ����
		int[] same_silver = new int[1000]; // �ݸ޴� ������ ���� ���޴� ������ ������ ���޴� ���� ����
		int same_gold_index = 0;
		int same_silver_index = 0;
		
		for (int i = 0; i < arr.length; i++) {
			if(gold < arr[i][1]) { // �ݸ޴� ������ �ڽź��� ������ ī��Ʈ
				cnt_g++;
			}
			if(gold == arr[i][1]) { // �ݸ޴� ������ �ڽŰ� ������ �׶��� ���޴� ���� ����
				same_gold[same_gold_index++] = arr[i][2];
				if(silver == arr[i][2]) { // �ݸ޴� ������ �ڽŰ� ���� �͵� �߿��� ���޴� ������ ������ �׶��� ���޴� ������ ����
					same_silver[same_silver_index++] = arr[i][3];
				}
			}
		}
		
		for (int i = 0; i <= same_gold_index; i++) { // �ݸ޴� ������ ���Ҵ� ������ ���޴� ������ ��
			if(silver < same_gold[i]) {
				cnt_s++;
			}
			if(silver == same_gold[i]) { // ���޴޵� ������
				for(int j = 0; j < same_silver_index; j++) {
					if(bronze < same_silver[j]) { // �׶��� ���޴� ��
						cnt_b++;
					}
				}
			}
		}
		
		
		/*for (int i = 0; i < same_gold_index; i++) {
			System.out.println("same gold : " + same_gold[i]);
		}
		for (int i = 0; i < same_silver_index; i++) {
			System.out.println("same silver : " + same_silver[i]);
		}
		System.out.println("cnt_g : " + cnt_g);
		System.out.println("cnt_s : " + cnt_s);
		System.out.println("cnt_b : " + cnt_b);*/
		int sum = cnt_g + cnt_s + cnt_b + 1;
		System.out.println(sum);
	}

}
