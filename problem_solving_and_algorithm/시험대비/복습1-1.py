time=int(input("초 단위 시간 입력: "))

m=time//60
s=time%60

h=m//60
m%=60

print("%d시 %d분 %d초"%(h,m,s))
