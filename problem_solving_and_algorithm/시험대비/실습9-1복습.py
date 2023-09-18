def sort(b):
    n=len(b)
    for i in range(n-1):
        for j in range(i, n-1):
            if b[i]>b[j+1]:
                b[i],b[j+1]=b[j+1],b[i]
    return b

def binarysearch(key,a):
    global cnt
    low=0
    high=len(a)-1
    while low<=high:
        mid=(low+high)//2
        cnt += 1
        if key<a[mid]:
            high=mid-1
        elif key>a[mid]:
            low=mid+1
        else:
            return mid

    return -1

cnt=0
b=[13,33,53,25,6,43,51,14]
a=sort(b)
print(a)

key=int(input('search key : '))
result=binarysearch(key,a)

if result==-1:
    print('탐색 실패')
else:
    print(b[result],' %d번에 탐색 성공'%cnt)
