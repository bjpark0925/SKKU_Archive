from tkinter import *
from tkinter import messagebox #

# 함수정의

def show():
    if sid.get()=='skku': #
        if spw.get()=='1234': #
            messagebox.showinfo('success','로그인 성공') #
        else:
            messagebox.showinfo('error','password error')
    else:
        messagebox.showinfo('error','id error') 
# main
w=Tk()
w.title('로그인 화면')
w.geometry('400x300')

photo=PhotoImage(file='icam.png')
output=Label(w,image=photo)
lbl1=Label(w,text='id',font=('',20))
sid=Entry(w,font=('',20)) #

lbl2=Label(w,text='pw',font=('',20))
spw=Entry(w,show='●',font=('',20)) #
btn1=Button(w,text='로그인',font=('',20),bg='#ECE0F8',command=show) #

output.pack(pady=5) #
lbl1.pack(pady=5)
sid.pack(pady=5)
lbl2.pack(pady=5)
spw.pack(pady=5)
btn1.pack(pady=5)
w.mainloop()
