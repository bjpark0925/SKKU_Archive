import random

com=random.randrange(1,4)
if com==1:
    com='가위'
elif com==2:
    com='바위'
else:
    com='보'

name=input("이름을 입력하세요: ")
player=input("가위바위보중 %s의 선택은?: "%name)

print("컴퓨터의 선택은 %s입니다."%com)
if player=='가위':
    if com=='가위':
        print("무승부")
    elif com=='바위':
        print('패')
    elif com=='보':
        print( "승")
elif player=='바위':
    if com=='가위':
        print("승")
    elif com=='바위':
        print('무')
    elif com=='보':
        print(name, "패")
elif player=='보':
    if com=='가위':
        print("패")
    elif com=='바위':
        print('승')
    elif com=='보':
        print("무")
