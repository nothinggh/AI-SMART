# 어떤 회사에서 리스트에 직원들의 월급을 저장하고 있다.
# 회사에서 일괄적으로 30%의 월급 인상을 하기로 하였다.
# 리스트의 모든 요소들을 30% 증가시키는 함수 modify()를
# 작성하고 테스트 해보자.

# a=200
# b=250
# c=300
# d=280
# e=500

# print((a*1.3),(b*1.3),(c*1.3),(d*1.3),(e*1.3))

def modify(list):
    salary2 = []
    for i in list:
        salary2.append(i * 1.3)
        
        return salary2
        
       
salary = [200, 250, 300, 280, 500]
print("인상전", salary)
print("인상후", modify(salary))
