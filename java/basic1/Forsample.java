package basic1;
public class Forsample {
    public static void main(String[] args) {
        int sum=0;

        for(int i=1; i<=10; i++){
            sum += i;
            System.out.print(i);

            if(i<=9)
                System.out.print("+");
            else{
                System.out.print("=");
                System.out.print(sum);
            }
        
        } // end of for
    } // end of main
} // end of sample
