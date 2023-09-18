# 실습2-2
# 학번 : 2019~ , 이름 : 나코딩

import sys

choice=int(input('도형선택_1:사각형,2:삼각형,3:원 '))

if choice==1: # 삼각형
    w=int(input('가로:'))
    h=int(input('세로:'))
    area=w*h
elif choice==2: # 사각형
    b=int(input('밑변:'))
    h=int(input('높이:'))
    area=0.5*b*h
elif choice==3: # 원
    r=int(input('반지름:'))
    area=3.1415*r*r
else:
    print('잘못된 선택')
    sys.exit() # 프로그램 강제 종료

#print('면적=', area)
#print('면적 %f' % area)    
print('면적 {0}' .format(area))

