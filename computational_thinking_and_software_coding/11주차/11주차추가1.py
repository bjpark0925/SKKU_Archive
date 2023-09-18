member=[]

num=int(input("회원수:"))

for i in range(num):
    print('='*5)
    name=input("이름:")
    phone=input("tell")
    mail=input("이메일")
    member.append((name,phone,mail))

print('#'*10)

for fact in member:
    print("이름: %-10s 연락처: %s"%(fact[0],fact[1]))
