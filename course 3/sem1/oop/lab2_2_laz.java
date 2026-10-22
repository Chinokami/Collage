import java.util.Arrays;

public class TextCipher {

    public static void main(String[] args) {
        String[] lines = {
            "Java",
            "Code",
            "Bitwise",
            "Cipher",
            "Text",
            "777",
            "A",
            "88888888"
        };

        String[] paddedLines = normalizeLines(lines);
        short[][] encrypted = encrypt(paddedLines);

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                System.out.printf("0x%04X ", encrypted[row][col] & 0xFFFF);
            }
            System.out.println();
        }
    }

    public static String[] normalizeLines(String[] input) {
        String[] result = new String[8];
        for (int i = 0; i < 8; i++) {
            String str = (i < input.length) ? input[i] : "";
            if (str.length() > 8) {
                str = str.substring(0, 8);
            }
            result[i] = String.format("%-8s", str);
        }
        return result;
    }

    public static short[][] encrypt(String[] lines) {
        short[][] result = new short[8][8];

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                char ch = lines[row].charAt(col);
                result[row][col] = encodeChar(ch, row, col);
            }
        }
        return result;
    }

    public static short encodeChar(char ch, int row, int col) {
        int ascii = ch & 0xFF;

        int rowBits = row & 0x07;
        int asciiLow = ascii & 0x0F;

        int firstByteValue = rowBits | (asciiLow << 3);
        int parity1 = calculateParity(firstByteValue);

        int byte0 = firstByteValue | (parity1 << 7);

        int asciiHigh = (ascii >> 4) & 0x0F;
        int colBits = col & 0x07;

        int secondByteValue = asciiHigh | (colBits << 4);
        int parity2 = calculateParity(secondByteValue);

        int byte1 = secondByteValue | (parity2 << 3);

        int word = byte0 | (byte1 << 8);

        return (short) word;
    }

    private static int calculateParity(int value) {
        int countOnes = Integer.bitCount(value);
        return (countOnes % 2 == 0) ? 1 : 0;
    }

    public static char decryptChar(short cipher) {
        int val = cipher & 0xFFFF;
        int asciiLow = (val >> 3) & 0x0F;
        int asciiHigh = (val >> 8) & 0x0F;
        return (char) ((asciiHigh << 4) | asciiLow);
    }
}
