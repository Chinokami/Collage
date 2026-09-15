import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        System.out.print("Введіть розмір массиву: ");
        int n = scanner.nextInt();

        scanner.close();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int a = random.nextInt(201) - 100;
            arr[i] = a;
        }

        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();

        System.out.println(smallest(arr));
        System.out.println(sum(arr));

        int[] neg_arr = rearrange(arr);

        for (int i : neg_arr) {
            System.out.print(i + " ");
        }

    }

    public static int smallest(int[] arr) {
        int result = 100;
        int index = 0;

        for (int i = 0; i < arr.length; i++) {
            if (Math.abs(arr[i]) < result) {
                result = Math.abs(arr[i]);
                index = i;
            }
        }

        return index;
    }

    public static int sum(int[] arr) {
        int sum = 0;
        boolean minus = false;

        for (int i : arr) {
            if (minus) {
                sum += i;
            } else if (i < 0) {
                minus = true;
            }
        }

        return sum;
    }

    public static int[] rearrange(int[] arr) {
        int negCount = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                negCount++;
            }
        }

        int[] result = new int[arr.length];
        int[] negatives = new int[negCount];

        int negIdx = 0;
        int otherIdx = negCount;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                negatives[negIdx++] = arr[i];
            } else {
                result[otherIdx++] = arr[i];
            }
        }

        for (int i = 0; i < negatives.length - 1; i++) {
            for (int j = 0; j < negatives.length - 1 - i; j++) {
                if (negatives[j] > negatives[j + 1]) {
                    int temp = negatives[j];
                    negatives[j] = negatives[j + 1];
                    negatives[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < negatives.length; i++) {
            result[i] = negatives[i];
        }

        return result;
    }
}
