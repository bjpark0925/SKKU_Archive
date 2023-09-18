# 실습2-2
# 학번 :  , 이름 :
# 20190926 1112

import sys

choice=int(input("도형선택_1:사각형,2:삼각형,3:원 "))

if choice==1:
    a=int(input('가로: '))
    b=int(input('세로: '))
    area=a*b
elif choice==2:
    a=int(input('밑변: '))
    b=int(input('높이: '))
    area=0.5*a*b
elif choice==3:
    r=int(input('반지름: '))
    area=3.1415*r*r
else:
    print('잘못된 선택')
    sys.exit()

print('면적 {0}' .format(area))
