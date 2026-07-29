package basic2;

class A{
    public A(){
        System.out.println("생성자A");
    }
    public A(int x){
        System.out.println("매개변수 생성자A");
    }
}
class B extends A{
    public B(int x){
        super();
        // super(x);
        System.out.println("매개변수 생성자B "+x);
    }
}
public class ConstructorEx4 {
    public static void main(String[] args) {
        // B b = new B(5);
    }
}
