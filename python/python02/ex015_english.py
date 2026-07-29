english_dict = {}
korea_dict = {}

english_dict["one"] = "하나"
english_dict["two"] = "둘"
english_dict["three"] = "셋"
korea_dict["하나"] = "one"
korea_dict["둘"] = "two"
korea_dict["셋"] = "three"

word = input("단어를 입력하세요:")

result = korea_dict.get(word) or english_dict.get(word) or "사전에 없는 단어입니다."

print(result)