class Car:
    # 객체를 만들 때 첫 글자 대문자를 하는 이유는 개발자들의 약속이다.
    def __init__(self, brand="차", speed=0):
        self.brand = brand
        self.speed = speed

        # 메소드

    def brand_print(self):
        print("지금 차의 브랜드는 =", self.brand)

    def speed_print(self):
        print("현재 차의 속도는 =", self.speed)


# main 객체 마을 -> 시간이 흐른다.
my_car = Car("BMW", 200)  # 생성자를 사용하면 객체가 탄생한다.

# my_car.brand = 'BMW' # 생성 후 초기화
# my_car.speed = 150   # 생성 후 초기화

my_car.brand_print()
my_car.speed_print()
