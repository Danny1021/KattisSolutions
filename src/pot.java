import java.util.Scanner;

public class Pot {

    public static void main (String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        int count = scan.nextInt();
        double n;
        int sum = 0;
        
        for (int i = 0; i < count; i++) {
            n = scan.nextInt();
            n = Math.pow((int)(n/10), n%10);
            sum += n;
        }
        
        System.out.println(sum);
    }
    
}
