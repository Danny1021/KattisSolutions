import java.util.*;

public class ABC {

    public static void main (String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        Map<String, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();
        
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        String order = scan.next();
        
        list.add(a);
        list.add(b);
        list.add(c);
        
        Collections.sort(list);
        
        map.put("A", list.get(0));
        map.put("B", list.get(1));
        map.put("C", list.get(2));
        
        System.out.print(map.get(order.substring(0, 1)) + " ");
        System.out.print(map.get(order.substring(1, 2)) + " ");
        System.out.print(map.get(order.substring(2, 3)) + " ");
        
        scan.close();
    }
    
}
