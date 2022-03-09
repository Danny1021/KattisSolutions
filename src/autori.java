import java.util.Scanner;

public class ArrayFill {
    
    public static void main (String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        String boh = scan.nextLine();
        
        System.out.print(boh.substring(0, 1));
        
        for (int i = 1; i < boh.length(); i++) {
            if (boh.charAt(i-1) == '-')
                System.out.print(boh.charAt(i));
        }
    
    }
}
