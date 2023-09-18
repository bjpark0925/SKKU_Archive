
money=int(input("투입"))
price=int(input("물건값"))
rest=money-price
print("거스름돈:",rest)

c500=rest//500
rest%=500
c100=rest//100
rest=rest%100

print("500원: ",c500)
print("100원: ",c100)
print(rest)
