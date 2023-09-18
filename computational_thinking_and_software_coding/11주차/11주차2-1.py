#1~100의 합계(3의 배수 제외)
sum,a=0,0

while a<=99:
    a+=1
    if a%3==0:
        continue
    sum+=a
print(sum)
    
