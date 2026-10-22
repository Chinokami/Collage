import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }

        a = foo(a, n);

        for (int i : a) {
            System.out.println(i);
        }
    }

    public static int[] foo(int[] arr, int size) {
        int[] result = new int[size];

        for (int i = 0; i < size; i++) {
            if (i < size / 2) {
                result[i] = arr[i] * 2;
            } else {
                result[i] = arr[i] * 3;
            }
        }

        return result;
    }
}
