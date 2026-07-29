package basic3;

class Person {
    public String name;

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
        // 업캐스팅(UpCasting)
        // Person person = new Student("홍길동");
        // 다운캐스팅(DownCasting)
        // Student s = (Student) person;

    }
}
