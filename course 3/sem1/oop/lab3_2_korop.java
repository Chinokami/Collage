import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        File[] files = new File[3];

        files[0] = new File();
        files[1] = new File();
        files[2] = new File();

        files[0].set("bTest", 50, "2026-10-01");
        files[1].set("aTest2", 100, "2026-10-01");
        files[2].set("Test3", 125, "2026-10-01");

        showByAlphabet(files);
        sizeMoreThen(files, 99);
        requestsMoreThen(files, 0);
    }

    public static void showByAlphabet(File[] arr) {
        Arrays.sort(arr, Comparator.comparing(File::getName));

        for (File i : arr) {
            i.show();
        }
    }

    public static void sizeMoreThen(File[] arr, int size) {
        for (File i : arr) {
            if (i.getSize() > size) {
                i.show();
            }
        }
    }

    public static void requestsMoreThen(File[] arr, int number) {
        for (File i : arr) {
            if (i.getRequests() > number) {
                i.show();
            }
        }
    }
}

class File {
    private String name;
    private int size;
    private String date;
    private int requests = 0;

    public void set(String name, int size, String date) {
        this.name = name;
        this.size = size;
        this.date = date;
    }

    public String getName() {
        this.requests++;
        return this.name;
    }

    public int getSize() {
        this.requests++;
        return this.size;
    }

    public String getDate() {
        this.requests++;
        return this.date;
    }

    public int getRequests() {
        this.requests++;
        return this.requests;
    }

    public void show() {
        System.out.println("Name: " + name);
        System.out.println("Size: " + size + "MB");
        System.out.println("Date: " + date);
        System.out.println("Requests: " + requests + "\n");
    }
}
