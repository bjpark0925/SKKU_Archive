def fibo(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

while True:
    num=int(input("몇번째 항?: "))
    if num==0:
        print("종료")
        break
    print('F(',num,') =', fibo(num))
