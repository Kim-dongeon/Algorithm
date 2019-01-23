package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class b1874_���ü��� {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> stack1 = new Stack<>();
		Stack<Integer> stack2 = new Stack<>();
		Stack<Integer> stack3 = new Stack<>();
		Stack<Integer> stack4 = new Stack<>();
		
		int n = Integer.parseInt(bf.readLine());
		
		for(int i = 0; i < n; i++) {
			int number = Integer.parseInt(bf.readLine());
			stack1.push(number);
		}
		
		for(int i = n; i > 0; i--) {
			stack2.push(i);
		}
		
		int cnt = 0;
		while(true) {
			
			if(stack1.isEmpty()) break;
			
			if(!stack1.isEmpty() && !stack2.isEmpty() && stack1.peek() == stack2.peek() && cnt == 0) { // �ΰ����� �����鼭 �� ���� �ٸ� ���� ��������
				int a = stack2.pop();
				stack3.push(a);
				stack1.pop();
				System.out.println('+');
			}
			else if(!stack1.isEmpty() && !stack2.isEmpty() && stack1.peek() != stack2.peek()) { // �ΰ����� �ٸ���
				int b = stack2.pop();
				stack3.push(b);
				cnt++;
				System.out.println('+');
			}
			else if(!stack1.isEmpty() && !stack2.isEmpty() && stack1.peek() == stack2.peek() && cnt != 0) { // �ΰ����� �����鼭 �� ���� �ٸ� ���� �־�����
				stack1.pop();
				while(cnt != 0) {
					int c = stack3.pop();
					stack4.push(c);
					cnt--;
					System.out.println('-');
				}
				stack3.push(stack2.pop());
				System.out.println('+');
			}
			else if(!stack3.isEmpty()){
				stack4.push(stack3.pop());
				System.out.println('-');
			}
			else {
				System.out.println("NO");
				break;
			}
		}
		
	}
}
