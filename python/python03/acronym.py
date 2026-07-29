# 머리 글자어(acronym)은 NATO(North Atlantic Treaty Organization)
# 처럼 각 단어의 첫글자를 모아서 만든 문자열이다.
# 사용자가 문장을 입력하면 해당되는 머리 글자어를
# 출력하는 프로그램을 작성하여 보자.

sentence = input("문장을 입력하세요: ")

result = ""
for word in sentence.split():
    result += word[0].upper()

print("머리 글자어:", result)