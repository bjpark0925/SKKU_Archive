# 함수정의
def search_list(key, data):
    n=len(data)
    for i in range(n):
        if key==data[i]: #
            return i 
    return -1
    

# 메인코드
data=[8,6,5,2,4]
print(data)
key=int(input('search key : ')) #

index=search_list(key,data) #

if index==-1:
    print('탐색 실패')
else:
    print('탐색 성공! 탐색 위치= %d' % index)

