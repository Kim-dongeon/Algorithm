package com.swexpert;

import java.util.Scanner;
import java.util.Stack;

public class D4_1218 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		
		
		for(int tc=0;tc<10;tc++)
		{
			int N =sc.nextInt();
			Stack []stk = new Stack[4];
			for(int i=0;i<stk.length;i++) {
				stk[i] = new Stack();
			}
			boolean flag = false;
			
			String str= sc.next();
			for(int i=0;i<str.length();i++)
			{
				char ch = str.charAt(i);
				if(ch == '(')
				{
					stk[0].push('(');
				}else if(ch == ')')
				{
					if(stk[0].isEmpty()) {
						flag = true;
						break;
					}else {
						stk[0].pop();
					}
				}else if(ch == '[')
				{
					stk[1].push('[');
				}else if(ch == ']')
				{
					if(stk[1].isEmpty()) {
						flag = true;
						break;
					}else {
						stk[1].pop();
					}
				}else if(ch == '{')
				{
					stk[2].push('{');
				}else if(ch == '}')
				{
					if(stk[2].isEmpty()) {
						flag = true;
						break;
					}else {
						stk[2].pop();
					}
				}else if(ch == '<')
				{
					stk[3].push('<');
				}else if(ch == '>')
				{
					if(stk[3].isEmpty()) {
						flag = true;
						break;
					}else {
						stk[3].pop();
					}
				}			
			}
			for(int i=0;i<stk.length;i++)
			{
				if(!stk[i].isEmpty())
				{
					flag = true;
					break;
				}
			}
			System.out.println("#"+(tc+1)+" "+1);
		}
	}

}
