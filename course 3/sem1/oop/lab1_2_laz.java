import java.lang.Integer;

public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 3, 4, 5, 6, -1, 33, 55, 4, 60};

        for (int i : arr) {
            System.out.print(i + " ");
        }

        System.out.println("   " + foo(arr));
    }

    public static int foo(int[] arr) {
        boolean minus = false;
        Integer minimum = null;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0 || minus) {
                minus = true;
                if ((i + 1) % 2 == 0 && arr[i] > 0) {
                    if (minimum == null || arr[i] < minimum) {
                        minimum = arr[i];
                    }
                }
            }
        }

        return (minimum == null) ? -1 : minimum;
    }
}
