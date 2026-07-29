
aa = 'A picture is worth a thousand words'

# letters = sum(1 for ch in text if ch.isalpha())
# digits = sum(1 for ch in text if ch.isdigit())
# spaces = sum(1 for ch in text if ch.isspace())

# print('letters:', letters)
# print('digits:', digits)
# print('spaces:', spaces)


dic = {'알파벳': 0, '숫자':0, '공백':0}

for i in aa:
    if i.isalpha():
        dic['알파벳']+=1
        if i.isdigit():
            dic['숫자']+=1
            if i.isspace():
                dic['공백']+=1
print(dic)
