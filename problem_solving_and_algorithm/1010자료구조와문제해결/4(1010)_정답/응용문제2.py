# 응용문제2

'''
<요구사항>
• 채팅어플에서 친구를 등록하고, 친구를 이름으로 검색한 후 연락처를 출력하는 프로그램을 작성하시오.
1. 선택메뉴: 친구등록, 친구검색, 종료
2. 딕셔너리 자료 구조 사용
3. 찾는 친구가 있으면 연락처를 출력하고 없으면 에러 메시지를 출력한다.
'''

addr={}

while True:
    s=int(input('choice 1) 친구등록 2) 검색 3) 종료'))
    if s==1:
        name=input('name: ')
        phone=input('phone: ')
        addr[name]=phone
    elif s==2:
        name=input('name: ')
        if name in addr:
            print(addr[name])
        else:
            print('not Found')
        # print(addr.get(name,'not Found')
    elif s==3:
        print('end')
        break
    else:
        print('not choice')
    
        
