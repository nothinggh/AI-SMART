import random

num = random.randint(1, 101)

while True:
    guess = int(input("1부터 100 사이의 숫자를 입력하세요: "))
    
    if guess == num:
        print("정답입니다!")
        break
    elif guess < num:
        print("Up")
    else:
        print("Down")

print(num)