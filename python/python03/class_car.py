class Car:
    def __init__(self):
        self.brand='차'
        self.speed=0

        #메소드
    def brand_print(self):
            print('지금 차의 브랜드는 =', self.brand)
    def speed_print(self):
            print('현재 차의 속도는 =', self.speed)

# main 객체 마을 -> 시간이 흐른다.
my_car=Car() # 생성자를 사용하면 객체가 탄생한다.

my_car.brand = 'BMW' # 생성 후 초기화
my_car.speed = 150   # 생성 후 초기화

my_car.brand_print()
my_car.speed_print()
    