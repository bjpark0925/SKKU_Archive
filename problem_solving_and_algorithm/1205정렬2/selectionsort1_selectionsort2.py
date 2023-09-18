# data sort algorithm : Selection Sort(선택정렬)_오름차순

def selection_sort1(a):           
    n=len(a)
    cnt=0
    for i in range(n-1):         
        for j in range(i+1, n):  
            if a[i]>a[j]:        
                a[i],a[j]=a[j],a[i] 
                cnt=cnt+1        
        print(i+1,'단계:',a)     
        print('-'*30)
    print('총 교환 횟수', cnt)

# 함수정의
def selection_sort2(a):
    n=len(a)
    cnt=0
    for i in range(n-1):
        pos=i
        for j in range(i+1, n):
            if a[pos]> a[j]:
                pos=j

        if pos!=i:
            a[i],a[pos]=a[pos],a[i]
            cnt +=1        
        print(i+1,'단계:',a) # 단계별 출력
        print('-'*30)
    print('총 교환 횟수 :', cnt)
        
        
    

    
a=[8,6,3,2,4]
print('sort before')
print(a)
print()
print('sort after : selection_sort1')
selection_sort1(a)
print()

a=[8,6,3,2,4]
print('sort before')
print(a)
print()

print('sort after : selection_sort2')
selection_sort2(a) 

    
