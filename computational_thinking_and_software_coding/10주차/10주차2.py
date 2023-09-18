shrit=int(input("티셔츠 개수"))
pants=int(input("바지 개수"))
jacket=int(input("자켓 개수"))
sprice=10000
pprice=15000
jprice=30000
total=shrit*sprice
total+=pants*pprice
total+=jacket*jprice

if total<100000:
    print("5%할인")
    total*=0.95
if (total>=100000 and total<200000):
    print("10%할인")
    total*=0.9
if total>200000:
    print("20%할인")
    total*=0.8
print("총 가격 %d"%total)
