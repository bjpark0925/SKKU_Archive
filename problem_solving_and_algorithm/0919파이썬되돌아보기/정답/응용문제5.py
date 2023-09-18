# 응용문제5

# 시험점수계산프로그램
# 출석(20%), 러닝페어(30%), 기말(40%), 평소학습(10%)


attend=int(input('attendance score: '))
fair=int(input('learning Fair score: '))
final=int(input('final score : '))
normal=int(input('normal score : '))

total = attend*0.2 + fair*0.3+final*0.4+normal*0.1

'''
total= attend*0.2
total+=fair*0.3
total+=final*0.4
total+=normal*0.1
'''
print('total : %d' % total)

