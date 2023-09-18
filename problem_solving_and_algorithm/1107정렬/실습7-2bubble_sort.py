# 버블정렬

def bubble_sort(a):
    n=len(a)
    cnt=0
    for i in range(n-1):                # (리스트길이-1)만큼 반복
        for j in range(n-1):
            if a[j]>a[j+1]:             # 앞의 자료가 뒤의 자료보다 크면
                a[j],a[j+1]=a[j+1],a[j] # 서로 교환
                cnt+=1
        print(i+1,'단계:',a)            # 단계별 출력
        print('-'*30)
    print('총 교환 횟수', cnt)

    
# 메인코드
a=[8,6,3,2,4]        # 자료 리스트 선언
print('버블정렬 전')
print(a)
print()
print('버블정렬 후')
bubble_sort(a)    # 버블정렬 함수 호출

