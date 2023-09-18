from tkinter import *
from tkinter.messagebox import * #
from tkinter.font import *

# 함수정의

def show():
    if sid.get()=='skku': #
        if spw.get()=='1234': #
            showinfo('success','로그인 성공') #
        else:
            showinfo('error','password error')
    else:
        showinfo('error','id error') 
# main
w=Tk()
w.title('로그인 화면')
w.geometry('400x400')
f=Font(family='맑은 고딕',size=20) # 폰트지정
photo=PhotoImage(file='icam.png')
output=Label(w,image=photo)
lbl1=Label(w,text='id',font=f)
sid=Entry(w,font=f) #

lbl2=Label(w,text='pw',font=f)
spw=Entry(w,show='●',font=f) #
btn1=Button(w,text='로그인',font=f,bg='#ECE0F8',command=show) #

output.pack(pady=5) #
lbl1.pack(pady=5)
sid.pack(pady=5)
lbl2.pack(pady=5)
spw.pack(pady=5)
btn1.pack(pady=5)
w.mainloop()
