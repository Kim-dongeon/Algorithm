import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
 
public class Solution_5432_쇠막대기자르기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        for(int tc = 1 ;tc<= T ;tc++) {
            String str = br.readLine();
            char now;
            char[] arr = new char[str.length()];
            int piece = 0;
            int stick=0;
            for(int i=0;i<str.length();i++) {
                now = str.charAt(i);
                
                if(now==')') {
                    char pre = str.charAt(i-1);
                    if(pre == '(') { //레이저
                        stick--;
                        piece += stick;
                    }
                    else {
                        stick --;
                        piece++;
                    }
                }
                
                if(now == '(') {
                    stick++;
                }
                
            }
        
        
            System.out.println("#"+tc+" "+piece);
        }//testcase end
    }// end of main
}
 
