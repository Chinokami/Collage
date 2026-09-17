import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        int[][] matrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scan.nextInt();
            }
        }

        System.out.println(magicSquare(matrix));
    }

    public static boolean magicSquare(int[][] matrix) {
        int number = 0;
        int temp = 0;

        for (int[] arr : matrix) {
            temp = 0;
            for (int i : arr) {
                temp += i;
            }

            if (number == 0) {
                number = temp;
            } else if (number != temp) return false;
        }

        for (int i = 0; i < matrix.length; i++) {
            temp = 0;
            for (int j = 0; j < matrix.length; j++) {
                temp += matrix[j][i];
            }

            if (number != temp) return false;
        }

        temp = 0;
        for (int i = 0; i < matrix.length; i++) {
            temp += matrix[i][i];
        }
        if (temp != number) return false;

        temp = 0;
        for (int i = matrix.length - 1; i >= 0; i--) {
            temp += matrix[i][i];
        }
        if (temp != number) return false;

        return true;
    }
}
