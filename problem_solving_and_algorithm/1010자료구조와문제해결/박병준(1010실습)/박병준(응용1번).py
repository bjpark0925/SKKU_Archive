# 응용문제 1번
# 2019312014 박병준

#1)
member=['홍일동', '홍이동', '홍삼동']
member.append('홍사동')
#2)
member.insert(2,'홍이동')
#3)
print("홍이동은 %d명"%member.count('홍이동'))
#4)
member.reverse()
print(member)
#5)
member.remove('홍일동')
print(member)
#6)
print("현재 학생수 %d명"%len(member))
