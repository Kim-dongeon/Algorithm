package com.ssafy.incheon;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/* �Է� ��
 * 4 3 (���� ��, ���� ��ȣ)
 * 1 1 2 0 (���� ��ȣ, �ݸ޴�, ���޴�, ���޴�)
 * 2 0 1 0
 * 3 0 1 0
 * 4 0 0 1
 * 
 * ��� ��
 * 4�� ���� �� 3��° ���� ���� ��� : 3���� 0 1 0���� ���� 2��
 * 
 * ���� �迭 ���� ��, �������� String���� ����
 * 
 * ��, ���� �Է� ���� �Ʒ��� ����
 * 
 * arr[1] = "120" (��1��2��0)
 * arr[2] = "010"
 * arr[3] = "010"
 * arr[4] = "001"
 * 
 * ���Ŀ� �������� �����ϸ�, String�� ū������ ���ʷ� ����
 */

public class Problem8979 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int count = sc.nextInt(); // ���� �� �Է�
		int rankChk = sc.nextInt(); // ��� �˰� ���� ���� �Է�
		
		String[] countryArr = new String[count]; // ���� ���� �迭
		String[] g = new String[count]; // �ݸ޴� ���� �迭
		String[] s = new String[count]; // ���޴� ���� �迭
		String[] b = new String[count]; // ���޴� ���� �迭
		
		
		for (int i = 0; i < count; i++) { // �Է� ��
			int country = sc.nextInt();
			int gold = sc.nextInt();
			int silver = sc.nextInt();
			int bronze = sc.nextInt();
			
			//���ڿ��� ��ȯ�ؼ� �� �迭�� ����
			g[country-1] = Integer.toString(gold); 
			s[country-1] = Integer.toString(silver);
			b[country-1] = Integer.toString(bronze);
		}
		
		int maxNum = 0; // �迭���� �ڸ��� �ִ� �� ����
		
		for (int i = 0; i < count; i++) {
			//�迭 ���鼭 �ڸ��� �ִ� �� ã��
			int m = Math.max(g[i].length(), s[i].length());
			int num = Math.max(m, b[i].length());
			
			//maxNum�� ����
			if (maxNum <= num) maxNum = num;
		}
		
		// countryArr�� �����Ű��
		// �� �޴��� �ڸ����� �޶��� �� ���ڿ� ��ȯ ���� �������� ������ �߸� ��µǴ� ��츦 �ذ��ϱ� ���� ����
		for (int i = 0; i < count; i++) {
			
			String newG = "";
			String newS = "";
			String newB = "";
			
			//���� �ִ� �ڸ��� maxNum���� �޴� ���� ��ŭ �� ���� ����
			int chkg = maxNum - g[i].length();
			int chks = maxNum - s[i].length();
			int chkb = maxNum - b[i].length();
			
			//���� �ݸ޴��� 1000���� 1000���� ����ǰ�
			//���� �ٸ� ������ �ݸ޴��� 1���� 0001�� �����ϱ� ���� (�̷��� ���� �� ����)
			if(chkg > 0){
				for(int j = 0; j < chkg; j++){
					newG += "0";
				}
			}
			if(chks > 0){
				for(int j = 0; j < chks; j++){
					newS += "0";
				}
			}
			if(chkb > 0){
				for(int j = 0; j < chkb; j++){
					newB += "0";
				}
			}
			
			newG += g[i];
			newS += s[i];
			newB += b[i];
			
			//���� countryArr �迭�� ����
			countryArr[i] = newG +','+ newS +','+ newB;
		}
		
		
		String[] copyArr = new String[count]; // ���� ���� �迭 ����
		for (int i = 0; i < count; i++) {
			copyArr[i] = countryArr[i];
		}
		
		
		
		//�������� ����
		Arrays.sort(copyArr, String.CASE_INSENSITIVE_ORDER);
		
		List<String> list = Arrays.asList(copyArr);
		Collections.reverse(list);
		
		copyArr = list.toArray(new String[list.size()]); // ���� �Ϸ�

		//���� Ȯ��
		for (int j = 0; j < count; j++) {
			if(countryArr[rankChk-1].equals(copyArr[j])){
				System.out.println(j+1);
				break;
			}
		}
	}
}