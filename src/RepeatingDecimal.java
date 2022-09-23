import java.util.*;
import java.math.*;

public class RepeatingDecimal {
    
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        while (scan.hasNext()) {
            
            int numerator = scan.nextInt();
            int denominator = scan.nextInt();
            int truncate = scan.nextInt();
            
            BigDecimal output = BigDecimal.valueOf(numerator).divide(BigDecimal.valueOf(denominator), truncate, BigDecimal.ROUND_DOWN);
            
            System.out.println(output);
            
        }
      
        scan.close();
      
    }
}
