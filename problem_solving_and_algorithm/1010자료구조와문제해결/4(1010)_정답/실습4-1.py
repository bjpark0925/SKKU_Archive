# 실습4-1


goodsay=[]
goodsay.append('행복하세요')
goodsay.append('응원합니다.')
goodsay.append('웃음 가득한 하루')
goodsay.append('다 잘 될꺼에요.')
goodsay.append('수고했어요')

while True:
    num=int(input('num:'))
    if num<0 or num>=len(goodsay):
        print('잘못입력하셨어요.')
    else:
        print('message:',goodsay[num])
        break


