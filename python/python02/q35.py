    #  1. 문제
    #     1~20 사이의 짝수 리스트 만들기
    #       [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
    #  2. 문제
    #     합격 여부를 알려주세요. (60점 이상 합격)
    #      scores = [55, 80, 43, 90, 72, 61]
    #     ['불합격', '합격', '불합격', '합격', '합격', '합격']
    #  3. 문제
    #    불량제품 찾아내기
    #    inspection = [0, 1, 0, 0, 1, 1, 0, 1]
    #    [2, 5, 6, 8]


# 1. 문제
# numbers=[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

# def is_even(n):
#     return n % 2 ==0
# result = list(filter(is_even, numbers))

# print(result)

# 2. 문제

# scores =[55, 80, 43, 90, 72, 61]

# result = ['합격' if i> 60 else '불합격' for i in scores]

# print(result)

# 3. 문제

# inspection = [0, 1, 0, 0, 1, 1, 0, 1]

# result = [i + 1 for i, val in enumerate(inspection) if val == 1]

# print(result)