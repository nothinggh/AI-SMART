# 변수명을 my_dict로 변경하는 것을 추천합니다.
my_dict = {'이름': '홍길동', '나이': 25, '직업': '개발자'}

print(my_dict['이름'])
print(my_dict['나이'])
print(my_dict['직업'])

print("--- key 출력 ---")
# 첫 번째 for문: key만 출력
for i in my_dict.keys():
    print(i)

print("--- value 출력 ---")
# 두 번째 for문: 들여쓰기를 앞으로 당겨서 별개로 실행
for j in my_dict.values():
    print(j)