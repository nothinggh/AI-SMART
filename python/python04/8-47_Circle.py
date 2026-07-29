class Circle:
	def __init__(self, radius):
		self.radius = radius

    def __eq__(self, other):
		if not isinstance(other, Circle):
			return NotImplemented
		return self.radius == other.radius


c1 = Circle(10)
c2 = Circle(10)

if c1 == c2:
	print("원의 반지름은 동일합니다. ")
else:
	print("원의 반지름은 동일하지 않습니다.")
