temp = float(input("물의 온도를 입력: "))

if 0 < temp <= 100:
 print("물의 상태는 고체입니다.")
elif temp and temp > 100:
 print("물의 상태는 기체입니다.")
else:
 print("물의 상태는 고체입니다.")