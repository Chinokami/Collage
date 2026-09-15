public class Main {
    public static void main(String[] args) {
        double a = 2.3;
        double b = 1.8;
        System.out.println(multiply(a, b));

        int c = 3;
        int d = 5;
        int e = 3;
        int f = 9;
        System.out.println(multiply(c, d, e, f));
    }

    public static double multiply(double a, double b) {
        return a * b;
    }

    public static String multiply(int num1, int den1, int num2, int den2) {
        if (den1 == 0 || den2 == 0) {
            throw new IllegalArgumentException("Знаменник не може дорівнювати нулю.");
        }
        int resultNum = num1 * num2;
        int resultDen = den1 * den2;

        int gcd = gcd(Math.abs(resultNum), Math.abs(resultDen));
        return (resultNum / gcd) + "/" + (resultDen / gcd);
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
