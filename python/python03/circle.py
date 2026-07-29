import math

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def getArea(self):
        return math.pi * self.radius ** 2

    def getPrimeter(self):
        return 2 * math.pi * self.radius


if __name__ == "__main__":
    c = Circle(10)
    print("반지름:", c.radius)
    print("넓이:", c.getArea())
    print("둘레:", c.getPrimeter())
