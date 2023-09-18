#실습6-1
#20191031 1138

from tkinter import * # tkinter 모듈 불러오기
w=Tk() #윈도우 생성

# 함수정의
def view1():
    label1.config(image=photo2) #위젯 생성
    #label1['image']=photo2
    
def view2():
    label1.config(image=photo3)
    #label1['image']=photo3
    

w.title('이미지 넣기') #문자 생성
photo1=PhotoImage(file='pooh.png') #그림 생성(파일 불러오기)
photo2=PhotoImage(file='tigger.png')
photo3=PhotoImage(file='piglet.png')

label1=Label(w,image=photo1) #label1에 사진 띄우기
btn1=Button(w,text='tigger',font=('',20), command=view1) #텍스트와 글자 크기를 정한 버튼 생성(버튼 클릭 시 view1 또는 view2함수 발생)
btn2=Button(w,text='piglet',font=('',20), command=view2)

label1.pack() #위젯을 추가된 순서에 따라 수직으로 배치
btn1.pack()
btn2.pack()

w.mainloop() #이벤트로부터 오는 메시지를 받고 전달

