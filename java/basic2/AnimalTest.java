package basic2;
// 디자인 패턴(중요)
class Animal {
    public String name;
    Animal() {
        this.name = "동물";
    }
    public void eat() {
        System.out.println("먹는다.");
    }
}
class Human extends Animal {
}
public class AnimalTest {
    public static void main(String[] args) {
        // 시간이 흐르는 객체
        Human hongGilDong = new Human();
        hongGilDong.eat();
        System.out.println(hongGilDong.name);
    }
}
