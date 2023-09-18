# 실습1-1

t=int(input('초 단위 시간:'))

m=t//60
s=t%60

h=m//60
m=m%60

print('%d시 %d분 %d초'%(h,m,s))
