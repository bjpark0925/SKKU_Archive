from tkinter import *
w=Tk()

w.title('윈도우 창 연습')
w.geometry('300x100')

label1=Label(w,text='Python을',font=('',30))
label2=Label(w,text='열심히',fg='blue')
label3=Label(w,text='공부중입니다.',bg='pink')

label1.pack()
label2.pack()
label3.pack()

