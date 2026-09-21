import java.util.*;

class Complex {
    private double num;
    private double i;

    public Complex() {
        this.num = 0;
        this.i = 0;
    }

    public Complex(double num) {
        this.num = num;
        this.i = 0;
    }

    public Complex(double num, double i) {
        this.num = num;
        this.i = i;
    }

    public Complex(Complex a) {
        this.num = a.num;
        this.i = a.i;
    }

public double num() {
    return this.num;
}

public double i() {
    return this.i;
}

public Complex assign(Complex a) {
        this.num = a.num;
        this.i = a.i;

        return this;
    }

    public Complex sum(Complex a) {
        return new Complex(
            this.num + a.num(),
            this.i + a.i()
        );
    }

    public Complex minus(Complex a) {
        return new Complex(
            this.num - a.num(),
            this.i - a.i()
        );
    }

    public Complex multiplication(Complex a) {
        double real = this.num * a.num() - this.i * a.i();
        double imaginary = this.num * a.i() + this.i * a.num();

        return new Complex(real, imaginary);
    }

    public Complex division(Complex a) {
        double denominator = a.num() * a.num() + a.i() * a.i();

        double real = (this.num * a.num() + this.i * a.i()) / denominator;
        double imaginary = (this.i * a.num() - this.num * a.i()) / denominator;

        return new Complex(real, imaginary);
    }

    public void print() {
        if (i >= 0) {
            System.out.println(num + " + " + i + "i");
        } else {
            System.out.println(num + " - " + (-i) + "i");
        }
    }
}

public class Main {
    public static Complex[] sumVectors(Complex[] vector1, Complex[] vector2) {
    
        if (vector1.length != vector2.length) {
            throw new IllegalArgumentException(
                "Вектори повинні мати однакову розмірність"
            );
        }

        Complex[] result = new Complex[vector1.length];

        for (int i = 0; i < vector1.length; i++) {
            result[i] = vector1[i].sum(vector2[i]);
        }

        return result;
    }
    
    public static void main(String[] args) {

        Complex[] vector1 = {
            new Complex(4, 2),
            new Complex(3, 5),
            new Complex(7, -1)
        };

        Complex[] vector2 = {
            new Complex(6, 8),
            new Complex(2, -3),
            new Complex(1, 4)
        };

        Complex[] result = sumVectors(vector1, vector2);

        System.out.println("Результат складання векторів:");

        for (Complex number : result) {
            number.print();
        }
    }
}
