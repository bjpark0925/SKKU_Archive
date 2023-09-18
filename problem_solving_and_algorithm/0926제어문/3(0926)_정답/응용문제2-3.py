# 응용문제 2-3
# 로그인 프로그램
 
# 아이디, 패스워드 입력
sid=input('id :')
spw=input('pw :')

# 로그인 판단
if sid=='skku': 
    if spw=='1234':
        print('login')
    else:
        print('pw error')
else:
    print('id error')

    
