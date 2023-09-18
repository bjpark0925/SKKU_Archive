# 실습1-1

s= int(input('초 단위 시간 :'))

m=s//60
s=s%60  # 초

h=m//60 # 시간
m=m%60  # 분

print('%d시 %d분 %d초' % (h,m,s))


