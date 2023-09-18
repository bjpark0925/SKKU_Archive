#실습 9-1
#2019312014 박병준

def binarySearch(key, data):
    global cnt
    low=0
    high=len(data)-1
    while low<=high:
        mid = (low+high)//2 #중간값 계산
        cnt += 1
        if key < data[mid]:
            high = mid-1
        elif key>data[mid]:
            low = mid +1
        else:
            return mid

    return -1

cnt=0 # 탐색횟수
data=[13,33,53,25,6,43,51,14]
data.sort()
print(data)

key=int(input('search key : '))
result=binarySearch(key,data)

if result==-1:
    print('탐색실패')
else:
    print('%d번에 탐색성공' %cnt)
