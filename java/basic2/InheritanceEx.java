package basic2;

class Person {

    private int weight;

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }
}

class Student extends Person {

    public Student() {
        System.out.println("학생 객체 생성");
    }
}

public class InheritanceEx {

    public static void main(String[] args) {

        Student gildong = new Student();

        gildong.setWeight(70);

        System.out.println("길동의 몸무게는 "
                + gildong.getWeight()
                + "kg입니다");
    }
}