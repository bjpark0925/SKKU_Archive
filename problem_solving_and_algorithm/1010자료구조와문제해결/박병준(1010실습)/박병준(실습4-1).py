# 실습4-1
#2019312014 박병준

goodsay=[]
goodsay.append('행복하세요')
goodsay.append('응원합니다.')
goodsay.append('웃음 가득한 하루')
goodsay.append('다 잘 될꺼에요.')
goodsay.append('고생하셨어요')

while True:
    num=int(input('num:'))
    if num<1 or num>5:
        print('잘못입력하셨어요.')
    else:
        print('message:',goodsay[num-1])
        break
