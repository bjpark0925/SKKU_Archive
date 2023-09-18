#prototype_hangul


from tkinter import *
from tkinter import messagebox
from copy import * #딕셔너리의 깊은 복사를 사용하기 위해 import한 모듈


def Enter_Time():

    #Label(이미지) 정보 변경 및 place
    Label_Text_Title["text"]="몇 월 몇째 주 무슨 요일인지 입력하세요.\n예)3월,2주,화요일\n위 예시와 똑같이 입력하세요."
    Label_Text_Title.place(x=300,y=300,anchor="center")


    #Entry place
    Time_Enter.place(x=300,y=450,anchor="center")

    #Button place
    Btn_Check_Time.place(x=300,y=500,anchor="center")
    Btn_Return.place(x=300,y=550,anchor="center")

    #Mainmenu 버튼 지우기
    Btn_Time_Enter.place_forget()
    Btn_B1_F.place_forget()
    Btn_1_F.place_forget()
    Btn_MagicIsland_F.place_forget()

    #Mainmenu 사진 지우기
    Label_Image_Title.place_forget()
    

def MessageBox_Display(title,message,cnt):
    MessageBox = Toplevel()
    x=500*(cnt-1)#count 변수 이용해서, 화면상에 위젯 배치 
    MessageBox.geometry("600x300+{0}+100".format(x),)
    MessageBox.title(title)

    Label_Text_MessageBox=Label(MessageBox,text=message,font=("맑은 고딕",10))
    Label_Text_MessageBox.place(x=300,y=150,anchor="center")
    
def Search(dir,attraction,start,end,floor,time=0):#길 찾기 알고리즘, 다익스트라 알고리즘 응용

    global cnt#count 변수 
    
    if attraction[start][0]>=time:#시간이 같은 경로 다른 여러가지 경로도 포함..
        attraction[start][0]=time
        dir.append(start)
        
    else:
        return "취소"

    if start==end:
        MessageBox_Display("{0}번째 경로".format(cnt),"{0}분 소요\n{1}\n왼쪽부터 순서대로 출발지에서 목적지까지의 경로\n".format(time,dir),cnt)
        cnt=cnt+1
        return "도착"

    for i in attraction[start][1]:
        Search(list(dir),attraction,i[0],end,i[1],i[2]+time)#재귀함수를 쓸 때는 얕은 복사를 통해 attraction 딕셔너리를 넘겨줌
        

def B1_F():#지하 1층 관장 함수
    
    if congestion==0:#날짜/시간을 입력하지 않으면
        messagebox.showinfo("warning","날짜/시간을 입력하세요!")
        return#함수 종료
    #Label(이미지) 정보 변경 및 place
    Label_Image_Title["image"]=PhotoImage_B1F_Title
    Label_Image_Title.place(x=300,y=150,anchor="center")


    #Label(텍스트) 정보 변경 및 place
    Label_Text_Title["text"]="""
    1~6번까지 중 현재 사용자의 위치와 가장 가까운 위치와 가고 싶은 놀이기구를 입력하세요\n
    예)와일드 윙,드림보트\n
    (1.와일드 윙,2.와일드 정글,3.와일드 밸리)\n(4.4D 슈팅 씨어터,5.드림보트,6.드래곤 트레인)\n
    예시와 똑같은 형식으로 입력해주세요(띄어쓰기 주의!).
    """
    Label_Text_Title.place(x=300,y=350,anchor="center")


    #Entry place
    Enter.place(x=300,y=450,anchor="center")


    #Button place
    Btn_Check.place(x=300,y=500,anchor="center")
    Btn_Return.place(x=300,y=550,anchor="center")
    

    #Mainmenu 버튼 지우기
    Btn_Time_Enter.place_forget()
    Btn_B1_F.place_forget()
    Btn_1_F.place_forget()
    Btn_MagicIsland_F.place_forget()


    
    
def _1_F():
        
    if congestion==0:#날짜/시간을 입력하지 않으면
        messagebox.showinfo("warning","날짜/시간을 입력하세요!")
        return#함수 종료
    #Label(이미지) 정보 변경 및 place
    Label_Image_Title["image"]=PhotoImage_1F_Title
    Label_Image_Title.place(x=300,y=150,anchor="center")


    #Label(텍스트) 정보 변경 및 place
    Label_Text_Title["text"]="""
    1~6번까지 중 현재 사용자의 위치와 가장 가까운 위치와 가고 싶은 놀이기구를 입력하세요\n
    예)신밧드의 모험,회전목마\n
    (1.신밧드의 모험,2.스페인 해적선,3.후룸라이드)\n(4.거울미로,5.거울벤쳐,6.회전목마)\n
    예시와 똑같은 형식으로 입력해주세요(띄어쓰기 주의!).
    """
    Label_Text_Title.place(x=300,y=350,anchor="center")


    #Entry place
    Enter.place(x=300,y=450,anchor="center")


    #Button place
    Btn_Check.place(x=300,y=500,anchor="center")
    Btn_Return.place(x=300,y=550,anchor="center")
    

    #Mainmenu 버튼 지우기
    Btn_Time_Enter.place_forget()
    Btn_B1_F.place_forget()
    Btn_1_F.place_forget()
    Btn_MagicIsland_F.place_forget()


    

def MagicIsland_F():
    return 0

def Return_Mainmenu():


    #Label(이미지) 정보 변경 및 place
    Label_Image_Title["image"]=PhotoImage_Title
    Label_Image_Title.place(x=150,y=300,anchor="center")
    
    #Button place
    Btn_Time_Enter.place(x=450,y=40,anchor="center")
    Btn_B1_F.place(x=450,y=100,anchor="center")
    Btn_1_F.place(x=450,y=300,anchor="center")
    Btn_MagicIsland_F.place(x=450,y=500,anchor="center")
    
    #이전 라벨,버튼,엔트리 지우기(지하1층,1층,매직아일랜드)
    Label_Text_Title.place_forget()
    Enter.place_forget()
    Btn_Check.place_forget()
    Btn_Return.place_forget()

    #이전 라벨,버튼,엔트리 지우기(날짜/시간 정보 입력)
    Time_Enter.place_forget()
    Btn_Check_Time.place_forget()
    

def Get_Enter():

    global cnt
    str_get=Enter.get()#Enter Entry에서 문자열 받아오기

    trigger=False#,를 기준으로 문자열을 문자열1,2로 분리하기 위한 trigger
    
    str1=[]#문자열1을 받기위한 string 리스트
    str2=[]#문자열2를 받기위한 string 리스트
    for i in str_get:#문자열1,문자열2 입력 받았을 때 두 문자열 분리하는 for 문

        if i==',':
            trigger=True
            continue#','문자는 안 받으려고
            
        if trigger==False:
            str1.append(i)
        else:
            str2.append(i)
            

            
    str1=''.join(str1)#문자 리스트를 문자열로 바꿈
    str2=''.join(str2)#문자 리스트를 문자열로 바꿈
    
    if str1 in Attraction.keys() and str2 in Attraction.keys():#놀이기구 딕셔너리에서 입력받은 두 문자열이 key값으로 있는지 조건 확
        Search([],deepcopy(Attraction),str1,str2,Attraction[str1][1][0][1])#길 찾기 알고리즘 시행 #4번째 Floor 인자 일반화를 위해 [str1][1][0][1]
                                                                           #길 찾기를 여러번 시행하기 위해, Attraction딕셔너리를 깊은 복사하여 인자로 넘겨줌

        

        messagebox.showinfo("알림","{0}개의 경로가 발견됐습니다.\n{1}의 대기시간은 {2}분입니다.".format(cnt-1,str2,Attraction[str2][2]+(15*(5-congestion))))#cnt-1마지막에 함수를 탈출하면 한번 더 count를 했기 때문에
                                                                                                                                #15*(5-혼잡도),혼잡도로 인해 발생하는
                                                                                                                                #추가 대기 시간 계산

        cnt=1#count값 초기화
        
    else:
        messagebox.showinfo("error","다시 입력하세요!")#잘못 입력해서 다시 입력하세요 메세지 박스 print

def Get_Time():
    
    global month
    global week
    global day
    global congestion
    
    str_get=Time_Enter.get()#Time_Enter Entry에서 문자열 받아오기

    previous_trigger=False#','를 기준으로 문자열을 문자열 1,2,3으로 분리하기 위한 previous_trigger
    trigger=False#','를 기준으로 문자열을 문자열1,2,3으로 분리하기 위한 trigger
    
    str1=[]#문자열1을 받기위한 문자 리스트
    str2=[]#문자열2를 받기위한 문자 리스트
    str3=[]#문자열2를 받기위한 문자 리스트
    for i in str_get:#문자열1,문자열2 입력 받았을 때 두 문자열 분리하는 for 문

        if i==',':
            
            previous_trigger=trigger
            if trigger==True:
                trigger=False
            else:
                trigger=True
            
            continue#','문자는 안 받으려고
            
        if previous_trigger==False and trigger==False :
            str1.append(i)
        elif previous_trigger==False and trigger==True:
            str2.append(i)
        else:
            str3.append(i)
            

            
    str1=''.join(str1)#문자 리스트를 문자열로 바꿈
    str2=''.join(str2)#문자 리스트를 문자열로 바꿈
    str3=''.join(str3)#문자 리스트를 문자열로 바꿈
    
    
    month=str1
    week=str2
    day=str3


    #입력값에 오타가 있는지 검사
    if not(month in Month and week in Week and day in Day):
        messagebox.showinfo("error","다시 입력하세요!")
        return

    #월별 주차별 요일별 혼잡도 하드 코딩
    if month=="1월":
        if week=="1주":
            congestion=Week_Case["model3"][day]
        if week=="2주":
            congestion=Week_Case["model1"][day]
        if week=="3주":
            congestion=Week_Case["model1"][day]
        if week=="4주":
            congestion=Week_Case["model2"][day]
        if week=="5주":
            congestion=Week_Case["model2"][day]
            
    elif month=="2월":
        if week=="1주":
            congestion=Week_Case["model5"][day]
        if week=="2주":
            congestion=Week_Case["model3"][day]
        if week=="3주":
            congestion=Week_Case["model1"][day]
        if week=="4주":
            congestion=Week_Case["model4"][day]
        if week=="5주":
            congestion=Week_Case["model4"][day]

    elif month=="3월":
        if week=="1주":
            congestion=Week_Case["model5"][day]
        if week=="2주":
            congestion=Week_Case["model5"][day]
        if week=="3주":
            congestion=Week_Case["model2"][day]
        if week=="4주":
            congestion=Week_Case["model2"][day]
        if week=="5주":
            congestion=Week_Case["model2"][day]

    elif month=="4월":
        if week=="1주":
            congestion=Week_Case["model5"][day]
        if week=="2주":
            congestion=Week_Case["model5"][day]
        if week=="3주":
            congestion=Week_Case["model2"][day]
        if week=="4주":
            congestion=Week_Case["model2"][day]
        if week=="5주":
            congestion=Week_Case["model1"][day]
  
    elif month=="5월":
        if week=="1주":
            congestion=Week_Case["model1"][day]
        if week=="2주":
            congestion=Week_Case["model6"][day]
        if week=="3주":
            congestion=Week_Case["model6"][day]
        if week=="4주":
            congestion=Week_Case["model6"][day]
        if week=="5주":
            congestion=Week_Case["model2"][day]

    elif month=="6월":
        if week=="1주":
            congestion=Week_Case["model2"][day]
        if week=="2주":
            congestion=Week_Case["model5"][day]
        if week=="3주":
            congestion=Week_Case["model5"][day]
        if week=="4주":
            congestion=Week_Case["model2"][day]
        if week=="5주":
            congestion=Week_Case["model2"][day]

    elif month=="7월":
        if week=="1주":
            congestion=Week_Case["model5"][day]
        if week=="2주":
            congestion=Week_Case["model2"][day]
        if week=="3주":
            congestion=Week_Case["model6"][day]
        if week=="4주":
            congestion=Week_Case["model1"][day]
        if week=="5주":
            congestion=Week_Case["model3"][day]


    elif month=="8월":
        if week=="1주":
            congestion=Week_Case["model4"][day]
        if week=="2주":
            congestion=Week_Case["model4"][day]
        if week=="3주":
            congestion=Week_Case["model1"][day]
        if week=="4주":
            congestion=Week_Case["model2"][day]
        if week=="5주":
            congestion=Week_Case["model2"][day]


    elif month=="9월":
        if week=="1주":
            congestion=Week_Case["model6"][day]
        if week=="2주":
            congestion=Week_Case["model6"][day]
        if week=="3주":
            congestion=Week_Case["model5"][day]
        if week=="4주":
            congestion=Week_Case["model5"][day]
        if week=="5주":
            congestion=Week_Case["model1"][day]

    elif month=="10월":
        if week=="1주":
            congestion=Week_Case["model6"][day]
        if week=="2주":
            congestion=Week_Case["model3"][day]
        if week=="3주":
            congestion=Week_Case["model6"][day]
        if week=="4주":
            congestion=Week_Case["model6"][day]
        if week=="5주":
            congestion=Week_Case["model6"][day]


    elif month=="11월":
        if week=="1주":
            congestion=Week_Case["model5"][day]
        if week=="2주":
            congestion=Week_Case["model5"][day]
        if week=="3주":
            congestion=Week_Case["model5"][day]
        if week=="4주":
            congestion=Week_Case["model5"][day]
        if week=="5주":
            congestion=Week_Case["model6"][day]


    elif month=="12월":
        if week=="1주":
            congestion=Week_Case["model6"][day]
        if week=="2주":
            congestion=Week_Case["model5"][day]
        if week=="3주":
            congestion=Week_Case["model2"][day]
        if week=="4주":
            congestion=Week_Case["model3"][day]
        if week=="5주":
            congestion=Week_Case["model3"][day]


    
    messagebox.showinfo("알림","입력완료!\n혼잡도 등급:{0}".format(congestion))
    
    
    
#main

cnt=1;#count변수 global로 사용

month="1월"#month변수 global로 사용,초기값=1월
week="1주"#week변수 global로 사용,초기값=1주
day="월요일"#day변수 global로 사용,초기값=월요일
congestion=0#congestion변수 global로 사용,초기값=0

#날짜/시간 입력 값에 오타를 확인하기 위한 리스트들
Month=["1월","2월","3월","4월","5월","6월","7월","8월","9월","10월","11월","12월"]
Week=["1주","2주","3주","4주","5주"]
Day=["월요일","화요일","수요일","목요일","금요일","토요일","일요일"]


Week_Case={
    "model1":{'월요일':4, '화요일':4, '수요일':3, '목요일':3, '금요일':3, '토요일':2, '일요일':2},
    "model2":{'월요일':5, '화요일':5, '수요일':4, '목요일':4, '금요일':3, '토요일':2, '일요일':2},
    "model3":{'월요일':3, '화요일':3, '수요일':3, '목요일':3, '금요일':3, '토요일':2, '일요일':2},
    "model4":{'월요일':3, '화요일':3, '수요일':3, '목요일':3, '금요일':2, '토요일':1, '일요일':1},
    "model5":{'월요일':5, '화요일':5, '수요일':5, '목요일':5, '금요일':4, '토요일':3, '일요일':3},
    "model6":{'월요일':4, '화요일':4, '수요일':4, '목요일':4, '금요일':3, '토요일':2, '일요일':2}
    
}#롯데월드 주차별 혼잡도 케이스를 6개의 모델로 모델링 한 것, 딕셔너리, 숫자가 "작을수록" 더 혼잡함!



Floor={#층 딕셔너리 선언
    "B1F":-1,
    "1F":1,
    "MagicIsland":2
}

Attraction={#놀이기구 딕셔너리 선언
    "와일드 윙":[
        10000,
        [
            ["와일드 정글",Floor["B1F"],5]
        ],
        60
        
    ],
    "와일드 정글":[
        10000,
        [
            ["와일드 윙",Floor["B1F"],5],#"놀이기구":[시작점에서 여기까지 오는데 걸리는 시간,[["인접 놀이기구1",층,가는데 걸리는 시간],["인접 놀이기구2",층,가는데 걸리는 시간]],놀이기구 대기시]
            ["와일드 밸리",Floor["B1F"],1],
            ["4D 슈팅 씨어터",Floor["B1F"],2]
        ],
        70
    ],
    "와일드 밸리":[
        10000,
        [
            ["와일드 정글",Floor["B1F"],1],
            ["4D 슈팅 씨어터",Floor["B1F"],2],
            ["드림보트",Floor["B1F"],10]
        ],
        65
    ],
    "4D 슈팅 씨어터":[
        10000,
        [
            ["와일드 정글",Floor["B1F"],2],
            ["와일드 밸리",Floor["B1F"],2],
            ["드림보트",Floor["B1F"],10],
            ["드래곤 트레인",Floor["B1F"],20]
        ],
        75
    ],
    "드림보트":[
        10000,
        [
            ["와일드 밸리",Floor["B1F"],10],
            ["4D 슈팅 씨어터",Floor["B1F"],10],
            ["드래곤 트레인",Floor["B1F"],5]
        ],
        60
    ],
    "드래곤 트레인":[
        10000,
        [
            ["4D 슈팅 씨어터",Floor["B1F"],20],
            ["드림보트",Floor["B1F"],5]
        ],
        55
    ],
    "신밧드의 모험":[
        10000,
        [
            ["스페인 해적선",Floor["1F"],1],
            ["회전목마",Floor["1F"],20],
            ["거울미로",Floor["1F"],10],
            ["후룸라이드",Floor["1F"],3]
        ],
        80
    ],
    "스페인 해적선":[
        10000,
        [
            ["신밧드의 모험",Floor["1F"],1],
            ["후룸라이드",Floor["1F"],2]
        ],
        70
    ],
    "후룸라이드":[
        10000,
        [
            ["신밧드의 모험",Floor["1F"],3],
            ["스페인 해적선",Floor["1F"],1],
            ["거울미로",Floor["1F"],7]
        ],
        75
    ],
    "거울미로":[
        10000,
        [
            ["신밧드의 모험",Floor["1F"],10],
            ["후룸라이드",Floor["1F"],7],
            ["회전목마",Floor["1F"],10],
            ["거울벤쳐",Floor["1F"],11]
        ],
        60
    ],
    "거울벤쳐":[
        10000,
        [
            ["회전목마",Floor["1F"],1],
            ["거울미로",Floor["1F"],11]
        ],
        60
    ],
    "회전목마":[
        10000,
        [
            ["신밧드의 모험",Floor["1F"],20],
            ["거울미로",Floor["1F"],10],
            ["거울벤쳐",Floor["1F"],1],
        ],
        55
    ]
    
}



window=Tk()
window.title("롯데월드 길찾기 프로그램")
window.geometry("600x600")#가로 세로 600픽셀


#PhotoImage 선언부
PhotoImage_Title=PhotoImage(file="lotteworld_title.png")
PhotoImage_B1F_Title=PhotoImage(file="lotteworld_b1f.png")
PhotoImage_1F_Title=PhotoImage(file="lotteworld_1f.png")


#Label(이미지) 선언부
Label_Image_Title=Label(window,image=PhotoImage_Title)

#Label(텍스트) 선언
Label_Text_Title=Label(window,text="",font=("Courier New",10))

#Button 선언부
Btn_Time_Enter=Button(window,text="날짜/시간 정보입력",font=("맑은 고딕",20),command=Enter_Time)
Btn_B1_F=Button(window,text="B1_F(지하1층)",font=("Courier New",20),command=B1_F)
Btn_1_F=Button(window,text="1_F(1층)",font=("Courier New",20),command=_1_F)
Btn_MagicIsland_F=Button(window,text="매직 아일랜드",font=("Courier New",20),command=MagicIsland_F)
Btn_Return=Button(window,text="메인메뉴로",font=("Courier New",20),command=Return_Mainmenu)
Btn_Check=Button(window,text="입력 완료",font=("Courier New",10),command=Get_Enter)
Btn_Check_Time=Button(window,text="입력 완료",font=("Courier New",10),command=Get_Time)#날짜/시간 입력 확인 버튼

#Entry 선언부
Time_Enter=Entry(window,font=("Courier New",20))
Enter=Entry(window,font=("Courier New",20))



#Label(이미지) place
Label_Image_Title.place(x=150,y=300,anchor="center")

#Button place
Btn_Time_Enter.place(x=450,y=40,anchor="center")
Btn_B1_F.place(x=450,y=100,anchor="center")
Btn_1_F.place(x=450,y=300,anchor="center")
Btn_MagicIsland_F.place(x=450,y=500,anchor="center")



window.mainloop()

