package basic1;
import java.util.Scanner;

public class RectArea {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("width를 입력하세요 : ");
        int width = sc.nextInt();
        System.out.print("hegiht를 입력하세요 : ");
        int height = sc.nextInt();
        int area = width * height;
        System.out.println("Area = " + area);

        sc.close();
        // Scanner처럼 사용자 입력을 받을 때는
        // close() 닫아주지 않으면 메모리가 낭비가 된다.
    }
}