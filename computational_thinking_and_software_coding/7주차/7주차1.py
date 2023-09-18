string='파이선을 사랑하는 한옥영님! 힘내세요!'
print('원본 문자열: %s' %string)

start= int(input('이름의 시작 인덱스 번호를 입력하세요(0부터 시작): '))
finish= int(input('이름의 마지막 인덱스 번호를 입력하세요(0부터 시작): '))
name=input('새롭게 작성될 문자열에 넣을 이름을 입력하세요: ')

new_string=string[:start] + name + string[finish+1:]
print("="*10, new_string)
