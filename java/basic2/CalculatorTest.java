package basic2;
import java.util.Scanner;

public class CalculatorTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("입력 : ");
        int value = sc.nextInt();
        System.out.println("입력 받은 정수 값은 : " + value);

        sc.close();

    }
}