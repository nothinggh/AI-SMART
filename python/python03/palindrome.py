# import sys
# import re

# def is_palindrome(s: str) -> bool:
#     # normalize: keep alphanumeric, lowercase
#     cleaned = re.sub(r'[^A-Za-z0-9]', '', s).lower()
#     return cleaned == cleaned[::-1]

# def main():
#     try:
#         s = input().rstrip('\n')
#     except EOFError:
#         return
#     print("YES" if is_palindrome(s) else "NO")

# if __name__ == '__main__':
#     main()

s = input("문자열을 입력하시오: ")

s1 = s[::-1] # 문자열을 거꾸로 만든다. 

if( s == s1 ):
        print("회문입니다.")
else:
        print("회문이 아닙니다.")
