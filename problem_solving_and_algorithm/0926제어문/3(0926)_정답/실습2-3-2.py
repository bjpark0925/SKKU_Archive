# 실습2-3
# 학번 : 2019~ , 이름 : 나코딩
import time



# 별 출력하기 1
'''
print('*****')
print('*****')
print('*****')
print('*****')
print('*****')
'''

for i in range(5):
    for j in range(5):
        print('*',end='')
    print()
    time.sleep(1)  # 1초 멈추기


# 별 출력하기 2

for i in range(1,6):
    for j in range(1,i+1):
        print('*',end='')
    print()

print()

for i in range(5):
    for j in range(i+1):
        print('*',end='')
    print()













