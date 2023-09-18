from tkinter import *
w=Tk()

w.title('윈도우 창 연습')
w.geometry('300x200')

L1=Label(w,text='Python을',font=('',30))
L2=Label(w,text='열심히',fg='blue')
L3=Label(w,text='공부중입니다.',bg='blue')

L1.pack()
L2.pack()
L3.pack()
