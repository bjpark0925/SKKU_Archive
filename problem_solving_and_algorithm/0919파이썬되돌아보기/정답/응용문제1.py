# 응용문제1

# BMI = 몸무게/키*키

kg=float(input('weight : '))
h=float(input('height(cm) : '))

h=h/100 # m로 변환
bmi=kg/h**2 # 또는 (h*h) 반드시 괄호

print('bmi : %.2f' % bmi)

