import random
x=random.randint(0, 9) 
y=random.randint(0, 9) 

while True:     
    login=int(input("암호 입력: "))
    a=int(login/10)
    b=login%10
    if  a==x and b==y:
        print("성공")
        break
    else: 
        print("실패")
        continue
