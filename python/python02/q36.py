# 다음 문자열 리스트에서 길이가 5글자 이상인 문자열만
# 대문자로 변환하여 새로운 리스트를 만드시오.
# words = [ "python", "sql", "ai", "streamlit", "db", "factory" ]

words = [ "python", "sql", "ai", "streamlit", "db", "factory" ]

for words in words:
    if len(words) >= 5:
        print(words.upper())