class Vehicle {
    protected String model;
    protected int speed;

    public Vehicle(String model, int speed) {
        this.model = model;
        this.speed = speed;
    }

    public void getSpeed() {
        System.out.println(model + " їде по дорозі зі швидкістю " + speed);;
    }
}

class Car extends Vehicle {
    private int doorsCount;

    public Car(String model, int speed, int doorsCount) {
        super(model, speed);
        this.doorsCount = doorsCount;
    }

    public void drift() {
        System.out.println(model + " дрифтить!");
    }
}

class Train extends Vehicle {
    protected int wagonsCount;

    public Train(String model, int speed, int wagonsCount) {
        super(model, speed);
        this.wagonsCount = wagonsCount;
    }

    @Override
    public void getSpeed() {
        System.out.println(model + " їде по рельсам зі швидкістю " + speed);
    }
}

class ExpressTrain extends Train {
    private String destination;

    public ExpressTrain(String model, int speed, int wagonsCount, String destination) {
        super(model, speed, wagonsCount);
        this.destination = destination;
    }

    public void displayRoute() {
        System.out.println("Швидкісний експресс " + model + " їде без зупинок до станції: " + destination);
    }
}

public class Main {
     public static void main(String[] args) {
        Car myCar = new Car("Audi R8", 250, 2);
        myCar.getSpeed();
        myCar.drift();

        System.out.println();

        Train regularTrain = new Train("Товарний поїзд №42", 80, 30);
        regularTrain.getSpeed();

        System.out.println();

        ExpressTrain express = new ExpressTrain("Сапсан", 200, 10, "Одесса");
        express.getSpeed();
        express.displayRoute();
     }
 }
