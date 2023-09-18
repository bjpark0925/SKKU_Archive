# 실습4-3
# 2019312014 박병준

menu={}

menu['라면']=3000
menu['떡볶이']=4000
menu['김밥']=2000
menu['햄버거']=5000
menu['참치마요']=2000

for i in menu:
    print(i,menu[i])

print()

s=input('search menu: ')
if s in menu:
    print('%d원' %menu[s])
else:
    print('not Found')
