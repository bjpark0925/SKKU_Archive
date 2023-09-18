name=input("이름: ")
score=int(input("점수: "))

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

print('이름:{},점수:{},성적:{}'.format(name,score,grade))
