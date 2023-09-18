from tkinter import *
w=Tk()

w.title('이미지 넣기')
photo=PhotoImage(file='pooh.png')
label1=Label(w,image=photo)

label1.pack()

w.mainloop()
