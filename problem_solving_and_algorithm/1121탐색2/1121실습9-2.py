#실습 9-2
#20191121 1109


from tkinter import *
from tkinter import messagebox

# 이진탐색 함수 정의
def binarysearch():
    global cnt
    low = 0
    high = len(a) - 1
    key=int(entry.get()) # 엔트리에서 값을 얻어옴
    # 추가코드 작성
    while low<=high:
        mid=(low+high)//2
        cnt+=1
        if key<a[mid]:
            high=mid-1
        elif key>a[mid]:
            low=mid+1
        else:
            messagebox.showinfo('result',str(cnt)+'번만에 success')
            return
    messagebox.showinfo('result','fail')

def last():
    msg='''
    문알수업에
    열정적으로 참여하신
    여러분
    수고하셨습니다.
    이제 파이썬 실습은 마지막입니다.
    끝날때까지 끝난 건 아니니깐.
    남은 러닝페어와 기말고사도 화이팅입니다.
    수고하신 실습조교님께도.뜨거운 박수를..
    러닝페어 동료들에게도 따뜻한 말 한마디를 전해보세요..
    '''
    messagebox.showinfo('greeting',msg)
    
# main
w=Tk()
a=[6, 13, 14, 25, 33, 43, 51, 53]
cnt=0
w.title('Binary Search')
label=Label(w,font=('',30),text=a)
entry=Entry(w,font=('',30),bg='yellow',fg='red')
btn=Button(w,text='이진검색',font=('',30),command=binarysearch)
end=Button(w,text='last',font=('',30),command=last)
label.pack()
entry.pack()
btn.pack()
end.pack()
w.mainloop()
