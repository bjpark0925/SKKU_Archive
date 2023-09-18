# 실습4-2
# 2019312014 박병준

team={'예지','리아','채령','류진'}
late={'리아','류진'}
absent={'채령','류진'}
print('='*40)
print('team',team)
print('late',late)
print('absent',absent)
print('='*40)

#1. 지각,결석x학생 가산점, 누구?

late_absent=late|absent
add_point=team-late_absent
print('add_point name: ',add_point)

#2. 지각,결석 모두 학생 벌점, 누구?

penalty_point=late&absent
print('penalty_point name: ',penalty_point)
