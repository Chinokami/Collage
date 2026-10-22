import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int d = scan.nextInt();

        int result = ((127&a) + (32&c) | 4096) - (d&1200) + (b&131);

        System.out.println(result);

        scan.close();
    }
}
