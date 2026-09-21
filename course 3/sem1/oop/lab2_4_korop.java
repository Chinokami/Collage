import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String str = scan.nextLine().toUpperCase();

        for (int i = 0; i < str.length(); i++) {
            System.out.print(getMorseCode(str.charAt(i)) + " ");
        }
    }

    private static String getMorseCode(char c) {
           return switch (c) {
               case 'А' -> ".-";    case 'Б' -> "-...";  case 'В' -> ".--";   case 'Г' -> "--.";
               case 'Д' -> "-..";   case 'Е', 'Ё' -> ".";case 'Ж' -> "...-";  case 'З' -> "--..";
               case 'И' -> "..";    case 'Й' -> ".---";  case 'К' -> "-.-";   case 'Л' -> ".-..";
               case 'М' -> "--";    case 'Н' -> "-.";    case 'О' -> "---";   case 'П' -> ".--.";
               case 'Р' -> ".-.";   case 'С' -> "...";   case 'Т' -> "-";     case 'У' -> "..-";
               case 'Ф' -> "..-.";  case 'Х' -> "....";  case 'Ц' -> "-.-.";  case 'Ч' -> "---.";
               case 'Ш' -> "----";  case 'Щ' -> "--.-";  case 'Ъ' -> "--.--"; case 'Ы' -> "-.--";
               case 'Ь' -> "-..-";  case 'Э' -> "..-.."; case 'Ю' -> "..--";  case 'Я' -> ".-.-";

               case '1' -> ".----"; case '2' -> "..---"; case '3' -> "...--"; case '4' -> "....-";
               case '5' -> "....."; case '6' -> "-...."; case '7' -> "--..."; case '8' -> "---..";
               case '9' -> "----."; case '0' -> "-----";

               case ' ' -> "   ";
               default -> "";
           };
       }
}
