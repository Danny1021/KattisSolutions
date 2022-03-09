import java.util.*;
public class Faktor {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        int articles = scan.nextInt();
        int impactFactor = scan.nextInt();
        
        System.out.println((articles*(impactFactor-1))+1);
        
    }
    
}
