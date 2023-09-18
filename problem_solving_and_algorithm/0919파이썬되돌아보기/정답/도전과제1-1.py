# 도전과제 1-1

# 세 자리 양의 정수를 입력 받아 각 자리수를 출력하시오.
digit=int(input('100~999 : '))

d100=digit//100
digit=digit%100

d10=digit//10
d1=digit%10

print('100의 자리수 숫자 : %d' % d100)
print(' 10의 자리수 숫자 : %d' % d10)
print('  1의 자리수 숫자 : %d' % d1)
