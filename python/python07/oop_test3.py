# 1. getter, setter를 만들고
# 2. property 방식으로 처래해 보아라.

class Car:
    def __init__(self, brand):
        self._brand = brand

    @property
    def brand(self):
        return self._brand

    @brand.setter
    def brand(self, brand):
        self._brand = brand

if __name__=='__main__':
    car = Car('차')
    print(car.brand)
    car.brand = '현대'
    print(car.brand)