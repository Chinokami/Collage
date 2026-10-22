import java.nio.charset.StandardCharsets;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        String originalText = "Hello, World!";

        byte[] data = originalText.getBytes(StandardCharsets.UTF_8);

        System.out.println("Оригінальний текст: " + originalText);
        System.out.println("Оригінальні байти: " + Arrays.toString(data));

        encode(data);
        System.out.println("\nЗакодовані байти:   " + Arrays.toString(data));
        System.out.println("Закодований текст:  " + new String(data, StandardCharsets.UTF_8));

        encode(data);
        System.out.println("\nДекодовані байти:   " + Arrays.toString(data));
        System.out.println("Розшифрований текст: " + new String(data, StandardCharsets.UTF_8));
    }

    public static void encode(byte[] a) {
        for (int i = 0; i < a.length; i++) {
            int key = 255 - (i % 256);
            a[i] = (byte) (a[i] ^ key);
        }
    }
}
