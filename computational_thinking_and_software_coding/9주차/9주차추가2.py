year=int(input("연도를 입력해라: "))
if (year%4==0 and year%100!=0) or (year%400==0):
    girl='윤년'
else:
    girl='윤년 아님'
print("%d년은 %s입니다."%(year, girl))
