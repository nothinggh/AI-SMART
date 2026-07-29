class Person {
    public String name;
    public String id;

    public Person(String name) {
        this.name = name;
    }

}

class Student extends Person {
    public Student(String name) {
        super(name);

    }

}

public class UpDown {
    public static void main(String[] args) {
        Person p; // 레퍼런스
        Student s = new Student("이재문");
        p=s; // 업캐스팅
        Person p2 = new Student("홍길동");

        System.out.println("p.name :"+p.name);
        System.out.println("p2.name :"+p2.name);
    }
}
