#이름, 이메일, 동아리 가입여부, 정규 회원 여부, 계속 입력희망

member=[]

def add_member(name, email, club='파이선 동아리', status='정규'):
    member.append([name, email, club, status])

while True:
    name=input("이름 입력: ")
    email=input("이메일 입력: ")
    
    chk_club=input("파이선 동아리 가입 Yes or No")
    if chk_club=='No':
        club=input("가입을 원하는 동아리명 입력: ")
        
    chk_status=input("정규 희망 Yes or No")
    if chk_status=='No':
        temp_status='임시'

    if chk_club=='Yes' and chk_status=='Yes':
        add_member=(name, email)
    elif chk_club=='No' and chk_status=='Yes':
        add_member==(name, email, club)
    elif chk_club=='Yes' and chk_status=='No':
        add_member=(name, email, status=temp_status)
    else:
        add_member==(name, email, club, status=temp_status)

    more=input("더 할거임? Yes or No")
    if more=='No':
        break

print("회원 명단 출력")
for i in member:
    print(i)
