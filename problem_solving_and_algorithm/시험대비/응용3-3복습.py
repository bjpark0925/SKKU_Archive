idee=input("아이디 입력: ")
password=int(input("비번: "))

if idee=='skku':
    if password==1234:
        print("성공!")
    else:
        print("비번만 틀림")
else:
    if password==1234:
        print("아이디만 틀림")
    else:
        print("다 틀림")
