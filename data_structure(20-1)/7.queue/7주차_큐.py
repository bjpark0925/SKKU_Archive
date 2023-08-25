#함수 정의 및 선언

def UserSetting():#사용자에게 프로그램 사용법을 표시해주는 함수
    print("사용자는 다음의 명령어를 사용할 수 있습니다.")
    print()
    print("I(대문자 i) : enqueue 명령(+enqueue할 요소)")
    print("L : 큐 전체 출력")
    print("P : head 위치의 요소 peek(보기)")
    print("- : head 위치의 요소 하나만 dequeue 명령(dequeue 후 자동적으로 앞으로 정렬됨)")
    print("-5 : head 위치의 요소부터 5개까지 dequeue(5가 아니어도 됨)")
    print("F : 큐가 꽉 찼는지 여부")
    print("# : 큐 요소 개수 확인")
    print("H : head의 현재 위치 출력")
    print("T : tail의 현재 위치 출력")
    print("E : 빈 큐 여부")
    print("?a : 큐에 요소가 있는지 여부(a가 아니어도 됨)")
    print("=a : tail 위치에 있는 요소를 사용자가 입력한 요소로 변경(a가 아니어도 됨)")
    print("C : 큐 비우기(요소들 보여주면서 비워짐)")
    print("Q : 프로그램 종료")
    print()
    print("밑의 3개는 자신만의 기능")
    print("S : 앞으로 정렬(앞에 빈 자리가 없도록 요소들을 이동)")
    print("Z : tail 뒤에 남은 자리가 얼마인지 출력")
    print("R : 큐의 순서를반대로 해서 출력(큐의 상태는 그대로)")
    print()
    print("PrintAll 함수와 is_member 함수에서 head를 원래대로 하는 연산을 수정했습니다.")
    print()

def Setposition():#첫 현재 위치 설정
    return -1

def DataCount(head, tail):#큐 요소 개수
    return tail-head

def Shift(array,head,tail):#앞으로 정렬
    if head==-1:#이미 앞으로 정렬된 상태이면 그대로 반환
        return
    
    else:
        frontlen=head+1#head 앞에 남은 자리의 개수
        i=0
        while head!=tail:#요소들을 모두 앞으로 당김
            head+=1
            array[i]=array[head]
            del array[head]
            i+=1

        head=Setposition()#head와 tail 위치 재설정
        tail-=frontlen

def Enqueue(array,tail):#enqueue 함수
    temp=input("abcd의 형식으로 삽입할 요소를 입력하세요: ")
    enlen=len(temp)#사용자가 넣고 싶은 요소의 개수(ex.abcd면 4개)
    remainlen=Max_Size-tail-2#큐에 남은 자리의 총 개수

    if (enlen>remainlen):#enlen보다 remainlen이 부족할 때
        print("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다."%remainlen)
            
    else:#큐에 자리가 넉넉할 때
        for i in range(enlen):
            array.append(temp[i])

        tail+=enlen

    return tail

def is_empty(head,tail):#큐가 비었는지
    if head==tail:
        return True
    else:
        return False

def PrintAll(array,head,tail):#현재 배열 상황을 출력해주는 함수

    temp=[]
    
    if is_empty(head,tail)==True:#큐가 비었으면
        print("출력할 것이 없음")
        
    else:#큐에 저장된 것이 있으면
        head+=1
        while head!=(tail+1):
            print(array[head],end='')#head요소를 dequeue하고
            temp.append(array[head])#temp에 저장
            del array[head]
            tail-=1
        print()

        #이후 temp에 넣어뒀던 것들을 다시 큐에 넣음
        #enqueue의 과정과 동일

        enlen=len(temp)#사용자가 넣고 싶은 요소의 개수(ex.abcd면 4개)
        remainlen=Max_Size-tail-2#큐에 남은 자리의 총 개수

        if (enlen>remainlen):#enlen보다 remainlen이 부족할 때
            print("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다."%remainlen)
            
        else:#큐에 자리가 넉넉할 때
            for i in range(enlen):
                array.append(temp[i])

            tail+=enlen

    return tail

def Peek(array,head,tail):#peek 함수
    if is_empty(head,tail)==True:#큐가 비었으면
        print("출력할 것이 없음")
    else:
        savehead=head
        head+=1
        print(array[head])
        head=savehead

def Dequeue(array,order,head,tail):#dequeue 함수(c와는 달리, python은 요소들이 계속해서 앞으로 정렬되는 것을 이용)
    if len(order)!=1:#-숫자 형태로 입력받은 경우
        if order[1].isdigit()==True:#-이후 사용자가 정수를 입력한 경우
            num=int(order[1])
            if num>DataCount(head,tail):
                print("입력한 숫자가 큐에 있는 요소 개수보다 많습니다. 다시 입력하세요",end='')
            else:
                for i in range(num):
                    savehead=head
                    head+=1
                    print(array[head],end='')#peek하고
                    del array[head]#삭제
                    head=savehead
                    tail-=1
                    
    else:#-만 입력받은 경우
        if is_empty(head,tail)==True:#큐가 비었으면
            print("dequeue할 것이 없음",end='')
        else:#큐에 저장된 것이 있는 경우
            savehead=head
            head+=1
            print(array[head],end='')
            del array[head]
            head=savehead
            tail-=1

    return tail

def is_full(tail):#큐가 가득찼는지
    if tail==Max_Size-2:
        return True
    else:
        return False

def Head(head):#head
    return head

def Tail(tail):#tail
    return tail

def is_member(array,order,head,tail):#큐에 요소가 있는지 여부
    temp=[]
    
    if is_empty(head,tail)==1:#큐가 비어있으면
        print("False")
        
    else:
        head+=1
        while head!=(tail+1):
            if array[head]==order[1]:#요소를 찾으면
                print("True")
            temp.append(array[head])#temp에 저장
            del array[head]
            tail-=1

        #이후 temp에 넣어뒀던 것들을 다시 큐에 넣음
        #enqueue의 과정과 동일

        enlen=len(temp)#사용자가 넣고 싶은 요소의 개수(ex.abcd면 4개)
        remainlen=Max_Size-tail-2#큐에 남은 자리의 총 개수

        if (enlen>remainlen):#enlen보다 remainlen이 부족할 때
            print("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다."%remainlen)
            
        else:#큐에 자리가 넉넉할 때
            for i in range(enlen):
                array.append(temp[i])

            tail+=enlen

    return tail

def Replace(array,order,head,tail):#변경
    if is_empty(head,tail)!=1:
        array[tail]=order[1]

def Clear(array,order,head,tail):#비우기
    while head!=tail:
        tail=Dequeue(array,order,head,tail)#처음부터 끝까지 dequeue

    print()
    return tail

def Rearlen(tail):#tail 뒤에 남은 자리가 얼마인지 출력
    return Max_Size-tail-2

def Reverse(array,head,tail):#큐의 순서를 반대로 해서 출력
    if is_empty(head,tail)==1:
        print("뒤집을 것이 없음")
    else:
        temp=[]
        savehead=head
        while head!=tail:
            head+=1
            temp.append(array[head])#큐의 요소들을 temp에 저장
        head=savehead

        for i in range(len(temp)//2):#temp를 거꾸로
            temp[i],temp[len(temp)-1-i]=temp[len(temp)-1-i],temp[i]

        for i in range(len(temp)):
            print(temp[i],end='')
        print()
            
#메인 함수
array=[]#배열을 하나 생성함

#첫 head와 tail 설정
head=Setposition()
tail=Setposition()

UserSetting()#프로그램 사용법 출력

Max_Size=100#임의로 Max_Size 설정

while(True):#Q명령 시 종료하고, 그 이외에는 프로그램이 계속 실행될 수 있도록 while문 사용
    order=input("명령어를 입력하세요: ")#사용자에게 명령어를 받음
    
    if (order=='Q'):#프로그램을 종료하는 명령어
        print("프로그램을 종료합니다.")
        break

    if (order=='I'):#enqueue
        tail=Enqueue(array,tail)
        
    if (order=='L'):#현재 배열 출력
        tail=PrintAll(array,head,tail)

    if (order=='P'):#peek
        Peek(array,head,tail)

    if (order[0]=='-'):#dequeue
        tail=Dequeue(array,order,head,tail)
        print()

    if (order=='F'):#is_full
        print(is_full(tail))

    if (order=='#'):#개수 확인
        print(DataCount(head,tail))

    if (order=='H'):#head 현재 위치
        print(Head(head))

    if (order=='T'):#tail 현재 위치
        print(Tail(tail))

    if (order=='E'):#빈 큐 여부
        print(is_empty(head,tail))

    if (order[0]=='?'):#is_member
        tail=is_member(array,order,head,tail)

    if (order[0]=='='):#replace
        Replace(array,order,head,tail)

    if (order=='C'):#clear
        tail=Clear(array,order,head,tail)

    if (order=='S'):#shift
        Shift(array,head,tail)

    if (order=='Z'):#rearlen
        print(Rearlen(tail))

    if (order=='R'):#reverse
        Reverse(array,head,tail)
