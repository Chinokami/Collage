import java.util.*;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        Scanner scan = new Scanner(System.in);

        int number = rand.nextInt(900) + 100;
        String targetNumber = String.valueOf(number);

        while (true) {
            String guessNumber = scan.nextLine().trim();

            if (guessNumber.length() != 3 || !guessNumber.matches("\\d{3}")) {
                System.out.println("Введіть 3-х значне число!");
                continue;
            }

            int exactMatches = 0;
            int totalGuessed = 0;

            boolean[] exactUsed = new boolean[3];
            boolean[] totalUsed = new boolean[3];

            for (int i = 0; i < 3; i++) {
                if (guessNumber.charAt(i) == targetNumber.charAt(i)) {
                    exactMatches++;
                    totalGuessed++;
                    exactUsed[i] = true;
                    totalUsed[i] = true;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (!exactUsed[i]) {
                    for (int j = 0; j < 3; j++) {
                        if (!totalUsed[j] && guessNumber.charAt(i) == targetNumber.charAt(j)) {
                            totalGuessed++;
                            totalUsed[j] = true;
                            break;
                        }
                    }
                }
            }

            System.out.printf("Вгадано: %d. На своїх позиціях: %d\n", totalGuessed, exactMatches);
            if (exactMatches == 3) {
                System.out.println("!!! ВИ ВГАДАЛИ !!!");
                break;
            }
        }
    }
}
