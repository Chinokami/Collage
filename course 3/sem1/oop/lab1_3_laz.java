import java.util.Scanner;

public class Main {

    static class Point {
        double x, y;
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static double sign(Point p1, Point p2, Point p3) {
        return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
    }

    static boolean isInsideTriangle(Point pt, Point v1, Point v2, Point v3) {
        double d1, d2, d3;
        boolean has_neg, has_pos;

        d1 = sign(pt, v1, v2);
        d2 = sign(pt, v2, v3);
        d3 = sign(pt, v3, v1);

        has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
        has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

        return !(has_neg && has_pos);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введіть координати вершини A (x y):");
        Point a = new Point(scanner.nextDouble(), scanner.nextDouble());

        System.out.println("Введіть координати вершини B (x y):");
        Point b = new Point(scanner.nextDouble(), scanner.nextDouble());

        System.out.println("Введіть координати вершини C (x y):");
        Point c = new Point(scanner.nextDouble(), scanner.nextDouble());

        System.out.println("Введіть кількість точок n (n <= 200):");
        int n = scanner.nextInt();

        int pointsInside = 0;

        System.out.println("Введіть координати " + n + " точок (попарно x y):");
        for (int i = 0; i < n; i++) {
            Point p = new Point(scanner.nextDouble(), scanner.nextDouble());
            if (isInsideTriangle(p, a, b, c)) {
                pointsInside++;
            }
        }

        System.out.println("Кількість точок, що належать трикутнику: " + pointsInside);

        scanner.close();
    }
}
