import java.util.*;

public class Aaah {
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        String whatJonCanSay = scan.nextLine();
        String whatDoctorTellsToSay = scan.nextLine();
        
        if (whatJonCanSay.length() >= whatDoctorTellsToSay.length())
            System.out.println("go");
        else
            System.out.println("no");
        
    }
}
