goodsay=[]
goodsay.append('행복하세요')
goodsay.append('응원합니다')
goodsay.append('웃음 가득한 하루')
goodsay.append('다 잘 될꺼에요')
goodsay.append('고생하셨어요')

print('%d'%len(goodsay))
print('%d'%goodsay.count('응원합니다'))

while True:
    num=int(input('num:'))
    if num<0 or num>4:
        print('잘못입력함')
    else:
        print('message:%s'%goodsay[num])
        break
