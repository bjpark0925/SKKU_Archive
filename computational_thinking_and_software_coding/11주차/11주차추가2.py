import random

user_win=com_win=0

while True:
    choice=input("주사위 게임 Yes or No")
    if choice=='No':
        print("종료함")
        break
    user=random.randint(1,6)
    com=random.randint(1,6)

    if user>com:
        user_win+=1
        print("사용자: %d, 컴퓨터: %d, 사용자 승"%(user,com))
    elif user<com:
        com_win+=1
        print("사용자: %d, 컴퓨터: %d, 컴퓨터 승"%(user,com))
    else:
        print("사용자: %d, 컴퓨터: %d, 무승부"%(user,com))

print("사용자는 %d번, 컴퓨터는 %d번 이김"%(user_win,com_win))
