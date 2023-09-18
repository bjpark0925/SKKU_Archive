def my_deposit(amonut):
    global total_amount
    print("내가 %d원 저축합니다."%amount)
    total_amount=total_amount+amount

def bro_deposit(amount):
    global total_amount
    print("동생이 %d원 저축합니다."%amount)
    total_amount=total_amount+amount

total_amount=0

while total_amount<100000:
    who=input("I/bro")
    amount=int(input("저축하는 액수 입력: "))
    if who=='I':
        my_deposit(amount)
    elif who=='bro':
        bro_deposit(amount)
    else:
        print("사람을 잘못 입력함")
    print("현재까지 액수: %d원"%total_amount)

print("다 채움!!!")
