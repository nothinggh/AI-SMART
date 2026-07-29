class Counter:
    def __init__(self):      # 생성자 함수 __ 언더바 두번
        self.count = 0       # 멤버 변수
    def increment(self):     # 멤버 메소드(함수)
        self.count += 1

# 메인
cnt = Counter() # 객체 생성
cnt.increment() # 1 카운터 증가

print(cnt.count)
