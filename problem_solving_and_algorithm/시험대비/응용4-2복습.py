chat={}

while True:
    s=int(input("1번 친구등록, 2번 친구검색, 3번 종료: "))
    if s==1:
        friend=input("친구 이름 등록:")
        phone=int(input("친구 전화번호 등록:"))
        chat[friend]=phone
    elif s==2:
        c=input("찾고 싶은 친구의 이름 입력:")
        if c in chat.keys():
            print(c,chat[c])
        else:
            print("친구가 검색되지 않음")
    elif s==3:
        print('종료')
        break
    else:
        print("1~3의 숫자 다시 입력바람")
