import java.math.*;
import java.util.*;

public class AnotherCandies { 
    
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        int cases = scan.nextInt();
        BigInteger sum = BigInteger.ZERO;
        boolean check = false;
        
        while (cases --> 0) {
            
            int children = scan.nextInt();
            
            for (int i = 0; i < children; i++) {
                
                BigInteger[] candiesArr = new BigInteger[children];
                candiesArr[i] = scan.nextBigInteger();
                
                sum = sum.add(candiesArr[i]);
                
            }
            
            if ((sum.mod(BigInteger.valueOf(children)) == BigInteger.ZERO))
                check = true;
        
            if (check)
                System.out.println("YES");
            else
                System.out.println("NO");
            
            sum = BigInteger.ZERO;
            check = false;
        }
        
        scan.close();
        
    }
    
}
