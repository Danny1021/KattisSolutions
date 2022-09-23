import java.util.*;
public class InverseFactorial {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        String input = scan.next();
        
        if (input.length() < 8) {
            
            int fac = 1;
            
            for (int i = 1; i < 11; i++) {
                fac *= i;
                if ((fac + "").equals(input)) {
                    System.out.println(i);
                    break;
                }
            }
            
        } else {
            
            double logsum = Math.log10(3628800);
            int uLen = input.length()-1;
            
            for (int i = 11; true; i++) {
                logsum += Math.log10(i);
                if ((int)(logsum) == uLen) {
                    System.out.println(i);
                    break;
                }
            }
            
        }
        scan.close();
    }
    
}
