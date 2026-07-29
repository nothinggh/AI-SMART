class Counter:
    # 생성자 만들기
    def __init__(self,  initValue=0) :
       self.count = initValue # 변수선언

    def increment(self):
        self.count += 1

#사용
a=Counter(99)
a.increment()
print(a.count)
b=Counter()
print(b.count)