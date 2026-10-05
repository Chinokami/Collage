import java.util.Scanner;
import java.lang.Integer;

public class Main {
    public static void main(String[] args) {
        Fraction one = new Fraction(1, 4);
        Fraction two = new Fraction(6, 8);

        Fraction three = one.add(two);
        three.fractionDisplay();

        two.fractionEntry();

        Fraction four = one.minus(two);
        four.fractionDisplay();
    }
}

class Fraction {
    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public void fractionEntry() {
        Scanner scan = new Scanner(System.in);
        String fraction = scan.nextLine();

        scan.close();

        String[] parts = fraction.split("/");

        this.numerator = Integer.parseInt(parts[0]);
        this.denominator = Integer.parseInt(parts[1]);
    }

    public void fractionDisplay() {
        System.out.println(numerator + "/" + denominator);
    }

    public Fraction add(Fraction other) {
        int newNum = this.numerator * other.denominator + other.numerator * this.denominator;
        int newDen = this.denominator * other.denominator;
        return new Fraction(newNum, newDen);
    }

    public Fraction minus(Fraction other) {
        int newNum = this.numerator * other.denominator - other.numerator * this.denominator;
        int newDen = this.denominator * other.denominator;
        return new Fraction(newNum, newDen);
    }
}
