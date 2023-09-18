# 응용문제 2

eng=int(input('eng : '))
com=int(input('com : '))
math=int(input('math : '))

avg=(eng+com+math)/3

if avg>=90:
    grade='A'
elif avg>=80:
    grade='B'
elif avg>=70:
    grade='C'
else:
    grade='F'

print('당신의 평균은 %.1f이고 학점은 %s입니다.' % (avg,grade))
#print('당신의 평균은 {0}이고 학점은 {1}입니다.'.format(avg,grade))
#print('당신의 평균은 {}이고 학점은 {}입니다.'.format(avg,grade))
#print('당신의 학점은 {1}이고 성적은 {0}입니다.'.format(grade,avg))
