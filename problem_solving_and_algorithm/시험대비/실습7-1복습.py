#선택 정렬 : 오름차순

#함수 정의

def sort(a):
    n=len(a)
    cnt=0
    for i in range(n-1):
        for j in range(i+1, n):
            if a[i]>a[j]:
                a[i],a[j]=a[j],a[i]
                cnt+=1
        print(i+1, '단계 : ', a)
    print('총 교환 횟수',cnt)





#메인 코드
a=[8,6,3,2,4]
print('선택정렬 전')
print(a)
print()
print('선택정렬 후')
sort(a)
