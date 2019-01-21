package com.swexpert;

import java.util.Scanner;
import java.util.Stack;

public class D4_1224 {
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
		Scanner sc = new Scanner(System.in);
		int [] isp = new int[] {-1,2,1,0};
		int [] icp = new int[] {-1,2,1,3};
		
		
		for(int t=0;t<10;t++) {
			
			int n = sc.nextInt();
			sc.nextLine();
			String str = sc.nextLine();
			
			String postStr = "";
			Stack<Character> stk = new Stack();
			for(int i=0;i<str.length();i++) {
				char ch = str.charAt(i);
				if(ch >= '0' && ch<='9') {
					postStr+=ch;
				}else if(ch == '(') {
					stk.push(ch);
				}else {
					int now = getToken(ch);
					int prev = 0;
					if(!stk.isEmpty()) {
						prev = getToken(stk.peek());
					}
					
					if(ch == ')') {
						while(stk.peek() != '(') {
							postStr += stk.peek();
							stk.pop();
						}
						stk.pop();
					}
					else if(isp[prev] < icp[now]) {
						stk.push(ch);
					}else {
						while(!stk.isEmpty() && icp[now] <= isp[getToken(stk.peek())]) {
							postStr += stk.peek();
							stk.pop();
						}
						stk.push(ch);
					}
				}				
			}//후위 연산으로
			while(!stk.empty()) {
				postStr+=stk.peek();
				stk.pop();
			}
			//System.out.println(postStr);
			
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
			System.out.println("#"+(t+1)+" "+calStk.peek());
		}
	}

}
