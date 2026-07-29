# 파이썬 상속자는 자식클래스(부모클래스)
# 생성자가 없으면 defalt 생성자는 자동으로 생성
# 부모 클래스 public, protected 매소드 표현 가능
# 부모와 동일한 함수 작성 시 오버라이딩

class Shape:
    def draw(self):
        print('도형을 그리다')

class Circle(Shape):
    def draw(self):
        print('원을 그리다')

if __name__=='__main__':
    circle = Circle()
    circle.draw()