# 실습2-1
# 학번 : 2019~ , 이름 : 나코딩

name=input('name : ')
score=int(input('score : '))

if score >=95:
    grade='A+'
elif score>=90:
    grade='A'
elif score>=80:
    grade='B+'
elif score>=70:
    grade='B'
else:
    grade='C'

print('%s학생의 점수는 %d이고 성적은 %s입니다.' % (name,score,grade))
#print('이름:{},점수:{},성적:{}'.format(name,score,grade))
    
