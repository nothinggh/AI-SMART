# 0부터 99까지의 정수 중에서 2의 배수이고 동시에 3의 배수인
# 수들을 모아서 리스트로 만들어보자.

# num=[0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 96]

# for i in range(0,100,2):
#  print(i)

#  for j in range(0,100,3):
#   print(j)


result = [i for i in range(100) if i % 2 == 0 and i % 3 == 0]

print(result)