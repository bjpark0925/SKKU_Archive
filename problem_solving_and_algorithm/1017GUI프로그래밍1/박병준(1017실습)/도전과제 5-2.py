# 20191017 1112

from tkinter import *
w=Tk()

w.title('윈도우 창 연습')
w.geometry('510x300')

label1=Label(w,text='Python을',font=('',20))
label2=Label(w,text='열심히',fg='red')
label3=Label(w,text='공부중입니다.',bg='green')

label4=Label(w,text='C언어도',font=('',45))
label5=Label(w,text='꾸준히',font=('',20),fg='yellow')
label6=Label(w,text='공부하고 있어요.',fg='red',bg='green')

label1.pack()
label2.pack()
label3.pack()
label4.pack()
label5.pack()
label6.pack()
