a=0

def whatatt(day):
    global a
    global today
    global thisweek
    holiday=int(input('\n혹시 오늘이 공휴일인가요? 1.네 2.아니요\n※숫자를 입력하주세요※ : '))
    if holiday == 1:
        today=1
        print('\n어떤 놀이기구를 타실건가요?')
        print('1.아트란티스 2.후렌치레볼루션 3.헤성특급')
        print('4.후룸라이드 5.파라오의분노 6.자이로드롭')
        a=int(input('원하는 어트랙션의 번호를 입력해주세요 : '))
        return a
    elif holiday == 2:
        print('\n어떤 놀이기구를 타실건가요?')
        print('[1.아트란티스 2.후렌치레볼루션 3.헤성특급]')
        print('[4.후룸라이드 5.파라오의분노 6.자이로드롭]')
        a=int(input('원하는 어트랙션의 번호를 입력해주세요 : '))
        return a
    else:
        return 0

def chooseatt(att, today):
    if att==1:
        time=atlan(today)
        print('\n아트란티스의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    elif att==2:
        time=french(today)
        print('\n후렌치 레볼루션의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    elif att==3:
        time=comet(today)
        print('\n혜성특급의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    elif att==4:
        time=ride(today)
        print('\n후룸라이드의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    elif att==5:
        time=phara(today)
        print('\n파라오의 분노의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    elif att==6:
        time=drop(today)
        print('\n자이로드롭의 대기시간은 약 %d분 ~ %d분으로 추정됩니다.\n'%(time, time-20))
    else:
        print('\n===잘못 입력하셨습니다. 다시 입력해 주세요.===\n')

def atlan(today):
    if today==1:
        return 150
    elif today==2:
        return 120
    elif today==3:
        return 100
    elif today==4:
        return 80
    elif today==5:
        return 60
def french(today):
    if today==1:
        return 140
    elif today==2:
        return 110
    elif today==3:
        return 90
    elif today==4:
        return 70
    elif today==5:
        return 50
def comet(today):
    if today==1:
        return 120
    elif today==2:
        return 90
    elif today==3:
        return 70
    elif today==4:
        return 60
    elif today==5:
        return 50
def ride(today):
    if today==1:
        return 130
    elif today==2:
        return 100
    elif today==3:
        return 80
    elif today==4:
        return 60
    elif today==5:
        return 40

def phara(today):
    if today==1:
        return 150
    elif today==2:
        return 120
    elif today==3:
        return 90
    elif today==4:
        return 60
    elif today==5:
        return 40

def drop(today):
    if today==1:
        return 60
    elif today==2:
        return 50
    elif today==3:
        return 40
    elif today==4:
        return 30
    elif today==5:
        return 20
    
    
while True:        
    model1={'월':4, '화':4, '수':3, '목':3, '금':3, '토':2, '일':2} # bbaaass
    model2={'월':5, '화':5, '수':4, '목':4, '금':3, '토':2, '일':2} # ccbbass
    model3={'월':3, '화':3, '수':3, '목':3, '금':3, '토':2, '일':2} # aaaaass
    model4={'월':3, '화':3, '수':3, '목':3, '금':2, '토':1, '일':1} # aaaasSS
    model5={'월':5, '화':5, '수':5, '목':5, '금':4, '토':3, '일':3} # ccccbaa
    model6={'월':4, '화':4, '수':4, '목':4, '금':3, '토':2, '일':2} # bbbbass

    print("{1월 2월 3월 4월}")
    print("{5월 6월 7월 8월}")
    print("{9월 10월 11월 12월}")
    month=int(input('이번달은 몇 월 인가요? : '))
    if month==1:
        week1=model3
        week2=model1
        week3=model1
        week4=model2
        week5=model2
    elif month==2:
        week1=model5
        week2=model3
        week3=model1
        week4=model4
        week5=model4
    elif month==3:
        week1=model5
        week2=model5
        week3=model2
        week4=model2
        week5=model2
    elif month==4:
        week1=model5
        week2=model5
        week3=model2
        week4=model2
        week5=model1
    elif month==5:
        week1=model1
        week2=model6
        week3=model6
        week4=model6
        week5=model2
    elif month==6:
        week1=model2
        week2=model5
        week3=model5
        week4=model2
        week5=model2
    elif month==7:
        week1=model5
        week2=model2
        week3=model6
        week4=model1
        week5=model3
    elif month==8:
        week1=model4
        week2=model4
        week3=model1
        week4=model2
        week5=model2
    elif month==9:
        week1=model6
        week2=model6
        week3=model5
        week4=model5
        week5=model1
    elif month==10:
        week1=model6
        week2=model3
        week3=model6
        week4=model6
        week5=model6
    elif month==11:
        week1=model5
        week2=model5
        week3=model5
        week4=model5
        week5=model6
    elif month==12:
        week1=model6
        week2=model5
        week3=model2
        week4=model3
        week5=model3
    else:
        print('\n===잘못 입력하셨습니다. 다시 입력해 주세요.===\n')
        continue

    print('\n이번주는 몇 째 주인가요?')
    week=int(input('※숫자를 입력해주세요※ : '))
    if week==1:
        thisweek=week1
    elif week==2:
        thisweek=week2
    elif week==3:
        thisweek=week3
    elif week==4:
        thisweek=week4
    elif week==5:
        thisweek=week5
    else:
        print('\n===잘못 입력하셨습니다. 다시 입력해 주세요.===\n')
        continue

    
    print("\n{월 화 수 목 금 토 일}")
    day=str(input("오늘이 몇 요일 인가요? : "))
    if day=='월':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='화':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='수':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='목':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='금':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='토':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    elif day=='일':
        today=thisweek[day]
        att=whatatt(day)
        chooseatt(att, today)
    else:
        print('\n===잘못 입력하셨습니다. 다시 입력해 주세요.===\n')
        continue

