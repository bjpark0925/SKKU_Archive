sum=0
count=10

for i in range(1,11):
    msg=str(i)+"번째 값을 입력하세요: "
    x=int(input(msg))
    sum=sum+x
avg=sum/count

print('=====\n입력받은 10개의 합은 %d이며 평균은 %.2f입니다.\n=====' %(sum, avg))
