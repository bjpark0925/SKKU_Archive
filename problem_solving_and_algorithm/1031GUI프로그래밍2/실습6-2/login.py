#실습 6-2
#20191031 1145

from tkinter import *
from tkinter import messagebox #tkinter의 messagebox 모듈 불러오기

# 함수정의

def show():
    if sid.get()=='skku': #조건문(sid에 skku 입력 시)
        if spw.get()=='1234': #조건문(spw에 1234 입력 시)
            messagebox.showinfo('success', '로그인 성공') #messagebox 생
        else:
            messagebox.showinfo('error', 'password error')
    else:
        messagebox.showinfo('error', 'id error')
    
# main
w=Tk()
w.title('로그인 화면')
w.geometry('400x300')

photo=PhotoImage(file='icam.png')
output=Label(w,image=photo)
lbl1=Label(w,text='id',font=('',20))
sid=Entry(w,font=('',20)) #id 입력용 한줄 텍스트 박스 생성

lbl2=Label(w,text='pw',font=('',20))
spw=Entry(w,show='●',font=('',20)) #pw 입력용 한줄 텍스트 박스 생성
btn1=Button(w,text='로그인',font=('',20),bg='#ECE0F8',command=show) #로그인 버튼 생성

output.pack(pady=5) #위젯을 추가된 순서에 따라 수직으로 배치(맨 위로부터 y방향으로 5만큼 띄우기)
lbl1.pack(pady=5)
sid.pack(pady=5)
lbl2.pack(pady=5)
spw.pack(pady=5)
btn1.pack(pady=5)
w.mainloop()
