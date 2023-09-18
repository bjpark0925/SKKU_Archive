# 실습4-2

team={'예지','리아','채령','류진'}
late={'리아','류진'}
absent={'채령','류진'}
print('='*40)
print('team',team)
print('late',late)
print('absent',absent)
print('='*40)

#1. 지각과 결석을 한 번도 하지 않은 학생들에게
#   가산점을 줄 때 가산점을 받는 학생은 누구인가?
late_absent=late | absent #합집합
add_point=team-late_absent # 차집합
print('add_point name : ',add_point)

#2. 지각과 결석을 모두 한 학생에게 벌점을 주려면
#   벌점을 받은 학생은 누구인가?

penalty_point=late & absent # 교집합
print('penalty_point name : ',penalty_point)
