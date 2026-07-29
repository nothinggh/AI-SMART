package basic1;

public class TypeConversion {
    public static void main(String[] args) {
        // int n = 300;
        // byte b = (byte) n; // 데어티 형변환(데이터 손실발생)

        // n = b; // 묵시적인 형변환

        byte b =127;
        int i = 100;

        System.out.println(b+i);
        System.out.println(10/4);
        System.out.println((char)0x12340041);
        System.out.println((int)0x12340041);
        System.out.println((byte)(b+i));
        System.out.println((int)2.9+1.8);

    }
}
