# 실습2-1
# 학번 : , 이름 :
# 20190926 1105

name=input("이름을 입력하세요: ")
score=int(input("점수를 입력하세요(100점 만점): "))

if score>=95:
    grade='A+'
elif score>=90:
    grade='A'
elif score>=85:
    grade='B+'
elif score>=80:
    grade='B'
else:
    grade='C'

print("%s학생의 점수는 %d이고, 성적은 %s입니다."%(name, score, grade))
