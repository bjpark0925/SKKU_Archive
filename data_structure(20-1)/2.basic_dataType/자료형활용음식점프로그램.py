#외국 음식점에서 음식 값을 지불하기 위해 필요한 원화를 계산하는 프로그램
#리스트를 사용한 프로그램(사용자가 음식 가격을 직접 입력해야 함)

food=['햄버거','스테이크','피자','피시앤칩스','파스타','바베큐','핫도그','프라이드 치킨','버팔로 윙','터키 로스트','샌드위치','로코모코','포테이토 칩스','랍스타','잠발라야','치킨 누들 수프','그리츠','클램 차우더','검보','도넛','브라우니','치즈 케이크','애플 파이','오레오','팝콘']
money_type=['유로','달러','엔화','위안화']
length=len(food)
add=0

def change_money(x, y):
    if x=='유로':
        return 1330.99*y
    if x=='달러':
        return 1230.80*y
    if x=='엔화':
        return 1105.19*y
    if x=='위안화':
        return 173.56*y
        
print("=================================메뉴판=================================")
print('\n')
for i in range(length):
    if (i!=0 and i%5==0):
        print('\n')
        
    if (i==length-1):
        print(food[i])
        print('\n')
    else:
        print(food[i],end=', ')
print("========================================================================")

while(True):
    while (True):
        choose=input("음식을 주문하세요: ")
        if choose in food:
            break
        else:
            print("주문한 음식이 메뉴에 없습니다. 메뉴판에 적힌 음식 중 하나를 정확히 입력하세요.")
            
    while(True):
        paytype=input("선택한 음식의 지불 방식을 입력하세요(유로, 달러, 엔화, 위안화 중 하나 정확히 기입): ")
        if paytype in money_type:
            break
        else:
            print("지불 방식을 잘못 입력했습니다. 유로, 달러, 엔화, 위안화 중 하나를 오타 없이 정확히 입력해주세요.")

    price=float(input("음식 가격은 몇 %s입니까?: "%paytype))

    Kmoney=change_money(paytype, price)
    add+=Kmoney

    question=input("또 주문하고 싶은 메뉴가 있습니까? 없다면 N또는 n을 입력하세요: ")
    
    if (question=='N' or question=='n'):
        break
    
print("지불해야 할 음식의 가격은 원화로 총 %.2f원입니다."%add)
