import random

x=random.randrange(0,101)
y=random.randrange(0,101)
answer=0

while (x+y) !=answer:
    answer=int(input(str(x)+"+"+str(y)+"의 값은?"))

    if x+y==answer:
        print("ㅇㅋ")
    else:
        print("ㄴㄴ")
