package com.swexpert;

import java.util.Scanner;

public class D4_1210 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		for(int tc=0;tc<10;tc++)
		{
			int T = sc.nextInt();
			
			int [][]arr = new int [100][100];
			
			for(int i=0;i<100;i++) {
				for(int j=0;j<100;j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			int start_y=0;
			
			for(int i=0;i<100;i++)
			{
				if(arr[99][i] == 2)
				{
					start_y =i;
					break;
				}
			}
			
			int start_x = 99;
			while(true) {	
				if(start_x == 0) {
					arr[start_x][start_y] = 3;
					break;
				}
				
				arr[start_x][start_y] = 3;
				if(start_y -1>= 0 && start_y+1<100)
				{
					int move =0;
					if(arr[start_x][start_y-1] ==1)
					{
						for(int i=start_y-1;arr[start_x][i] !=0 ;i--)
						{
							arr[start_x][i] =3;
							move--;
							if(i==0) break;
						}
					}else if(arr[start_x][start_y+1]==1)
					{
						for(int i=start_y+1;arr[start_x][i] !=0 ;i++)
						{
							arr[start_x][i] =3;
							move++;
							if(i==99) break;
						}
					}
					start_x--;
					start_y += move;
				}
				else if(start_y ==0)
				{
					int move =0;
					if(arr[start_x][start_y+1]==1)
					{
						for(int i=start_y+1;arr[start_x][i] !=0;i++)
						{
							arr[start_x][i] =3;
							move++;
						}
					}
					start_x--;
					start_y += move;
				}else if( start_y == 99)
				{
					int move =0;
					if(arr[start_x][start_y-1] ==1)
					{
						for(int i=start_y-1;arr[start_x][i] !=0;i--)
						{
							arr[start_x][i] =3;
							move--;
						}
					}
					start_x--;
					start_y += move;
				}
				
			}
			
			for(int i=0;i<100;i++)
			{
				if(arr[0][i] == 3)
				{
					System.out.println("#"+T+" "+i);
				}
			}
		}
	}	

}
