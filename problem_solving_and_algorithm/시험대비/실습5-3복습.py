from tkinter import *

w=Tk()
w.title('곰돌이 푸, 행복한 일은 매일 있어')
photo=PhotoImage(file='pooh.png')
label1=Label(w,image=photo)

msg='''
곰돌이 푸, 행복한 일은 매일 있어
매일 즐거운 일이 생기지 않으면
인생이 재미없다고 생각하는 사람들이 있습니다.
하지만 진정한 행복을 느끼는 일은
한번이어도 충분히 의미 있고 재미있는 인생입니다.
행복을 찾는 방법은
자신에게 그 행복한 한번이 무엇인지 찾아가는 과정이에요.
'''
label2=Label(w,text=msg)

label1.pack(side=LEFT)
label2.pack(side=RIGHT)
w.mainloop
