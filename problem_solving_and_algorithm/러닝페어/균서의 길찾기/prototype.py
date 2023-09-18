#prototype
from tkinter import *
from tkinter import messagebox

def Search(dir,start,end,floor,time=0):#길 찾기 알고리즘, 다익스트라 알고리즘 응용
    if Attraction[start][0]>time:
        Attraction[start][0]=time
        dir.append(start)
    else:
        return "취소"

    if start==end:
        messagebox.showinfo("test","{0}분 소요\n{1}".format(time,dir))
        return "도착"

    for i in Attraction[start][1]:
        Search(list(dir),i[0],end,i[1],i[2]+time)
        

def B1_F():#지하 1층 관장 함수

    #Label(이미지) 정보 변경 및 place
    Label_Image_Title["image"]=PhotoImage_B1F_Title
    Label_Image_Title.place(x=300,y=150,anchor="center")


    #Label(텍스트) 정보 변경 및 place
    Label_Text_Title["text"]="""
    1~6번까지 중 현재 사용자의 위치와 가장 가까운 위치와 가고 싶은 놀이기구를 입력하세요\n
    예)WildWing,WildValley\n
    (1.WildWing,2.WildJungle,3.WildValley)\n(4.4DShootingTheater,5.DreamBoat,6.DragonTrain)
    """
    Label_Text_Title.place(x=300,y=350,anchor="center")


    #Entry place
    Enter.place(x=300,y=450,anchor="center")


    #Button place
    Btn_Check.place(x=300,y=500,anchor="center")
    Btn_Return.place(x=300,y=550,anchor="center")
    

    #Mainmenu 버튼 지우기
    Btn_B1_F.place_forget()
    Btn_1_F.place_forget()
    Btn_MagicIsland_F.place_forget()


    
    
def _1_F():
    return 0

def MagicIsland_F():
    return 0

def Return_Mainmenu():
    Label_Image_Title["image"]=PhotoImage_Title
    Label_Image_Title.place(x=150,y=300,anchor="center")

    Btn_B1_F.place(x=450,y=100,anchor="center")
    Btn_1_F.place(x=450,y=300,anchor="center")
    Btn_MagicIsland_F.place(x=450,y=500,anchor="center")

    Label_Text_Title.place_forget()
    Enter.place_forget()
    Btn_Check.place_forget()
    Btn_Return.place_forget()


def Get_Enter():
    
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
    
    if str1 in Attraction.keys() and str2 in Attraction.keys():
        Search([],str1,str2,Floor["B1F"])#길 찾기 알고리즘 시행
    else:
        messagebox.showinfo("error","다시 입력하세요!")#잘못 입력해서 다시 입력하세요 메세지 박스 print
    

    
    
    
    
#main
            
Floor={#층 딕셔너리 선언
    "B1F":-1,
    "1F":1,
    "MagicIsland":2
}

Attraction={#놀이기구 딕셔너리 선언
    "WildWing":[
        10000,
        [
            ["WildJungle",Floor["B1F"],5]
        ]
    ],
    "WildJungle":[
        10000,
        [
            ["WildWing",Floor["B1F"],5],
            ["WildValley",Floor["B1F"],1],
            ["4DShootingTheater",Floor["B1F"],2]
        ]
    ],
    "WildValley":[
        10000,
        [
            ["WildJungle",Floor["B1F"],1],
            ["4DShootingTheater",Floor["B1F"],2],
            ["DreamBoat",Floor["B1F"],10]
        ]
    ],
    "4DShootingTheater":[
        10000,
        [
            ["WildJungle",Floor["B1F"],2],
            ["WildValley",Floor["B1F"],2],
            ["DreamBoat",Floor["B1F"],10],
            ["DragonTrain",Floor["B1F"],20]
        ]
    ],
    "DreamBoat":[
        10000,
        [
            ["WildValley",Floor["B1F"],10],
            ["4DShootingTheater",Floor["B1F"],10],
            ["DragonTrain",Floor["B1F"],5]
        ]
    ],
    "DragonTrain":[
        10000,
        [
            ["4DShootingTheater",Floor["B1F"],20],
            ["DreamBoat",Floor["B1F"],5]
        ]
    ]
    
}



window=Tk()
window.title("롯데월드 길찾기 프로그램")
window.geometry("600x600")#가로 세로 600픽셀


#PhotoImage 선언부
PhotoImage_Title=PhotoImage(file="lotteworld_title.png")
PhotoImage_B1F_Title=PhotoImage(file="lotteworld_b1f.png")


#Label 선언부
Label_Image_Title=Label(window,image=PhotoImage_Title)
Label_Text_Title=Label(window,text="",font=("Courier New",10))

#Button 선언부
Btn_B1_F=Button(window,text="B1_F(지하1층)",font=("Courier New",20),command=B1_F)
Btn_1_F=Button(window,text="1_F(1층)",font=("Courier New",20),command=_1_F)
Btn_MagicIsland_F=Button(window,text="매직 아일랜드",font=("Courier New",20),command=MagicIsland_F)
Btn_Return=Button(window,text="메인메뉴로",font=("Courier New",20),command=Return_Mainmenu)
Btn_Check=Button(window,text="입력 완료",font=("Courier New",10),command=Get_Enter)

#Entry 선언부
Enter=Entry(window,font=("Courier New",20))


#Label(이미지) place
Label_Image_Title.place(x=150,y=300,anchor="center")

#Button place
Btn_B1_F.place(x=450,y=100,anchor="center")
Btn_1_F.place(x=450,y=300,anchor="center")
Btn_MagicIsland_F.place(x=450,y=500,anchor="center")



window.mainloop()

