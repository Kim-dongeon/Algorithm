import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Tower {
	int number;
	int size;
	
	public Tower(int number, int size) {
		this.number = number;
		this.size = size;
	}
	
	
}

public class Solution_TopRasor {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		int T = sc.nextInt();
		
		for(int t=1;t<=T;t++) {
			Stack<Tower> stack = new Stack<>();
			ArrayList<Integer> list = new ArrayList<>();
			int N= sc.nextInt();//height
			int now=0;
			int idx=0;
			//int[] ans = new int[N]; //answer
			for(int i=0;i<N;i++) {
				now = sc.nextInt();
				
				if(stack.empty()) list.add(0);
				else {
					while(!stack.empty()) {
						
						
						if(stack.peek().size < now ) {
							stack.pop();
							if(stack.empty()) list.add(0);
							
						} else {
							list.add(stack.peek().number);
							break;
						}
					}
				}
				stack.push(new Tower(++idx,now));
			}
			
			System.out.print("#"+t+" ");
			for(int i=0;i<list.size();i++) {
				System.out.print(list.get(i)+" ");
			}
			System.out.println();
		}
		
	}
}
