# 원을 클래스로 표현해보자.
# 클래스 이름은 Circle로 하자.
# 원을 초기화하는 생성자는 만들어야 한다.
# 원은 반지름을 속성으로 가진다.
# 메소드로는 원의 넓이와 둘레를 반환하는
# getArea()와 getPrimeter()를 정의한다.
# 원의 면적 314.1592653589793
# 원의 둘레 62.83185307179586
import math

class Circle:
    def __init__(self, radius):      # 생성자 함수 __ 언더바 두번
        self.radius=radius
    def 면적(self):
        return round(math.pi*self.radius**2,2)
    def 둘레(self):
        return round(2*math.pi*self.radius,2)

# 메인
Circle = Circle(10)
print(Circle.면적())
print(Circle.둘레())