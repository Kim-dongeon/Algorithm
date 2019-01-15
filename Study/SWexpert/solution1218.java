import java.util.Scanner;
import java.util.Stack;
 
public class Solution_1218_괄호짝짓기{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        for(int tc = 1; tc <=10;tc++) {
            int result = -1;
            int len = sc.nextInt();
 
            String str = sc.next();
            Stack s = new Stack();
            
            for(int i=0;i<len;i++) {
                if(str.charAt(i) == '(' || str.charAt(i) == '{' || str.charAt(i) == '[' || str.charAt(i) == '<' ) s.push(str.charAt(i));
                else if(str.charAt(i) == ')' || str.charAt(i) == '}' || str.charAt(i) == ']' || str.charAt(i) == '>') {
//                    if(s.isEmpty()){
//                        result = 0;
//                        break;
//                    }
                    char pop = (char) s.pop();
                    if ( (str.charAt(i) == ')' && pop =='(' ) 
                        || (str.charAt(i) == '}' && pop =='{' )
                        || (str.charAt(i) == ']' && pop =='[')
                        || (str.charAt(i) == '>' && pop =='<')) {
                        continue;
                    }else {
                        result = 0;
                    }
                    
                }
                if(result ==0 )break;
            }
            if(s.size() != 0) result = 0;
            else result = 1;
            
            
            System.out.println("#"+tc+" "+result);
            
            
        }
    }
}
 
