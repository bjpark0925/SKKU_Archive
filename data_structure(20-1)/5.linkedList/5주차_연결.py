#Node 클래스 정의
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

#LinkedList 클래스 정의
class LinkedList:

    #초기화 메서드
    def __init__(self):
        dummy=Node("dummy")
        self.head=dummy
        self.cur=self.head
        self.before=None#데이터 삭제를 위해 before 설정(before는 항상 cur 앞에)
        
        self.size=0

    def data_insert(self,data):#삽입
       newNode=Node(data)
       newNode.next=self.cur.next
       
       self.cur.next=newNode
       self.before=self.cur
       self.cur=newNode

       self.size+=1

    def print_list(self):#리스트 출력
        p=self.head.next
        while p:
            if p.next!=None:
                print(p.data, '-> ', end='')
            else:
                print(p.data)
            p=p.next

    def count(self):#개수
        return self.size

    def traverse_front(self,cnt):#앞에서부터 traverse
        if self.size==0:#빈 리스트
            return
        
        self.cur=self.head.next#위치 초기화
        self.before=self.head

        if cnt<self.size:
            for i in range(cnt):#cnt에 따른 현재 위치 이동
                self.cur=self.cur.next
                self.before=self.before.next

    def traverse_rear(self,cnt):#뒤에서부터 traverse
        if self.size==0:
            return
        
        self.cur=self.head.next#위치 초기화
        self.before=self.head

        if cnt<self.size:
            for i in range(self.size-1-cnt):#cnt에 따른 현재 위치 이동
                self.cur=self.cur.next
                self.before=self.before.next
    
    def get(self):#현재 위치 데이터 출력
        return self.cur.data

    def delete(self):#현재 위치 데이터 삭제
        if self.size==0:
            return
        
        if self.cur.next==None:#현재 위치가 맨끝
            self.before.next=self.cur.next
            del self.cur

            self.cur=self.head.next
            self.before=self.head
            self.size-=1
        else:#현재 위치가 리스트 중간
            self.before.next=self.cur.next
            del self.cur

            self.cur=self.before.next
            self.size-=1

    def replace(self,data):#교체
        if self.size==0:
            return
        self.cur.data=data

    def is_member(self,data):#데이터 존재 여부
        if self.size==0:
            return
        p=self.head.next
        while p:
            if p.data==data:
                return True
            p=p.next

    def Clear(self):#리스트 비우기
        if self.size==0:
            return
        
        self.before=self.head#위치 초기화
        self.cur=self.head.next
        while self.cur:#처음부터 끝까지 데이터 삭제
            self.before.next=self.cur.next
            del self.cur

            self.cur=self.before.next
            self.size-=1

        self.__init__()#리스트를 첫 상태로 초기화

    def is_empty(self):#빈 배열 여부
        if self.size==0:
            return True
        else:
            return False

    def nswap(self):#nswap
        if self.cur.next==None:
            return
        self.before.next=self.cur.next
        self.cur.next=self.cur.next.next
        self.before.next.next=self.cur

    def reverse_print(self):#reverse_print
        if self.size==0:
            return
        arr=[]
        p=self.head.next

        for i in range(self.size):#리스트의 데이터를 arr에 저장
            arr.append(p.data)
            p=p.next

        for i in range(self.size//2):#arr를 전부 reverse
            arr[i],arr[self.size-1-i]=arr[self.size-1-i],arr[i]

        for i in range(self.size):#reverse된 arr 출력
            print(arr[i],end='')
        print()
        
    def type(self):#type
        if self.size==0:
            return
        p=self.head.next
        while p:
            if p.next!=None:
                print(type(p.data), '-> ', end='')
            else:
                print(type(p.data))
            p=p.next

def UserSetting():
    print("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
    print("명령어 : Q, +, L, G, N, P, -, #, =, ?, C, E, WN, RL, T");
    print("Q : 프로그램 종료");
    print("+: 삽입 명령(+만 입력 후 엔터해야 함)");
    print("L : 리스트 전체 출력");
    print("G : 현재 위치의 데이터 출력");
    print("N : 현재 위치를 앞에서부터 변경(N만 입력 후 엔터해야 함)");
    print("P : 현재 위치를 뒤에서부터 변경(P만 입력 후 엔터해야 함)");
    print("- : 현재 위치의 데이터 삭제 명령");
    print("# : 리스트 요소 개수 확인");
    print("= : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경(=만 입력 후 엔터해야 함)");
    print("? : 찾기 명령(?만 입력 후 엔터해야 함)");
    print("C : 리스트 전체 비우기");
    print("E : 빈 리스트 여부 확인");
    print()
    print("[이 밑으로는 새로운 기능]");
    print("WN : 현재 위치의 데이터와 바로 뒤 데이터의 위치 바꾸기");
    print("RL : 리스트 거꾸로 출력(연결리스트의 연결 상태는 변하지 않음)");
    print("T : 리스트에 들어있는 데이터들의 데이터 타입 출력");
    print()
    
if __name__=='__main__':
    s=LinkedList()#create

    UserSetting()

    while(True):
        order=input("order: ")

        if (order=='Q'):
            print("프로그램을 종료합니다")
            break

        if (order=='+'):
            aorder=input("추가할 데이터를 하나만 입력하세요: ")
            s.data_insert(aorder)

        if (order=='L'):
            s.print_list()

        if (order=='G'):
            print(s.get())

        if (order=='N'):
            norder=int(input("앞에서부터 몇 번 traverse하겠습니까?(정수): "))
            s.traverse_front(norder)

        if (order=='P'):
            porder=int(input("뒤에서부터 몇 번 traverse하겠습니까?(정수): "))
            s.traverse_rear(porder)

        if (order=='-'):
            s.delete()
            
        if (order=='#'):
            print(s.count())
            
        if (order=='='):
            rorder=input("바꿀 데이터를 입력하세요: ")
            s.replace(rorder)

        if (order=='?'):
            morder=input("찾을 데이터를 입력하세요; ")
            print(s.is_member(morder))

        if (order=='C'):
            s.Clear()

        if (order=='E'):
            print(s.is_empty())

        if (order=="WN"):
            s.nswap()

        if (order=="RL"):
            s.reverse_print()

        if (order=='T'):
            s.type()
