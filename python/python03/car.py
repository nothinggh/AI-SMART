class Car:
    def __init__(self, speed, color, model,year, price):
        self.speed=speed
        self.color=color
        self.model=model
        self.year=year
        self.price=price
	
    # 멤버 메소드
    def drive(self):
        self.speed=100
        print('자동차의 속도는', self.speed)

myCar=Car(0,"blue","e-class",2026,500)
print('자동차 연식:',myCar.year)
print('자동차 가격:',myCar.price)

myCar.drive()