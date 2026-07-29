
class Point {
    // 멤버 변수
    private int x;
    private int y;

    // 기본 생성자
    public Point() {
    }

    // 좌표를 받는 생성자 추가
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}

class ColorPoint extends Point {
    // 필드는 private으로 캡슐화
    private String color;

    // x, y, color를 인자로 받는 생성자 추가
    public ColorPoint(int x, int y, String color) {
        super(x, y); // 부모 클래스(Point)의 생성자 호출
        this.color = color;
    }

    // getColor() 메서드 추가
    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
}
// class SuperColorPoint extends ColorPoint{
// private String tick;


public class ColorPointTest {
    public static void main(String[] args) {
        // 올바른 인스턴스 생성
        ColorPoint cp = new ColorPoint(3, 3, "빨간색");
        System.out.println("X좌표:" + cp.getX() + " Y좌표:" + cp.getY());
        System.out.println("색상:" + cp.getColor());
    }
}