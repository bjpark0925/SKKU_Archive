def bubble_sort(a):
    cnt=0
    n=len(a)
    for i in range(n-1):
        for j in range(0, n-1):
            if a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
                cnt+=1
            else:
                break
        print(i+1,'단계 : ',a)
    print('총 교환 횟수: ',cnt)


a=[8,6,3,2,4]
print('정렬 전: ')
print(a)
print()
print('정렬 후: ')
bubble_sort(a)
