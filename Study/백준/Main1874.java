import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main1874 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int now;
		int cnt=0;
		int pre = Integer.parseInt(br.readLine());
		boolean[] checked = new boolean[n];
		for(int i=0;i<pre;i++) {
			System.out.println("+");
			cnt++;
			checked[cnt] = true;
		}
		System.out.println("-");
		checked[cnt]=false;
		
		while(true) {
			now = Integer.parseInt(br.readLine());
			if(now<pre) {
				for(int i=now;i<pre;i++) {
					if(!checked[i]) continue;
					System.out.println("-");
					checked[i]=false;
					if(i==0) {
						break;
					}
				}
			} else { // pre<now
				int cc=cnt;
				for(int i=cc+1;i<=now;i++) {
					System.out.println("+");
					checked[i]=true;
					cnt++;
				}
				System.out.println("-");
				checked[cnt] = false;
			}
			pre = now;
		}
	}
}
