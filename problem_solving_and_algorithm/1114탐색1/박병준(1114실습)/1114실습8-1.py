#실습 8-1
#20191114 1112

#메뉴 함수정의
def menu():
    print()
    print('Frineds and telephone')

    print('='*30)
    print('1. Look up a telephone')
    print('2. Add a  new telephone')
    print('3. Delete a telephone')
    print('4. All telephone')
    print('5. Quit the program')
    print('='*30)

#메인코드
menu()
addr={} #딕셔너리 선언

while True:
    choice=int(input('Enter your choice: '))

    if choice==1: #1번 검색기능
        name=input('Enter a name: ')
        print(addr.get(name, 'not Found')) #name이 없으면 not Found 메시지 출력

    if choice==2: #2번 추가기능
        name=input('Enter a name: ')
        if name in addr:
            print("already exists")
        else:
            tel=input("Enter a telephone: ")
            addr[name]=tel

    if choice==3: #3번 삭제기능
        name=input("Enter a name: ")
        if name in addr:
            del addr[name] # name이 addr에 있으면 그 name과 tel 삭제
        else:
            print("not Found")

    if choice==4: #4번 전체검색기능
        print(addr)
    if choice==5:
        print("the End")
        break
