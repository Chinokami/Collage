class Date {
    private int day;
    private int month;
    private int year;

    public Date(int day, int month, int year) {
        if (check(day, month, year)) {
            throw new IllegalArgumentException("Не підходяще введення користувача");
        }
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Date(int year) {
        this(1, 1, year);
    }

    protected boolean check(int day, int month, int year) {
        if (day > 31 || day < 1) {
            return true;
        } else if (month > 12 || month < 1) {
            return true;
        }

        return false;
    }

    public int getDay() {
        return this.day;
    }

    public int getMonth() {
        return this.month;
    }

    public int getYear() {
        return this.year;
    }

    public void print() {
        System.out.println(this.day + " " + getMonthForPrint() + " " + this.year + " року");
    }

    private String getMonthForPrint() {
        String month = switch (this.month) {
            case 1 -> "січня";
            case 2 -> "лютого";
            case 3 -> "березня";
            case 4 -> "квітня";
            case 5 -> "травня";
            case 6 -> "червня";
            case 7 -> "липня";
            case 8 -> "серпня";
            case 9 -> "вересня";
            case 10 -> "жовтня";
            case 11 -> "листопада";
            case 12 -> "грудня";
            default -> "ERROR";
        };

        return month;
    }

    @Override
    public String toString() {
        return this.day + "." + this.month + "." + this.year;
    }
}

public class ListNode {
    public static void main(String[] args) {
        Date date = new Date(9, 12, 2006);

        date.print();

        System.out.println(date.toString());

        System.out.println(date.getMonth());
        System.out.println(date.getYear());
    }
}
