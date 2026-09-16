import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[] arr = new int[10];

        System.out.println("Введіть елементи масиву (10 цілих чисел) в одному рядку та натисніть <Enter>. ");
        for (int i = 0; i < 10; i++) {
            arr[i] = scan.nextInt();
        }

        System.out.println("Сума елементів масиву: " + sum(arr));
        System.out.println("Кількість ненульових елементів: " + notNull(arr));
        System.out.println("Середньо арифметичне значення ненульових елементів: " + average(arr));

    }

    public static int notNull(int[] arr) {
        int count = 0;

        for (int i : arr) {
            if (i != 0) {
                count++;
            }
        }

        return count;
    }

    public static int sum(int[] arr) {
        int sum = 0;

        for (int i : arr) {
            sum += i;
        }

        return sum;
    }

    public static double average(int[] arr) {
        double sum = sum(arr);
        double count = notNull(arr);

        double average = sum / count;

        return average;
    }
}
