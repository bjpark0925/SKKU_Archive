from tkinter import * # 
w=Tk() #

# 함수정의
def view1():
    label1.config(image=photo2) #
    #label1['image']=photo2
    
def view2():
    label1.config(image=photo3)
    #label1['image']=photo3
    

w.title('이미지 넣기') #
photo1=PhotoImage(file='pooh.png') #
photo2=PhotoImage(file='tigger.png')
photo3=PhotoImage(file='piglet.png')

label1=Label(w,image=photo1) #
btn1=Button(w,text='tigger',font=('',20), command=view1) #
btn2=Button(w,text='piglet',font=('',20), command=view2)

label1.pack() #
btn1.pack()
btn2.pack()

w.mainloop() #

