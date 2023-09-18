i=0
while i<=99:
    i+=1
    if i%3==0:
        continue
    elif '3' in str(i):
        continue
    print(i,end=',')
