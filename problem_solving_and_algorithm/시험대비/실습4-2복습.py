team={'케인','알리','손흥민','모우라','시소코','다이어'}
late={'시소코','알리'}
absent={'케인','알리'}
print('='*40)
print('team',team)
print('late',late)
print('absent',absent)
print('='*40)

#1. 지각과 결석을 한 번도 하지 않은 학생들에게
#   가산점을 줄 때 가산점을 받는 학생은 누구인가?

noincentive=late|absent
incentive=team-noincentive
print("가산점 받을 사람:",incentive)

#2. 지각과 결석을 모두 한 학생에게 벌점을 주려면
#   벌점을 받은 학생은 누구인가?

penalty=late&absent
print("벌점 받을 사람: ",penalty)
