class Car:
    def __init__(self, make, model, color, price):
        self.make = make
        self.model = model
        self.color = color
        self. price = price
    
    def my_print(self):
        print(self.make)
    

class ElectricCar(Car):
    def __init__(self, make, model, color, price, batterySize):
        super().__init__(make, model, color, price)
        self.batterySize = batterySize

def main():
    # 메인함수 코딩
    my_car = ElectricCar("Tesla", 'Model S', 'White', 10000, 0)
    my_car.my_print()

main()
  


