num=int(input("세자리 정수 입력: "))

ten=num//10
one=num%10

hun=ten//10
ten=ten%10

print("100의 자리 수 숫자 : %d\n 10의 자리수 숫자 : %d\n 1의 자리수 숫자 : %d"%(hun, ten, one))
