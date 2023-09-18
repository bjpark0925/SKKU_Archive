# 실습4-3

# 1. 빈 딕셔너리 생성
menu={}

# 2. 딕셔너리 정보 추가(초기화)
menu['라면']=3000
menu['떡볶이']=4000
menu['김밥']=2000
menu['햄버거']=5000
menu['참치마요']=2000


# 3. 전체 딕셔너리 정보 출력
for i in menu.keys():
    print(i,menu[i])

print()

# 4. 가격 검색
s=input('search menu :')
if s in menu:
    print('%d원' % menu[s])
else:
    print('not Found')




