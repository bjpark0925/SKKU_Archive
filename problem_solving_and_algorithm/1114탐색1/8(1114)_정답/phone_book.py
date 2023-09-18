# 메뉴 함수정의
def menu():
    print()
    print('Friends and telephone')

    print('='*30)
    print('1. Look up a telephone')
    print('2. Add a new telephone')
    print('3. Delete a telephone')
    print('4. All telephone')
    print('5. Quit the program')
    print('='*30)

# 메인코드
menu()
addr={} # 

while True:
    choice = int(input('Enter your choice: '))

    if choice==1: #
        name=input('Enter a name: ')
        print(addr.get(name,'Not found')) #

    if choice==2: #
       name=input("Enter a name:")
       if name in addr:
            print("already exists")
       else:
           tel=input("Enter a telephone:")
           addr[name]=tel
    if choice==3: #
        name=input("Enter a name:")
        if name in addr:
            del(addr[name]) #
        else:
            print("not Found")

    if choice==4: #
        print(addr)
    if choice==5: 
         print("the End")
         break
    
