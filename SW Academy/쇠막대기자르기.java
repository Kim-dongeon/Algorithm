package com.swexpert;

import java.util.Scanner;
import java.util.Stack;

public class D4_5432 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		
		for(int t=0;t<T;t++)
		{
			String str = sc.next();
			str= str+"!";
			Stack stk = new Stack();
			
			int ans =0;
			for(int i=0;i<str.length()-1 ;i++)
			{
				if(str.charAt(i) == '(')
				{
					if(str.charAt(i+1) == ')')
					{						
						ans += stk.size();
						i++;
					}else {
						stk.push('(');
					}
				}else {
					ans++;
					stk.pop();
				}
				
			}
			System.out.println("#"+(t+1)+" "+ans);
		}
	}

}
