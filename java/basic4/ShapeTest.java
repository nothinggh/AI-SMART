abstract class Shape {
    abstract public void draw();

}
class Circle extends Shape{

    @Override
    public void draw() {
        System.out.println("Circle을 그립니다.");
        
    }
    
}
class Rect extends Shape {

    @Override
    public void draw() {
        System.out.println("Rect를 그립니다.");
        
    }
    
}

public class ShapeTest{
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.draw();

        Rect rect = new Rect();
        rect.draw();

        System.out.println("--------------------");

        Shape[] shapes = new Shape[2];
        shapes[0] = new Circle();
        shapes[1] = new Rect();

        for (Shape s : shapes) {
            s.draw();
      }
    }
}