def treeful_add(a, b, c):  # 기본 함수 형태
    return a + b + c

def treeful_add2(*number):  # 가변 인수 형태
    sum = 0
    for n in number:
        sum += n
        return sum

if __name__ == "__main__": # 메인 함수

    print(treeful_add(3, 4, 5))
    print(treeful_add2(10, 20, 30))
