interface Flyable {
    public void fly(); // abstract method 처럼 동작
}

class Horse{
    public void run(){};
}
class Bird{
    public void fly(){};
}
class Unicorn extends Horse implements Flyable{
    @Override
    public void fly() {
      System.out.println("날다.");
        
    }
    
}

public class FlyTest {
    public static void main(String[] args) {
        Unicorn unicorn = new Unicorn();
        unicorn.fly();
    }
}
