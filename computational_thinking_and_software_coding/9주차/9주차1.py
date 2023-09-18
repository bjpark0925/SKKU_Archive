apple=int(input("사과 개수"))
banana=int(input("바나나 개수"))
kiwi=int(input("키위 개수"))
aprice=2000
bprice=3000
kprice=4000
total=aprice*apple
total=total+bprice*banana
total+=kprice*kiwi
print("총 매출은 %d원 입니다."%total)
