#함수 정의 및 선언

def UserSetting():#사용자에게 프로그램 사용법을 표시해주는 함수
    print("사용자는 다음의 명령어를 사용할 수 있습니다.")
    print()
    print("I(대문자 i) : 삽입 명령(+삽입할 요소)")
    print("L : 스택 전체 출력")
    print("P : top 위치의 요소 peek(보기)")
    print("- : top 위치의 요소 하나만 pop(꺼내기)")
    print("F : 스택이 꽉 찼는지 여부")
    print("# : 스택 요소 개수 확인")
    print("T : top 위치의 요소 출력")
    print("? : 스택에 요소가 있는지 여부")
    print("= : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경")
    print("C : 스택 비우기(요소들 보여주면서 비워짐)")
    print("Q : 프로그램 종료")
    print()
    print("밑의 3개는 자신만의 기능")
    print("E : 빈 스택 여부")
    print("SW : top과 top-1요소를 swap")
    print("R : 스택의 순서를 top부터 reverse해서 출력")
    print()

def Setposition():#첫 현재 위치 설정
    return -1

def Push(array, top):
    data=input("abcd의 형식으로 삽입할 요소를 입력하세요: ")
    len_data=len(data)

    remain_len=Max_Size-top-2#스택에 남은 자리의 개수

    if (len_data>remain_len):
        print("스택에 남은 자리가 부족합니다. 남은 자리는 %d개입니다."%remain_len)
    else:
        for i in range(len_data):
            array.append(data[i])

        top+=len(data)
        
    return top

def PrintAll(array,top):#현재 배열 상황을 출력해주는 함수
    if top==-1:
        print("출력할 것이 없음")
    else:
        savetop=top#원래의 top위치 저장
        temp=[]#array의 순서와는 반대로 저장하는 배열 temp 생성
        
        for i in range(savetop+1):
            temp.append(array[top])
            del array[top]
            top-=1
        top=savetop#top을 다시 원래 위치로 업데이트

        print("현재 배열 상황: ",end='')
        for i in range(savetop+1):
            array.append(temp[top-i])
            print(array[i], end='')
        print()

def Peek(array,top):#peek 함수
    if top==-1:
        print("출력할 것이 없음")
    else:
        print(array[top])

def Pop(array,top):#pop 함수
    if top==-1:
        print("pop할 것이 없음")
    else:
        Peek(array,top)#peek하고
        del array[top]#삭제
        top-=1#top위치 변경

    return top

def is_full(array,top):#스택 가득 찼는지 여부 함수
    if (top==Max_Size-2):
        print("가득 참")
    else:
        print("가득 차있지 않음")

def element_count(top):#스택 요소 개수 확인 함수
    print(top+1)

def Top(array,top):#top 위치의 요소 출력 함수
    if top==-1:
        print("top 위치에 요소가 없음")
    else:
        print("({0}, {1})".format(top+1,array[top]))

def is_member(array,top):#스택에 요소가 있는지 여부 함수
    order=input("찾을 문자 입력: ")
    
    if top==-1:
        print("False")
    
    else:
        temp=[]
        exist=False#요소 존재 여부 확인하는 변수
        savetop=top#원래의 top위치 저장
        
        for i in range(savetop+1):#temp는 array와 반대로 저장, 저장과 동시에 search하기
            temp.append(array[top])

            if (temp[i]==order):
                exist=True

            del array[top]
            top-=1

        if exist==True:
            print("True")
        else:
            print("False")

        top=savetop#top을 다시 원래의 위치로 업데이트

        for i in range(savetop+1):#temp에 저장한 것을 다시 array로
            array.append(temp[top-i])

def Replace(array,top):#top 요소 변경 함수
    order=input("변경할 요소 입력: ")

    if (top!=-1):
        array[top]=order

def Clear(array,top):#스택 비우기 함수
    savetop=top

    for i in range(savetop+1):
        top=Pop(array,top)

    return top

def is_empty(top):#빈 스택 여부 함수
    if top==-1:
        print("True(스택이 비어있음)")
    else:
        print("False(스택이 비어있지 않음)")

def Swap(array,top):#top과 top-1요소를 swap 후 출력 함수
    savetop=top

    if (top<1):
        print("swap할 요소가 부족함")

    else:
        temp1=[]
        temp2=[]
        
        temp1.append(array[top])
        del array[top]
        top-=1

        temp2.append(array[top])
        del array[top]
        top-=1

        array.append(temp1[0])
        top+=1
        array.append(temp2[0])
        top+=1

        PrintAll(array,top)

def ReverseStack(array,top):#뒤집고 출력 함수
    savetop=top

    if top==-1:
        print("뒤집을 것이 없음")

    else:
        temp=[]
        for i in range(savetop+1):#array의 top요소가 temp로 넘어감
            temp.append(array[top])
            print(array[top],end='')
            del array[top]
            top-=1
        top=savetop#top을 다시 원래의 위치로 업데이트

        for i in range(savetop+1):#temp에서 다시 array로 저장
            array.append(temp[top-i])
        print()

#메인 함수
array=[]#배열을 하나 생성함

UserSetting()#프로그램 사용법 출력

top=Setposition()#첫 top 위치 설정
Max_Size=100#임의로 Max_Size 설정

while(True):#Q명령 시 종료하고, 그 이외에는 프로그램이 계속 실행될 수 있도록 while문 사용
    order=input("명령어를 입력하세요: ")#사용자에게 명령어를 받음
    
    if (order=='Q'):#프로그램을 종료하는 명령어
        print("프로그램을 종료합니다.")
        break

    if (order=='I'):#삽입 명령(+삽입할 요소)
        top=Push(array,top)
        
    if (order=='L'):#현재 배열 출력
        PrintAll(array,top)

    if (order=='P'):#peek
        Peek(array,top)

    if (order=='-'):#pop
        top=Pop(array,top)

    if (order=='F'):#is_full
        is_full(array,top)

    if (order=='#'):#개수 확인
        element_count(top)

    if (order=='T'):#Top
        Top(array,top)

    if (order=='?'):#찾기
        is_member(array,top)

    if (order=='='):#replace
        Replace(array,top)

    if (order=='C'):#clear
        top=Clear(array,top)

    if (order=='E'):#is_empty
        is_empty(top)

    if (order=="SW"):#swap
        Swap(array,top)

    if (order=='R'):#reverse
        ReverseStack(array,top)
