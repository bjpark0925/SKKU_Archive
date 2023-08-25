#함수 정의 및 선언

def UserSetting():#사용자에게 프로그램 사용법을 표시해주는 함수
    print("사용자는 다음의 명령어를 사용할 수 있습니다.")
    print()
    print("I(대문자 i) : 삽입 명령(+삽입할 요소)")
    print("N : 현재 위치를 앞에서부터 변경(N의 개수는 마음대로)")
    print("P : 현재 위치를 뒤에서부터 변경(P의 개수는 마음대로)")
    print("- : 현재 위치의 요소 삭제 명령")
    print(">- : 마지막 요소 삭제 명령")
    print("@ : 현재 위치의 요소 출력")
    print("= : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경")
    print("E : 배열 비우기")
    print("M : 현재 위치의 요소를 (n, 앞, 뒤)번째로 이동")
    print("D : 배열 요소 개수 확인")
    print("L : 배열 출력")
    print("S : 찾기 명령")
    print("R : 배열 거꾸로 바꾸기 명령")
    print("WP : 요소 2개 서로 교환 명령")
    print("Q : 프로그램 종료")
    print()

def Setposition():#첫 현재 위치 설정
    return 0

def DataInsert(array,position):#삽입 함수
    
    idata=input("abcd의 형식으로 삽입할 요소를 입력하세요: ")
    len_idata=len(idata)
    for i in range(len_idata):
        array.insert(position+i, idata[i])

def traverse_front(array):#현재 위치 앞에서부터 변경 함수
    Norder=input("<NN의 형식으로 traverse해주세요: ")

    ttemp=list(Norder)
    if (ttemp[0]=='<'):
        position=0
        tlen=len(ttemp)
        for i in range(1,tlen):
            if (ttemp[i]=='N'):
                position+=1
    else:
        print("입력 형식이 잘못되었습니다.")

    return position

def traverse_rear(array):#현재 위치 뒤에서부터 변경 함수
    Porder=input(">PP의 형식으로 traverse해주세요: ")
    arrlen1=len(array)

    ptemp=list(Porder)
    if (ptemp[0]=='>'):
        position=arrlen1-1
        plen=len(ptemp)
        for i in range(1,plen):
            if (ptemp[i]=='P'):
                position-=1
    else:
        print("입력 형식이 잘못되었습니다.")

    return position

def Delete(array,position):#현재 위치의 요소 삭제 명령
    del array[position]

def DeleteLast(array):#마지막 요소 삭제 명령
    Dlen=len(array)
    del array[Dlen-1]

def get_data(array,position):#현재 위치의 요소 출력
    print(array[position],"을/를 현재 가리키고 있음")

def replace(array,position):#현재 위치에 있는 요소를 사용자가 입력한 요소로 변경
    Delete(array,position)
    DataInsert(array,position)

def empty(array):#배열 비우기
    array=[]
    return array

def move(array,position):#현재 위치의 요소를 (n, 앞, 뒤)번째로 이동
    order=input("현재 위치의 요소를 옮길 위치가 절대 위치인가요? Y/N: ")

    if ((order=='Y') or (order=='y')):
        order2=int(input("현재 위치의 요소를 옮길 위치를 입력하세요(정수): "))
        if (position<order2):
            for i in range(order2-position):
                array[position+i],array[position+i+1]=array[position+i+1],array[position+i]
        elif (order2<position):
            for i in range(position-order2):
                array[position-i],array[position-i-1]=array[position-i-1],array[position-i]
        else:
            print("잘못입력하셨습니다")

    elif ((order=='N') or (order=='n')):
        order3=input("현재 위치의 요소를 앞으로 이동한다면 P를, 뒤로 이동한다면 N을 입력하세요: ")
        if (order3=='P'):
            array[position],array[position-1]=array[position-1],array[position]
        elif (order3=='N'):
            array[position],array[position+1]=array[position+1],array[position]
        else:
            print("잘못 입력함")
            
    else:
        print("잘못 입력")

def data_count(array):#배열 요소 개수 확인
    arrlen=len(array)
    print(arrlen)

def PrintArray(array):#현재 배열 상황을 출력해주는 함수
    print("현재 배열 상황: ",end='')
    print(array)

def Search(array):#찾기 함수
    arrlen=len(array)#배열의 길이를 arrlen에 저장함
    
    SearchAlphabet=input("찾을 문자 입력: ")#사용자에게 찾을 문자 받아옴

    index=[]#배열에 중복된 문자가 있을 수 있음을 고려, index번호를 여러 개 저장할 수 있는 빈 배열 생성

    for i in range(arrlen):#배열의 처음부터 끝까지
        if SearchAlphabet in array[i]:#찾을 문자가 배열에 있으면
            index.append(i)#index배열의 끝에 추가하기
    
    indexlen=len(index)

    #사용자에게 찾은 상황을 알려줌
    
    if (index==[]):#index배열이 빈 배열이면
        print("찾고자 하는 문자가 없습니다.")
    else:#index배열이 빈 배열이 아니면
        print("찾고자 하는 문자 %s는"%SearchAlphabet,end='')
        print(index,end='')
        print("번 인덱스에 있습니다.")

def Reverse(array):#배열을 거꾸로 바꾸는 함수
    arrlen=len(array)#배열의 길이를 arrlen에 저장함
    for i in range(arrlen//2):#바꾸는 과정이 중복되지 않도록 arrlen//2까지 반복함
        array[i],array[arrlen-1-i]=array[arrlen-1-i],array[i]#바꿈
    
def Swap(array):#인덱스 번호를 기준으로 두 요소를 서로 교환하는 함수
    arrlen=len(array)#배열의 길이를 arrlen에 저장함
    while (True):
        #사용자에게 swap할 두 인덱스 번호를 받음
        n1=int(input("swap할 두 인덱스 번호 중 하나를 우선 입력하세요: "))
        n2=int(input("swap할 두 인덱스 번호 중 나머지 하나를 입력하세요: "))

        if ((n1<arrlen)and(n2<arrlen)and(n1!=n2)):#이스케이프 코드
            break
        else:
            print("입력한 인덱스 번호를 감당할 수 없음. 현재 배열을 고려하여 다시 입력")

    array[n1],array[n2]=array[n2],array[n1]#바꿈

#메인 함수
array=[]#배열을 하나 생성함

PrintArray(array)#현재 배열 상황 출력
UserSetting()#프로그램 사용법 출력

position=Setposition()#첫 현재 위치 설정

while(True):#Q명령 시 종료하고, 그 이외에는 프로그램이 계속 실행될 수 있도록 while문 사용
    order=input("명령어를 입력하세요: ")#사용자에게 명령어를 받음
    
    if (order=='Q'):#프로그램을 종료하는 명령어
        print("프로그램을 종료합니다.")
        break

    if (order=='I'):#삽입 명령(+삽입할 요소)
        DataInsert(array,position)
        
    if (order=='N'):#현재 위치를 앞에서부터 변경(N의 개수는 마음대로)
        position=traverse_front(array)
        
    if (order=='P'):#현재 위치를 뒤에서부터 변경(P의 개수는 마음대로)
        position=traverse_rear(array)
        
    if (order=='-'):#현재 위치의 요소 삭제 명령
        Delete(array,position)
        
    if (order==">-"):#마지막 요소 삭제 명령
        DeleteLast(array)
        
    if (order=='@'):#현재 위치의 요소 출력
        get_data(array,position)
        
    if (order=='='):#현재 위치에 있는 요소를 사용자가 입력한 요소로 변경
        replace(array,position)
        
    if (order=='E'):#배열 비우기
        array=empty(array)
        
    if (order=='M'):#현재 위치의 요소를 (n, 앞, 뒤)번째로 이동
        move(array,position)
        
    if (order=='D'):#배열 요소 개수 확인
        data_count(array)
        
    if (order=='L'):#현재 배열 출력
        PrintArray(array)
        
    if (order=='S'):#찾기 함수를 불러오는 명령어
        Search(array)
        
    if (order=='R'):#배열 거꾸로 함수를 불러오는 명령어
        Reverse(array)

    if (order=="WP"):#요소 2개 서로 교환 함수 불러오는 명령어
        Swap(array)
