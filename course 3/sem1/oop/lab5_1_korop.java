import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Введіть кількість студентів в групі: ");
        int n = scan.nextInt();

        Student[] group = new Student[n];

        System.out.println("Введіть Ім'я, Рік народження та Оцінки студента:");
        for (int i = 0; i < n; i++) {
            group[i] = new Student();
            group[i].name = scan.next();
            group[i].year = scan.nextInt();

            for (int j = 0; j < 4; j++) {
                group[i].bal[j] = scan.nextInt();
            }
        }
        scan.close();

        for (Student stud : group) {
            if (stud.getAverage() >= 4) {
                stud.showInfo();
            }
        }
    }
}

class Student {
    protected String name;
    protected int year;
    protected int[] bal = new int[4];

    public double getAverage() {
        double a = 0;

        for (int i : bal) {
            a += i;
        }

        return a / 4;
    }

    public void showInfo() {
        System.out.println(name + " ; " + year);
    }
}
