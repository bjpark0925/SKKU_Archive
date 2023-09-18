#응용문제 1

weight=float(input('몸무게를 입력하세요(소수점 입력 가능, kg): '))
height=float(input('키를 입력하세요(소수점 입력 가능m): '))
x=height*height
bmi=weight/x

print('당신의 BMI 지수는 %f입니다.'%bmi)
