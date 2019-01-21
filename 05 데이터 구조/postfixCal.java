package com.prac;

import java.util.Stack;

public class pra1_218p {

	static int getToken(char ch) {
		int token = 0;
		if(ch == ')') {
			token =0;
		}else if(ch == '*' || ch == '/') {
			token = 1;
		}else if(ch== '+' || ch == '-') {
			token =2;
		}else if(ch == '(') {
			token = 3;
		}else {
			token = -1;
			System.out.println("연산자 잘못입력");
		}
		return token;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int [] isp = new int[] {-1,2,1,0};
		int [] icp = new int[] {-1,2,1,3};
		
		String str = "(6+5*(2-8)/2)";
		String postStr="";
		Stack<Character> stk = new Stack<>();	
		
		for(int i=0;i<str.length();i++) {
			char ch = str.charAt(i);
			if(ch >= '0' && ch<='9') {
				//System.out.print(ch+" ");
				postStr += ch;
			}else {
				int now = getToken(ch);
				int prev = 0;
				if(!stk.empty()) {
					prev = getToken(stk.peek());
				}
				
				if(icp[now] == -1) {
					while(stk.peek() != '(')
					{
						//System.out.print(stk.peek()+" ");
						postStr += stk.peek();
						stk.pop();
					}
					stk.pop();					
				}
				else if(icp[now] > isp[prev]) {
					stk.push(ch);
				}else {
					while(icp[now] <= isp[getToken(stk.peek())]) {
						//System.out.print(stk.peek()+" ");
						postStr += stk.peek();
						stk.pop();
					}
					stk.push(ch);
				}
			}
		}
		System.out.println(postStr);
		
		Stack<Integer> calStk = new Stack();
		for(int i=0;i<postStr.length();i++) {
			char ch = postStr.charAt(i);
			if(ch>='0' && ch <='9') {
				calStk.push(ch-'0');
			}else if (ch =='-') {
				int num1 = (int)calStk.peek();
				calStk.pop();
				int num2 = (int)calStk.peek();
				calStk.pop();
				calStk.push(num2 - num1);
			}else if (ch =='+') {
				int num1 = (int)calStk.peek();
				calStk.pop();
				int num2 = (int)calStk.peek();
				calStk.pop();
				calStk.push(num2 + num1);
			}else if (ch =='*') {
				int num1 = (int)calStk.peek();
				calStk.pop();
				int num2 = (int)calStk.peek();
				calStk.pop();
				calStk.push(num2 * num1);
			}else if (ch =='/') {
				int num1 = (int)calStk.peek();
				calStk.pop();
				int num2 = (int)calStk.peek();
				calStk.pop();
				calStk.push(num2 / num1);
			}
		}
		System.out.println(calStk.peek());
	}

}
