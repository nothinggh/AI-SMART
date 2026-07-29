def add(*numbers):
    sum=0
    for n in numbers:
        sum+=n
    return sum

print(add(10,20,30))
print(add(10,20,30,40,50,60))
