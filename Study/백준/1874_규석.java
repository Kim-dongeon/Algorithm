import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.ArrayList;

public class Problem1874 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		
		int[] arr = new int[num]; // �Է� �� ������ �迭 ����
		Stack<Integer> stack = new Stack<>(); // ���� ����
		ArrayList<String> str = new ArrayList<String>();
		
		for (int i = 0; i < num; i++) {
			arr[i] = Integer.parseInt(br.readLine()); //�Է��� �� arr�� ����
		}
		
		int cnt = 0; // ������ų ��
		int arrCnt = 0; // arr�迭 �ε���
		
		while(arrCnt!=num){ // �ε��� ���� num�̶� ���� ������
			
			if(stack.isEmpty()) { // ���� ��������� �߰�
				stack.push(++cnt);
				str.add("+");
			}
			
			else if(stack.peek() == arr[arrCnt]){ // ���� �� �� ���� arr�迭 ���� ������ pop
				str.add("-");
				stack.pop();
				arrCnt++; // ���� �� ã������ arr�迭 �ε��� ����
			}
			else if (stack.peek() <= arr[arrCnt]){ 
				str.add("+");
				stack.push(++cnt);
			}
			
			else {
				System.out.println("NO");
				return;
			}
		}
		
		for (int i = 0; i < str.size(); i++) {
			System.out.println(str.get(i));
		}
		
		br.close();
	}

}