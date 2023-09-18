attendence=float(input('출석 점수를 입력하세요(100점 만점): '))
learning=float(input('러닝페어 점수를 입력하세요(100점 만점): '))
final=float(input('기말고사 점수를 입력하세요(100점 만점): '))
ordinary=float(input('평소학습 점수를 입력하세요(100점 만점): '))

a=attendence*0.2
b=learning*0.3
c=final*0.4
d=ordinary*0.1
total=a+b+c+d

print('이번 학기 문제해결과 알고리즘 과목의 총점은 %.1f점입니다.'%total)
