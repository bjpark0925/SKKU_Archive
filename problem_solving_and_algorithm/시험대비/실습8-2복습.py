def search(s, a):
    n=len(a)
    for i in range(n):
        if s==a[i]:
            return i
    return -1
   
        
a=[8,6,5,2,4]
print(a)

while (True):
    s=int(input("search key : "))
    if s==0:
        break
    index=search(s,a)

    if index==-1:
        print('탐색 실패')
    else:
        print('탐색 성공! 탐색 위치= %d'%index)

