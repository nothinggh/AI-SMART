infile = open("input.txt", "r")
ch = infile.read(1)

while ch != '':
    print(ch)
    ch=infile.read(1)

infile.close() #  클로즈를 없애고 싶으면 아래 참조


# 아래
# with open("input.txt", "r") as infile:
#     ch = infile.read(1)

#     while ch != "":
#         print(ch)
#         ch = infile.read(1)
