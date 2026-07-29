try:
    fname = input("파일 이름을 입력하세요: ")
    infile = open(fname, "r") 
except IOError as e:
    print(e)
