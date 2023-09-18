
money=int(input("돈 넣어: "))

c500=money//500
money=money%500

c100=money//100
money%=100

c50=money//50
money%=50

c10=money//10
money%=10

print("500: %d, 100: %d, 50: %d 10: %d 잔돈: %d"%(c500,c100,c50,c10,money))
