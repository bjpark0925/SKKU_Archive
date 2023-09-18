# Selection Sort(선택정렬) : 오름차순

# 함수정의

def selection_sort(a):           # 선택정렬 함수 정의 부분
    n=len(a)
    cnt=0
    for i in range(n-1):         # (자료의개수-1)만큼 반복
        for j in range(i+1, n):  # 선택된 자료 뒤의 모든 자료들을 비교하여
            if a[i]>a[j]:        # 선택된 자료가 뒤의 자료보다 크면
                a[i],a[j]=a[j],a[i] # 서로 교환
                cnt=cnt+1        # 교환 횟수 계산
        print(i+1,'단계:',a)     # 단계별 출력
        print('-'*30)
    print('총 교환 횟수', cnt)

    
# 메인코드
a=[8,6,3,2,4]        # 자료 리스트 선언
print('선택정렬 전')
print(a)
print()
print('선택정렬 후')
selection_sort(a)    # 선택정렬 함수 호출

    
