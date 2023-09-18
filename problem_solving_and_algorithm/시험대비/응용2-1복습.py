age=int(input("나이 입력: "))

if age>=65:
    message='경로 우대 승차권 발급'
else:
    message='일반 승차권 발급'

same='이용해주셔서 감사합니다.'

print("%d세인 당신, %s\n%s"%(age, message, same))
