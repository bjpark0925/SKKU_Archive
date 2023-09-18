#실습 8-2
#20191114 1104

#함수정의
def search_list(key, data):
    n=len(data)
    for i in range(n):
        if key==data[i]: #key값이 data와 같으면
            return i

    return -1


# 메인코드
data=[8,6,5,2,4]
print(data)
key=int(input('search key: ')) #key값 입력

index=search_list(key,data) #탐색 성공인지 실패인지 알아보기 위해 index사용

if index==-1:
    print('탐색 실패')
else:
    print('탐색 성공! 탐색 위치= %d' %index)
