while True:
    num=int(input("몇 단 출력?: "))
    if (num==0 or num>9):
        print("종료")
        break
    j=1
    while num<=9:
        while j<=9:
            print(num,'*',j,'=',num*j)
            j+=1
        j=1
        num+=1
