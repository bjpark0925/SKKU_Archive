a=int(input("몇 단 출력?"))
if a==0:
    print("ㄴㄴ")
    
else:
    for a in range(a,10,1):
        for i in range(1,10,1):
             print(a,'*',i,'=',a*i)
